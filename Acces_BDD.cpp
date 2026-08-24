#include "Acces_BDD.h"

Acces_BDD::Acces_BDD(string dsn)
{
    n_session=NULL;
    n_connect_ok=true;
    // on va utiliser ODBC
    ODBC::Connector::registerConnector();
    try
    {
        n_session= new Session("ODBC", "DSN="+dsn);
        cout<<"connexion succès"<<endl;
    }
    catch (ConnectionFailedException& ce)
    {
        n_last_error= ce.displayText();
        cout<<"connexion échoué"<<endl;
        n_connect_ok=false;
    }
}

bool Acces_BDD::Select(string requete){
    bool retour=true;

    if (n_session != NULL)
    {
        // on essaye de faire un select
        try
        {
            Statement select(*n_session);
            select << requete;
            RecordSet rs(select);
            // on récupère les données
//            while (!select.done())
//            {
              select.execute();
              bool more = rs.moveFirst();
              n_last_result.clear();
              n_nombreColonnesResultat=rs.columnCount();
              while (more)
              {
                for (std::size_t col = 0; col < n_nombreColonnesResultat; ++col)
                {
                    n_last_result.push_back(rs[col].convert<string>());
                }
                more = rs.moveNext();
              }
 //           }
        }            
        catch (ODBC::StatementException& se)
        {
            n_last_error= se.toString();
            retour=false;
        }
    }
    
    return retour;
}

bool Acces_BDD::Insert(string requete){
    bool retour=true;
    if (n_session != NULL)
    {
        // on essaye de faire un select
        try
        {
            Statement insert(*n_session);
            insert << requete;
            RecordSet rs(insert);
        }
        catch (ODBC::StatementException& se)
        {
            n_last_error= se.toString();
            retour=false;
        }
    }
    return retour;
}
Acces_BDD::~Acces_BDD()
{
}
