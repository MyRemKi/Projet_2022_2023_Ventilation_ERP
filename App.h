#ifndef APP_H
#define APP_H
#include <stdio.h>
#include <iostream>
#include <unistd.h>
#include <Acces_BDD.h>
#include <Thread_Puissance.h>
//#include <grovepi.h>
#define PIN_DEBIT_AIR 8
#define PIN_PUISSANCE 9
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
    //VOIR MODULE GROVEPI+
    ~App();
private:
    Acces_BDD *m_acces_bdd;
    string m_dsn;
    int id_ventilation=0;
    Thread_Puissance *m_puissance;

};

#endif // APP_H
