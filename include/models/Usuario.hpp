#ifndef USUARIO_HPP
#define USUARIO_HPP
#include "stdafx.hpp"


class Usuario  {
    private:
        int id;
        std::string nome;
        std::string nomeUsuario;
        std::string endereco;
        std::string senha;
    public:
        ~Usuario();
        Usuario();
        bool login(std::string nomeUsuario, std::string senha);

};

#endif