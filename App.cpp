#include "App.h"

App::App()
{
}
bool App::Init(string &dsn){
    bool retour=true;
    m_dsn=dsn;
    cout<<"Initialisation du système de ventilation"<<endl;
    cout<<"----------------------------------------"<<endl;
    cout<<"|| Accès à la base de données ||"<<endl;
    cout<<"Connexion sur :"<<m_dsn<<endl;
    m_acces_bdd=new Acces_BDD(m_dsn);
    retour=m_acces_bdd->IsConnexionOK();
    //VOIR ID DU VENTILATEUR
    cout<<"----------------------------------------"<<endl;
    cout<<"|| Puissance ||"<<endl;
    m_puissance= new Thread_Puissance();
	if ( m_puissance->Create() != wxTHREAD_NO_ERROR )
	{
		cout<<"App: Création thread détaché impossible!"<<endl;
		return false;
	}
	else
	{
		cout<<"App: thread détaché lancé"<<endl;
		m_puissance->Run();
	}
    cout<<"----------------------------------------"<<endl;
    cout<<"||  Convertisseur  ||"<<endl;
    cout<<"    GrovePi :"<<endl;
    //initGrovePi();
    cout<<"PinMode :"<<endl;
    //pinMode(PIN_DEBIT_AIR,OUTPUT);
    //pinMode(PIN_PUISSANCE,INPUT);
    cout<<"----------------------------------------"<<endl;
    return retour;
}

bool App::Loop(){
    bool retour=true;
    while(retour==true){
    }
    /*cout<<"App: demande de fin du thread joignable"<<endl;
    m_thread_joignable->SetFinDemandee();

    // on attend la fin du thread joignable
    cout<<"App: attente fin thread joignable"<<endl;
    long i=(long)m_thread_joignable->Wait();
    cout<<"Le thread joignable a terminé et à compté jusqu'à "<<i<<endl;
    delete m_thread_joignable;
    */
    return retour;
}

App::~App()
{
}
