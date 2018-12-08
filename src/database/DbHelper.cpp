#include "DbHelper.hpp"
#include <list>

DbHelper::~DbHelper(){
    this->closeConnection();
}

sqlite3* DbHelper::getDatabase(){
    return this->dbFile;
}

std::string DbHelper::getDbName(){
    return this->dbName;
}

DbHelper::DbHelper(std::string dbName){
    this->dbName = dbName;
    this->dbFile = nullptr;
    this->startConnection();
}

bool DbHelper::closeConnection(){
    if (this->dbFile != nullptr){
        return sqlite3_close(this->dbFile);
    }
    return false;
}

bool DbHelper:: startConnection(){
    if (this->dbName.empty()){
        return false;   
    }
    return !sqlite3_open(this->dbName.c_str(), &this->dbFile);
}




bool DbHelper::runSql(std::string sql){
    char* messaggeError;
    int rc = 0;
    rc = sqlite3_exec(this->dbFile, sql.c_str(), nullptr, 0,&messaggeError);

    if (rc != SQLITE_OK) { 
        std::cerr << "SQL ERROR" << std::endl; 
        std::cerr << messaggeError << std::endl;
        sqlite3_free(messaggeError);
        return false; 
    }
    return true;
}

void DbHelper::down(){
    std::string sql ="DROP TABLE IF EXISTS RESIDUO;";
    this->runSql(sql);
    sql ="DROP TABLE IF EXISTS USUARIO;";
    this->runSql(sql);
}
void DbHelper::up(){
    std::string sql = "CREATE TABLE IF NOT EXISTS RESIDUO ( ID INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, NOME TEXT NOT NULL, FORMA TEXT NOT NULL, TIPO INT NOT NULL, QUANTIDADE REAL NOT NULL, UNIDADE TEXT NOT NULL);";
    this->runSql(sql);
    sql = "CREATE TABLE IF NOT EXISTS USUARIO ( ID INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, NOME TEXT NOT NULL, NOME_USUARIO TEXT NOT NULL, ENDERECO TEXT NOT NULL, SENHA TEXT NOT NULL,CPF TEXT, CNPJ TEXT);";
    this->runSql(sql);
    sql = "CREATE TABLE IF NOT EXISTS PONTOCOLETA ( ID INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, NOME TEXT NOT NULL, ENDERECO TEXT NOT NULL, ID_USUARIO INT);";
    this->runSql(sql);
}


std::list<Row*>* DbHelper::read(const char* sql, std::list<variant*>* params){
    std::list<Row*>* rows = new std::list<Row*>();
    sqlite3_stmt *stmt;
    prepareStatementSQL(sql, params, &stmt);
    int rc = sqlite3_step(stmt);
    while (rc != SQLITE_DONE && rc != SQLITE_OK)
    {
        Row* row = new Row();
        row->fields = new std::list<Field*>();
        int colCount = sqlite3_column_count(stmt);
        for (int colIndex = 0; colIndex < colCount; colIndex++)
        {
            int type = sqlite3_column_type(stmt, colIndex);
            std::string columnName = std::string(reinterpret_cast<const char*>(sqlite3_column_name(stmt, colIndex)));
            if (type == SQLITE_INTEGER)
            {
                int valInt = sqlite3_column_int(stmt, colIndex);
                row->fields->push_back(getField(getVariant(valInt), columnName));
            }
            else if (type == SQLITE_FLOAT)
            {
                double valDouble = sqlite3_column_double(stmt, colIndex);
                row->fields->push_back(getField(getVariant(valDouble), columnName));
            }
            else if (type == SQLITE_TEXT)
            {
                std::string valChar = std::string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, colIndex)));
                row->fields->push_back(getField(getVariant(valChar), columnName));
            }
            else if (type == SQLITE_NULL)
            {
                row->fields->push_back(getField(getVariant(""), columnName));
            }
        }
        rows->push_back(row);
        rc = sqlite3_step(stmt);
    }
    rc= sqlite3_finalize(stmt);
    return rows;
}
int DbHelper::prepareStatementSQL(const char* sql, std::list<variant*>* params, sqlite3_stmt** statement){
    int rc = sqlite3_prepare_v2(dbFile, sql, strlen(sql), statement, 0);
    std::list<variant*>::iterator it;
    int paramCount =1;
    for(it = params->begin();it!= params->end(); ++it){
        std::string result = "";
        switch((*it)->variantType){
            case t_string:
                result = getString(*it);
                sqlite3_bind_text(*statement, paramCount,result.c_str(), result.length(), SQLITE_TRANSIENT);
                break;
            case t_double:
                sqlite3_bind_double(*statement, paramCount, getDouble(*it));
                break;
            case t_int:
                sqlite3_bind_int(*statement, paramCount, getInt(*it));
                break;
        }
        paramCount++;
    }

    return rc;

}

Field* getField(variant* data, std::string name){
    return new Field{
        data,
        name
    };
}