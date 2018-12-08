#ifndef PESSOA_FISICA_H
#define PESSOA_FISICA_H
#include "stdafx.hpp"
#include "Usuario.hpp"

using namespace std;

class PessoaFisica : public Usuario {
    public:
        PessoaFisica() : Usuario(){
            this->cpf = "";
        }
        ~PessoaFisica(){
            this->cpf.clear();
        }        
        PessoaFisica(int id, string nome, string nome_usuario, string endereco, string senha,
                     string cpf) : Usuario(id, nome, nome_usuario, endereco, senha){
            this->cpf =cpf;
        }
        string get_cpf() const;
        bool set_cpf(string cpf);
        bool valida_dados();
        
        friend ostream& operator<<(ostream& out,const PessoaFisica& obj);
        friend istream& operator>>(istream& in,PessoaFisica& obj);
    private:
        string cpf;

};

#endif