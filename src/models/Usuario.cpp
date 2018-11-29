#include "Usuario.hpp"

Usuario::~Usuario(){
    
}

bool Usuario::login(std::string nomeUsuario, std::string senha){
    if(this->nomeUsuario.compare(nomeUsuario) == 0)
        if(this->senha.compare(senha) == 0)
            return true;
    return false;
}