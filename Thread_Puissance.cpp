#include "Thread_Puissance.h"
#include <wx/string.h>
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
    std::cout<<"\033[31m" // ROUGE
             <<"  Thread joignable: OnExit appelé"<<std::endl
             << "\033[0m"; // RESET
}

wxThread::ExitCode Thread_Puissance::Entry()
{   
    while (!fin_demandee)
    {
        std::cout<< "\033[36m" // ROUGE
                 << "  Thread joignable: mon compteur vaut "
                 << "\033[0m"; // RESET
        Sleep(500);
    }
    // on retourne à l'application principale la valeur finale
    return (ExitCode)0;
}