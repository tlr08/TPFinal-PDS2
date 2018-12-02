#ifndef DEFAULT_CONTROLLER_H
#define DEFAULT_CONTROLLER_H
#include "sqlite3.h"
#include "stdafx.hpp"


using namespace std;
template <class T>
class DefaultController {
    public:
        virtual void run() = 0;
        DefaultController(sqlite3* db){
            this->data_set = new list<T*>();
            this->db;
        }
        ~DefaultController(){
            this->db = nullptr;
            this->data_set->clear();
            delete this->data_set;
            this->data_set = nullptr;
        }
    protected:
        sqlite3* db;
        std::list<T*> *data_set;
        virtual int get_view() = 0;
        virtual void create() = 0;
        virtual void update() = 0;
        virtual void list_all() = 0;
        virtual void remove() = 0;
        virtual void show() = 0;
        virtual int get_next_id() = 0;
};

#endif