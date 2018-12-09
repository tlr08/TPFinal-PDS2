#ifndef USUARIO_CONTROLLER_H
#define USUARIO_CONTROLLER_H
#include "stdafx.hpp"
#include "DefaultController.hpp"
#include "UsuarioDAO.hpp"

using namespace std;
class UsuarioController : public DefaultController<Usuario>{
    public:
        void run();
        UsuarioController(DbHelper* helper);
        ~UsuarioController();
    private:
        UsuarioDAO* dao;
        int get_view();
        void create();
        void list_all();
        void update();
        void remove();
        void show(); 
};

#endif