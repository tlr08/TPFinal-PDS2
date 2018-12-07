#ifndef PONTOCOLETA_CONTROLLER_H
#define PONTOCOLETA_CONTROLLER_H
#include "stdafx.hpp"
#include "DefaultController.hpp"
#include "PontoColeta.hpp"

using namespace std;
class PontoColetaController : public DefaultController<PontoColeta>{
    public:
        void run();
        using DefaultController<PontoColeta>::DefaultController;
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