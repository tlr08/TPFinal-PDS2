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
        
    public:
        virtual ~Usuario() {
            this->endereco.clear();
            this->nome.clear();
            this->nome_usuario.clear();
            this->senha.clear();    
        }
        Usuario();
        Usuario(int id, string nome, string nome_usuario, string endereco, string senha);
        virtual bool valida_dados() = 0;
        bool login(string nome_usuario, string senha);
        int get_id() const;
        string get_nome() const;
        string get_nome_usuario() const;
        string get_endereco() const;
        string get_senha() const;
        bool set_nome(string nome);
        bool set_nome_usuario(string nome_usuario);
        bool set_endereco(string endereco);
        bool set_id(int id);
        bool set_senha(string senha);

};

#endif