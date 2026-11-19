#ifndef APP_H
#define APP_H
#include <stdio.h>
#include <iostream>
#include <unistd.h>
#include <Acces_BDD.h>
#include <Thread_Puissance.h>
#include <Thread_DebitAir.h>
#include <Config.h>
//#include <grovepi.h> inclus dans App.cpp et Thread_DebitAir.cpp
using namespace std;
//using namespace GrovePi;
class App
{
public:
    App();
    bool Init(string &dsn);
    bool Loop();
    //VOIR MODULE PWM
    //VOIR MODULE MOSQUITTO
    ~App();
private:
    void Arret(); // arrête proprement les threads
    Acces_BDD *m_acces_bdd;
    string m_dsn;
    int m_id_module; // id_module de la ventilation dans la BDD (ancien id_ventilation)
    Thread_Puissance *m_puissance;
    Thread_DebitAir *m_debit;
};

#endif // APP_H
