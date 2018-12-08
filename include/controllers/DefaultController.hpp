#ifndef DEFAULT_CONTROLLER_H
#define DEFAULT_CONTROLLER_H
#include "sqlite3.h"
#include "stdafx.hpp"
#include "DbHelper.hpp"

using namespace std;
template <class T>
class DefaultController {
    public:
        virtual void run() = 0;
    protected:
        virtual int get_view() = 0;
        virtual void create() = 0;
        virtual void update() = 0;
        virtual void list_all() = 0;
        virtual void remove() = 0;
        virtual void show() = 0;
        virtual int get_next_id() = 0;
};

#endif