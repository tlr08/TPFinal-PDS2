#ifndef ANGENDAMENTO_CONTROLLER_H
#define AGENDAMENTO_CONTROLLER_H
#include "stdafx.hpp"
#include "DefaultController.hpp"
#include "Agendamento.hpp"

using namespace std;
class AgendamentoController : public DefaultController<Agendamento>{
    public:
        void run();
        using DefaultController<Agendamento>::DefaultController;
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