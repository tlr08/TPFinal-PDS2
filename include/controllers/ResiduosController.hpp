#ifndef RESIDUOS_CONTROLLER_H
#define RESIDUOS_CONTROLLER_H
#include "stdafx.hpp"
#include "DefaultController.hpp"
#include "Residuo.hpp"

using namespace std;
class ResiduosController : public DefaultController<Residuo>{
    public:
        void run();
        using DefaultController<Residuo>::DefaultController;
    private:
        int get_view();
        void create();
        void list_all();
        void update();
        void remove();
        void show(); 
        int get_next_id();
};

#endif