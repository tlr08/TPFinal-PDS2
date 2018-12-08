#ifndef PONTOCOLETA_H
#define PONTOCOLETA_H
#include <string>
#include "Usuario.hpp"
#include "stdafx.hpp"
using namespace std;

class PontoColeta
{
    public:
        PontoColeta();
        PontoColeta(int id,string nome,string endereco, Usuario* user);
        string get_nome() const;
        string get_endereco() const;
        Usuario* get_usuario() const;
        bool set_nome(string nome);
        bool set_endereco(string endereco);
        int get_id() const;
        int get_user_id() const;
        bool set_id(int id);
        bool set_Usuario(Usuario* user);
        ~PontoColeta();
        friend ostream& operator<<(ostream& out,const PontoColeta& obj);
        friend istream& operator>>(istream& in, PontoColeta& obj);

    protected:

    private:
        string _nome, _endereco;
        int _id;
        Usuario* user;

};

#endif // PONTOCOLETA_H
