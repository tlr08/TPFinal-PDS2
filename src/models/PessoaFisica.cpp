#include "PessoaFisica.hpp"

string PessoaFisica::get_cpf () const{
    return this->cpf;
}

bool PessoaFisica::valida_dados(){
    return true;
}

bool PessoaFisica::set_cpf(string cpf){
    if(!cpf.empty()){
        this->cpf = cpf;
        return true;
    }
    return false;
}
ostream& operator<<(ostream& out, const PessoaFisica& obj){
    out << "ID: " << obj.get_id() << endl;
    out << "Nome: " << obj.get_nome() << endl;
    out << "Usuário: " << obj.get_nome_usuario() << endl;
    out << "Endereço: " << obj.get_endereco() << endl;
    out << "CPF: " << obj.get_cpf()  << endl;
    out << endl;
    return out;
}


istream& operator>>(istream& in, PessoaFisica& obj){
    string nome_usuario = "";
    string nome =  "";
    string endereco = "";
    string cpf = "";

    
    clearBuffer(in);
    
    cout << "Informe o nome: ";
    getline(in,nome,'\n');
    
    cout << "Informe o usuário: ";
    getline(in,nome_usuario,'\n');
    
    cout << "Informe o endereço: ";
    getline(in,endereco,'\n');

    cout << "Informe o CPF: ";
    getline(in,cpf,'\n');
    
    obj.set_nome(nome);
    obj.set_nome_usuario(nome_usuario);
    obj.set_cpf(cpf);
    obj.set_endereco(endereco);
    
    return in;
}