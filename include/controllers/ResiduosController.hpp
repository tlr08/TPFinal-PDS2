#ifndef RESIDUOS_CONTROLLER_H
#define RESIDUOS_CONTROLLER_H
#include "stdafx.hpp"
#include "DefaultController.hpp"
#include "ResiduosDAO.hpp"

using namespace std;
class ResiduosController : public DefaultController<Residuo>{
    public:
        void run();
        ResiduosController(DbHelper* helper);
        ~ResiduosController();
    private:
        ResiduosDAO *dao;
        int get_view();
        void create();
        void list_all();
        void update();
        void remove();
        void show(); 
};

#endif