#ifndef PONTOCOLETA_H
#define PONTOCOLETA_H
#include "Usuario.hpp"
#include <string>
using namespace std;

class PontoColeta
{
    public:
        PontoColeta();
        PontoColeta(int id,string nome,string endereco,int idUsuario);
        string get_nome() const;
        string get_endereco() const;
        int get_id_usuario() const;
        bool set_nome(string nome);
        bool set_endereco(string endereco);
        int get_id() const;
        bool set_id(int id);
        bool set_id_Usuario(int idUsuario);
        ~PontoColeta();
        friend ostream& operator<<(ostream& out,const PontoColeta& obj);
        friend istream& operator>>(istream& in,PontoColeta& obj);

    protected:

    private:
        string _nome, _endereco;
        int _id,_id_usuario;


};

#endif // PONTOCOLETA_H
