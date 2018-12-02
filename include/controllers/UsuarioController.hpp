#ifndef USUARIO_CONTROLLER_H
#define USUARIO_CONTROLLER_H
#include "stdafx.hpp"
#include "DefaultController.hpp"
#include "Usuario.hpp"
#include "PessoaFisica.hpp"
#include "PessoaJuridica.hpp"

using namespace std;
class UsuarioController : public DefaultController<Usuario>{
    public:
        void run();
        using DefaultController<Usuario>::DefaultController;
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