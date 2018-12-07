#ifndef MAIN_CONTROLLER_H
#define MAIN_CONTROLLER_H
#include "stdafx.hpp"
#include "sqlite3.h"
#include "ResiduosController.hpp"
#include "UsuarioController.hpp"
#include "PontoColetaController.hpp"
#include "AgendamentoController.hpp"

using namespace std;

class MainController{
    public:
        MainController(sqlite3* db);
        ~MainController(){}
        void run();
    private:
        int showView();
        sqlite3* db;
        ResiduosController* residuos;
        UsuarioController*  usuario;
        PontoColetaController* local;
        AgendamentoController* agendamento;
};

#endif