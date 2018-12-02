#include "Usuario.hpp"

bool Usuario::login(std::string nome_usuario, std::string senha){
    if(this->nome_usuario.compare(nome_usuario) == 0)
        if(this->senha.compare(senha) == 0)
            return true;
    return false;
}

int Usuario::get_id() const{
    return this->id;
}

string Usuario::get_nome() const{
    return this->nome;
}

string Usuario::get_nome_usuario() const{
    return this->nome_usuario;
}

string Usuario::get_endereco() const{
    return this->endereco;
}

string Usuario::get_senha() const{
    return this->senha;
}

Usuario::Usuario(int id,  string nome, string nome_usuario, string endereco, string senha){
    this->id = id;
    this->nome = nome;
    this->nome_usuario = nome_usuario;
    this->endereco = endereco;
    this->senha = senha;
}

Usuario::~Usuario(){
    this->endereco.clear();
    this->nome.clear();
    this->nome_usuario.clear();
    this->senha.clear();    
}

Usuario::Usuario(){
    this->id =  0;
    this->nome = "";
    this->nome_usuario = "";
    this->endereco = "";
    this->senha = "";
}
bool Usuario::set_endereco(string endereco){
    if(!endereco.empty()){
        this->endereco = endereco;
        return true;
    }
    return false;
}
bool Usuario::set_nome_usuario(string nome_usuario){
    if(!nome_usuario.empty()){
        this->nome_usuario = nome_usuario;
        return true;
    }
    return false;
}
bool Usuario::set_nome(string nome){
    if(!nome.empty()){
        this->nome = nome;
        return true;
    }
    return false;
}
bool Usuario::set_id(int id){
    if(id>0){
        this->id = id;
        return true;
    }
    return false;
}