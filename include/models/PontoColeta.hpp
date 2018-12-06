#ifndef PONTOCOLETA_H
#define PONTOCOLETA_H
#include "Usuario.h"
#include <string>
using namespace std;

class PontoColeta
{
    public:
        PontoColeta();
        PontoColeta(string nome,string endereco /*Usuario *User*/);
        string get_nome() const;
        string get_endereco() const;
        //Usuario* get_usuario();
        bool set_nome(string nome);
        bool set_endereco(string endereco);
     //   bool set_Usuario(Usuario *User);
        ~PontoColeta();
        friend ostream& operator<<(ostream& out,const PontoColeta& obj);
        friend istream& operator>>(istream& in,PontoColeta& obj);

    protected:

    private:
        string _nome, _endereco;
     //   Usuario *_User;

};

#endif // PONTOCOLETA_H
