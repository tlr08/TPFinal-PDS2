#ifndef MAIN_CONTROLLER_H
#define MAIN_CONTROLLER_H
#include "stdafx.hpp"
#include "ResiduosController.hpp"
#include "UsuarioController.hpp"
#include "PontoColetaController.hpp"
#include "AgendamentoController.hpp"

using namespace std;

class MainController{
    public:
        MainController(DbHelper* helper);
        ~MainController(){}
        void run();
    private:
        int showView();
        DbHelper* helper;
        ResiduosController* residuos;
        UsuarioController*  usuario;
        PontoColetaController* local;
        AgendamentoController* agendamento;
};

#endif