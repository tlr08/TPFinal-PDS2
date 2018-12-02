#ifndef USUARIO_HPP
#define USUARIO_HPP
#include "stdafx.hpp"
using namespace std;


class Usuario  {
    private:
        int id;
        string nome;
        string nomeUsuario;
        string endereco;
        string senha;
    public:
        ~Usuario();
        Usuario();
        bool login(string nomeUsuario, string senha);

};

#endif