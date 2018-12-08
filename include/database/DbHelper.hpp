#ifndef DBHELPER_H
#define DBHELPER_H
#include "stdafx.hpp"
#include "sqlite3.h"
//Classe para auxilar no gerenciamento do Banco de Dados 
//Implementar métodos de exclusão, atualização e inserção.
//Criar métodos para carregar o banco.

typedef struct struct_field {
    variant* data;
    std::string name;
} Field;

typedef struct struct_row {
    std::list<Field*>* fields;
} Row;

Field* getField(variant* data, std::string name);

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