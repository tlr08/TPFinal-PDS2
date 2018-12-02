#include "PessoaJuridica.hpp"

string PessoaJuridica::get_cnpj() const{
    return this->cnpj;
}

bool PessoaJuridica::valida_dados(){
    return true;
}

bool PessoaJuridica::set_cnpj(string cnpj){
    if(!cnpj.empty()){
        this->cnpj = cnpj;
        return true;
    }
    return false;
}
ostream& operator<<(ostream& out, const PessoaJuridica& obj){
    out << "ID: " << obj.get_id() << endl;
    out << "Nome: " << obj.get_nome() << endl;
    out << "Usuário: " << obj.get_nome_usuario() << endl;
    out << "Endereço: " << obj.get_endereco() << endl;
    out << "CNPJ: " << obj.get_cnpj()  << endl;
    out << endl;
    return out;
}


istream& operator>>(istream& in, PessoaJuridica& obj){
    string nome_usuario = "";
    string nome =  "";
    string endereco = "";
    string cnpj = "";

    
    clearBuffer(in);
    
    cout << "Informe o nome: ";
    getline(in,nome,'\n');
    
    cout << "Informe o usuário: ";
    getline(in,nome_usuario,'\n');
    
    cout << "Informe o endereço: ";
    getline(in,endereco,'\n');

    cout << "Informe o CNPJ: ";
    getline(in,cnpj,'\n');
    
    obj.set_nome(nome);
    obj.set_nome_usuario(nome_usuario);
    obj.set_cnpj(cnpj);
    obj.set_endereco(endereco);
    
    return in;
}