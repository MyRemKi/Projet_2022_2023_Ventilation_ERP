#include "App.h"
#include <grovepi.h>
#include <wx/utils.h>
#include <signal.h>
#include <exception>

// Mis à 1 par Ctrl+C (SIGINT) ou SIGTERM pour sortir de Loop()
static volatile sig_atomic_t g_arret_demande = 0;
static void OnSignal(int) { g_arret_demande = 1; }

App::App()
{
    m_acces_bdd=NULL;
    m_puissance=NULL;
    m_debit=NULL;
    m_id_module=ID_MODULE_VENTILATION;
}

bool App::Init(string &dsn){
    m_dsn=dsn;
    signal(SIGINT,OnSignal);
    signal(SIGTERM,OnSignal);

    cout<<"Initialisation du système de ventilation"<<endl;
    cout<<"----------------------------------------"<<endl;
    cout<<"|| Accès à la base de données ||"<<endl;
    cout<<"Connexion sur :"<<m_dsn<<endl;
    m_acces_bdd=new Acces_BDD(m_dsn);
    if(!m_acces_bdd->IsConnexionOK())
    {
        cout<<"App: base de données inaccessible"<<endl;
        return false;
    }

    cout<<"----------------------------------------"<<endl;
    cout<<"||  Convertisseur  ||"<<endl;
    cout<<"    GrovePi :"<<endl;
    try
    {
        GrovePi::initGrovePi();
        cout<<"PinMode :"<<endl;
        GrovePi::pinMode(PIN_DEBIT_AIR,GrovePi::INPUT); // lecture du débit (A0)
        GrovePi::pinMode(PIN_PUISSANCE,GrovePi::OUTPUT); // PWM puissance (D9)
    }
    catch(const std::exception &e)
    {
        cout<<"App: erreur GrovePi : "<<e.what()<<endl;
        return false;
    }

    cout<<"----------------------------------------"<<endl;
    cout<<"|| Puissance ||"<<endl;
    m_puissance= new Thread_Puissance();
    if ( m_puissance->Create() != wxTHREAD_NO_ERROR )
    {
        cout<<"App: Création thread puissance impossible!"<<endl;
        delete m_puissance;
        m_puissance=NULL;
        return false;
    }
    m_puissance->Run();
    cout<<"App: thread puissance lancé"<<endl;

    cout<<"----------------------------------------"<<endl;
    cout<<"|| Débit d'air ||"<<endl;
    m_debit= new Thread_DebitAir(m_acces_bdd,m_id_module);
    if ( m_debit->Create() != wxTHREAD_NO_ERROR )
    {
        cout<<"App: Création thread débit d'air impossible!"<<endl;
        delete m_debit;
        m_debit=NULL;
        return false;
    }
    m_debit->Run();
    cout<<"App: thread débit d'air lancé"<<endl;
    cout<<"----------------------------------------"<<endl;
    return true;
}

bool App::Loop(){
    // Plus de boucle active à 100 % CPU : on dort, les threads travaillent
    while(!g_arret_demande){
        wxMilliSleep(200);
    }
    cout<<"App: arrêt demandé"<<endl;
    Arret();
    return true;
}

void App::Arret()
{
    if(m_debit!=NULL){
        m_debit->SetFinDemandee();
        m_debit->Wait(); // thread joignable : on attend sa fin
        delete m_debit;
        m_debit=NULL;
    }
    if(m_puissance!=NULL){
        m_puissance->SetFinDemandee();
        m_puissance->Wait();
        delete m_puissance;
        m_puissance=NULL;
    }
}

App::~App()
{
    Arret(); // threads arrêtés AVANT de fermer la BDD
    delete m_acces_bdd;
    m_acces_bdd=NULL;
}
