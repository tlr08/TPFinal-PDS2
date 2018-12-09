#ifndef ANGENDAMENTO_CONTROLLER_H
#define AGENDAMENTO_CONTROLLER_H
#include "stdafx.hpp"
#include "DefaultController.hpp"
#include "Agendamento.hpp"
#include "AgendamentoDAO.hpp"
#include "UsuarioDAO.hpp"
#include "ResiduosDAO.hpp"
#include "PontoColetaDAO.hpp"

using namespace std;
class AgendamentoController : public DefaultController<Agendamento>{
    public:
        void run();
        AgendamentoController(DbHelper* helper);
        ~AgendamentoController();
    private:
        AgendamentoDAO* dao;   
        UsuarioDAO* usuarioDAO;
        PontoColetaDAO* localDAO;
        ResiduosDAO* residuosDAO;
        int get_view();
        void create();
        void list_all();
        void update();
        void remove();
        void show(); 
        void residuos();
};

#endif