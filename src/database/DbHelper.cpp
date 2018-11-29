#include "DbHelper.hpp"

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
    this->dbFile = NULL;
    this->startConnection();
}

bool DbHelper::closeConnection(){
    if (this->dbFile != NULL){
        return sqlite3_close(this->dbFile);
    }
    return false;
}

bool DbHelper::startConnection(){
    
    if (this->dbName.empty){
        return false;   
    }
    return !sqlite3_open(this->dbName.c_str(), &this->dbFile);
}
