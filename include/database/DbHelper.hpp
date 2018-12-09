#ifndef DBHELPER_H
#define DBHELPER_H
#include "stdafx.hpp"
#include "sqlite3.h"
#include "Row.hpp"

//Classe para auxilar no gerenciamento do Banco de Dados 
class DbHelper {
    private:
        sqlite3* dbFile;
        std::string dbName;
        int migration;
    public:
        DbHelper(std::string dbName);
        ~DbHelper();
        bool startConnection();
        bool closeConnection();
        std::string getDbName();
        sqlite3* getDatabase();
        void up();
        void down();
        int getMigration();
        int prepareStatementSQL(const char* sql, std::list<variant*>* params, sqlite3_stmt** statement);
        std::list<Row*>* read(const char* sql, std::list<variant*>* params);

        bool runSql(std::string sql);
};

#endif