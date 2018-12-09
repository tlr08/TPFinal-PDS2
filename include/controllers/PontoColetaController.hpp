#ifndef PONTOCOLETA_CONTROLLER_H
#define PONTOCOLETA_CONTROLLER_H
#include "stdafx.hpp"
#include "DefaultController.hpp"
#include "PontoColetaDAO.hpp"
#include "UsuarioDAO.hpp"

using namespace std;
class PontoColetaController : public DefaultController<PontoColeta>{
    public:
        void run();
        PontoColetaController (DbHelper* helper);
        ~PontoColetaController();
    private:
        PontoColetaDAO* dao;
        UsuarioDAO*usuarioDAO;
        int get_view();
        void create();
        void list_all();
        void update();
        void remove();
        void show(); 
};

#endif