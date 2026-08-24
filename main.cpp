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
	//wxPrintf( wxT("Hello in wxWidgets World!\n\n") );
    string dsn="RKBDD";
    //DECLARATION
    App MyApp;
    MyApp.Init(dsn);
    MyApp.Loop();
    return 0;
}