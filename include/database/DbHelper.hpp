#ifndef DBHELPER_H
#define DBHELPER_H
#include <string>
#include <sqlite3.h>

//Classe para auxilar no gerenciamento do Banco de Dados 
//Implementar métodos de exclusão, atualização e inserção.
//Criar métodos para carregar o banco.
class DbHelper {
    sqlite3* dbFile;
    std::string dbName;

    public:
        DbHelper(std::string dbName);
        ~DbHelper();
        bool startConnection();
        bool closeConnection();
        std::string getDbName();
        sqlite3* getDatabase(   );

};

#endif