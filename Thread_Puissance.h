#ifndef THREAD_PUISSANCE_H
#define THREAD_PUISSANCE_H
//#include <Mosquitto.h>
#include <wx/thread.h>
#include <atomic>

class Thread_Puissance : public wxThread
{
public:
    Thread_Puissance();
    void SetFinDemandee () { fin_demandee=true; }
    virtual ExitCode Entry();
    virtual void OnExit();
    ~Thread_Puissance();
protected:
private:
    std::atomic<bool> fin_demandee;
};

#endif // THREAD_PUISSANCE_H
