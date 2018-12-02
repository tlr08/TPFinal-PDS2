#ifndef USUARIO_HPP
#define USUARIO_HPP
#include "stdafx.hpp"
using namespace std;


class Usuario  {
    private:
        string senha;
    protected:
        int id;
        string nome;
        string nome_usuario;
        string endereco;
        virtual string get_senha() const;
    public:
        ~Usuario();
        Usuario();
        Usuario(int id, string nome, string nome_usuario, string endereco, string senha);
        virtual bool valida_dados() = 0;
        virtual bool login(string nome_usuario, string senha);
        virtual int get_id() const;
        virtual string get_nome() const;
        virtual string get_nome_usuario() const;
        virtual string get_endereco() const;

        bool set_nome(string nome);
        bool set_nome_usuario(string nome_usuario);
        bool set_endereco(string endereco);
        bool set_id(int id);

};

#endif