#include <wx/init.h>
#if wxVERSION_NUMBER < 2900
    #include <wx/string.h>
#else
    #include <wx/crt.h>
    #include <wx/cmdline.h>
#endif
#include <App.h>
int main( int argc, char** argv )
{
	// initialize wxWidgets
	wxInitializer init;
	if ( !init.IsOk() )
	{
		cerr<<"Initialisation de wxWidgets impossible"<<endl;
		return 1;
	}
    string dsn="RKBDD";
    //DECLARATION
    App MyApp;
    if ( !MyApp.Init(dsn) )
    {
        cerr<<"Initialisation du système de ventilation échouée"<<endl;
        return 1;
    MyApp.Loop();
    return 0;
}
