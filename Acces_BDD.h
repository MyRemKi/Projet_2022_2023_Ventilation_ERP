#ifndef ACCES_BDD_H
#define ACCES_BDD_H
#include <string>
#include <iostream>
using namespace std;
#include<string>
using std::string;
#include <vector>
using std::vector;
#include <Poco/Data/Session.h>
#include <Poco/Data/ODBC/Connector.h>
using namespace Poco::Data::ODBC;
using namespace Poco::Data;
#include <Poco/Exception.h>
#include "Poco/Data/ODBC/ODBCException.h"
#include <Poco/Data/RecordSet.h>
//Mettre les linkers ODBC !
class Acces_BDD
{
    public:
        Acces_BDD(string dsn);
        bool Select(string requete);
        bool Insert(string requete);
        bool IsConnexionOK(){return n_connect_ok;};
        ~Acces_BDD();
    private:
        Session *n_session;
        string n_last_error;
        unsigned int n_nombreColonnesResultat;
        vector<string> n_last_result;
        bool n_connect_ok;
    

};

#endif // ACCES_BDD_H
