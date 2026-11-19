#include "Thread_Puissance.h"
#include <wx/utils.h>
#include <iostream>

Thread_Puissance::Thread_Puissance(): wxThread(wxTHREAD_JOINABLE)
{
    fin_demandee=false;
}

Thread_Puissance::~Thread_Puissance()
{
}

void Thread_Puissance::OnExit()
{
    std::cout<<"\033[31m" //ROUGE
             <<"  Thread puissance: OnExit appelé"<<std::endl
             << "\033[0m"; //RESET
}

wxThread::ExitCode Thread_Puissance::Entry()
{
    while (!fin_demandee && !TestDestroy())
    {
        // TODO
        //récupérer la puissance demandée (0-100 %), la convertir en PWM
        //et l'envoyer au GrovePi :
        //wxMutexLocker verrou(GroveMutex());
        //GrovePi::analogWrite(PIN_PUISSANCE, valeur); valeur 0..255
        wxMilliSleep(500);
    }
    return (ExitCode)0;
}
