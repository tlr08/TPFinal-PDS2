#ifndef PESSOA_JURIDICA_H
#define PESSOA_JURIDICA_h
#include "stdafx.hpp"
#include "Usuario.hpp"

using namespace std;

class PessoaJuridica : public Usuario {
    public:
        PessoaJuridica() : Usuario(){
            this->cnpj = "";
        }
        ~PessoaJuridica(){
            this->cnpj.clear();
        }
        PessoaJuridica(int id, string nome, string nome_usuario, string endereco, string senha,
                     string cnpj) : Usuario(id, nome, nome_usuario, endereco, senha){
            this->cnpj =cnpj;
        }
        string get_cnpj() const;
        bool set_cnpj(string cnpj);
        bool valida_dados();
        friend ostream& operator<<(ostream& out,const PessoaJuridica& obj);
        friend istream& operator>>(istream& in,PessoaJuridica& obj);
    private:
        string cnpj;

};

#endif