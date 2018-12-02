#include "Residuo.hpp"


string tipo_to_string(TipoResiduo tipo){
    switch(tipo){
        case LIQUIDO:
            return "Líquido";
        case SOLIDO:
            return "Sólido";
        case ORGANICO:
            return "Orgânico";
        default:
            return "";
    }
}

TipoResiduo int_to_tipo(int value){
    switch(value){
        case 0:
            return LIQUIDO;
        case 1:
            return SOLIDO;
        case 2:
            return ORGANICO;
        default:
            return SOLIDO;
    }
}


Residuo::Residuo(){
    this->forma_armazenamento = "";
    this->id = 0;
    this->nome_residuo = "";
    this->tipo_residuo = SOLIDO;
}

Residuo::~Residuo(){
    this->nome_residuo.clear();
    this->forma_armazenamento.clear();
}

Residuo::Residuo(int id, string nome_residuo, 
                string forma_armazenamento, 
                TipoResiduo tipo_residuo){
    this->id = id;
    this->nome_residuo = nome_residuo;
    this->forma_armazenamento = forma_armazenamento;
    this->tipo_residuo = tipo_residuo;
}

int Residuo::get_id() const{
    return this->id;
}
string Residuo::get_nome_residuo() const{
    return this->nome_residuo;
}

TipoResiduo Residuo::get_tipo_residuo() const{
    return this->tipo_residuo;
}

string Residuo::get_forma_armazenamento() const{
    return this->forma_armazenamento;
}

bool Residuo::set_id(int id){
    if(id>0){
        this->id = id;
        return true;
    } 
    return false;
}

bool Residuo::set_nome_residuo(string nome_residuo){
    if(!nome_residuo.empty()){
        this->nome_residuo = nome_residuo;
        return true;
    }
    return false;
}

void Residuo::set_tipo_residuo(TipoResiduo tipo_residuo){
    this->tipo_residuo = tipo_residuo;
}

bool Residuo::set_forma_armazenamento(string forma_armazenamento){
    if(!forma_armazenamento.empty()){
        this->forma_armazenamento = forma_armazenamento;
        return true;
    }
    return false;
}

string Residuo::to_string(){
    return this->nome_residuo;
}

ostream& operator<<(ostream& out, const Residuo& obj){
    out << "ID: " << obj.get_id() << endl;
    out << "Resíduo: " << obj.get_nome_residuo() << endl;
    out << "Forma de Armazenamento: " << obj.get_nome_residuo() << endl;
    out << "Tipo de Resíduo: " << tipo_to_string(obj.get_tipo_residuo())  << endl;
    return out;
}


istream& operator>>(istream& in, Residuo& obj){
    string nome_residuo = "";
    string forma_armazenamento = "";
    int tipo_residuo = 0;
    
    cout << "Informe o nome do resíduo: ";
    in >> nome_residuo;

    cout << "Informe a forma de armazenamento: ";
    in >> forma_armazenamento;

    cout << "Informe o Tipo de Resíduo:";
    in >> tipo_residuo;

    obj.set_forma_armazenamento(forma_armazenamento);
    obj.set_nome_residuo(nome_residuo);
    obj.set_tipo_residuo(int_to_tipo(tipo_residuo));

    return in;
}

