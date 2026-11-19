#include "Acces_BDD.h"

Acces_BDD::Acces_BDD(string dsn)
{
    n_session=NULL;
    n_connect_ok=true;
    n_nombreColonnesResultat=0;
    // utilisation de ODBC
    ODBC::Connector::registerConnector();
    try
    {
        n_session= new Session("ODBC", "DSN="+dsn);
        cout<<"connexion succès"<<endl;
    }
    catch (Poco::Exception& e)
    {
        n_last_error= e.displayText();
        cout<<"connexion échoué : "<<n_last_error<<endl;
        n_session=NULL;
        n_connect_ok=false;
    }
}

bool Acces_BDD::Select(string requete){
    bool retour=true;

    if (n_session != NULL)
    {
        try
        {
            Statement select(*n_session);
            select << requete;
            select.execute();// exécuter AVANT de créer le RecordSet
            RecordSet rs(select);
            n_last_result.clear();
            n_nombreColonnesResultat=rs.columnCount();
            bool more = rs.moveFirst();
            while (more)
            {
                for (std::size_t col = 0; col < n_nombreColonnesResultat; ++col)
                {
                    if (rs[col].isEmpty())
                        n_last_result.push_back("");   // valeur NULL
                    else
                        n_last_result.push_back(rs[col].convert<string>());
                }
                more = rs.moveNext();
            }
        }
        catch (Poco::Exception& e)
        {
            n_last_error= e.displayText();
            retour=false;
        }
    }
    else
    {
        n_last_error="pas de connexion à la base de données";
        retour=false;
    }

    return retour;
}

bool Acces_BDD::Insert(string requete){
    bool retour=true;
    if (n_session != NULL)
    {
        try
        {
            Statement insert(*n_session);
            insert << requete;
            insert.execute();
        }
        catch (Poco::Exception& e)
        {
            n_last_error= e.displayText();
            retour=false;
        }
    }
    else
    {
        n_last_error="pas de connexion à la base de données";
        retour=false;
    }
    return retour;
}

Acces_BDD::~Acces_BDD()
{
    delete n_session;
    n_session=NULL;
    if (n_connect_ok)
        ODBC::Connector::unregisterConnector();
}
