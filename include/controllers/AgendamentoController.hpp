#ifndef ANGENDAMENTO_CONTROLLER_H
#define AGENDAMENTO_CONTROLLER_H
#include "stdafx.hpp"
#include "DefaultController.hpp"
#include "Agendamento.hpp"

using namespace std;
class AgendamentoController : public DefaultController<Agendamento>{
    public:
        void run();
        AgendamentoController(DbHelper* helper);
    private:
        list<Agendamento*>* data_set;    
        DbHelper* helper;
        int get_view();
        void create();
        void list_all();
        void update();
        void remove();
        void show(); 
        int get_next_id();
        void residuos();
};

#endif