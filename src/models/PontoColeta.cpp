#include "PontoColeta.hpp"
PontoColeta::PontoColeta()
{
    _nome = "";
    _endereco = "";
    _id = 0;
    user = nullptr;
}
PontoColeta::PontoColeta(int id, string nome, string endereco, Usuario *user)
{
    _id = id;
    _nome = nome;
    _endereco = endereco;
    user = user;
}
string PontoColeta::get_nome() const
{
    return this->_nome;
}
string PontoColeta::get_endereco() const
{
    return this->_endereco;
}
int PontoColeta::get_id() const
{
    return this->_id;
}
Usuario* PontoColeta::get_usuario() const
{
    return user;
}
bool PontoColeta::set_nome(string nome)
{
    if (!nome.empty())
    {
        _nome = nome;
        return true;
    }
    return false;
}
bool PontoColeta::set_endereco(string endereco)
{
    if (!endereco.empty())
    {
        _endereco = endereco;
        return true;
    }
    return false;
}
bool PontoColeta::set_id(int id)
{
    if (id > 0)
    {
        this->_id = id;
        return true;
    }
    return false;
}
bool PontoColeta::set_Usuario(Usuario* user)
{
    if(user!=nullptr){
        this->user  =user;
        return true;
    }
    return false;
}   
PontoColeta::~PontoColeta()
{
    _nome.clear();
    _endereco.clear();
    user=nullptr;
}

ostream &operator<<(ostream &out, const PontoColeta &obj)
{
    out << "ID: " << obj.get_id() << endl;
    out << "Nome: " << obj.get_nome() << endl;
    if(obj.get_usuario() != nullptr)
        out << "Usuário: " <<  obj.get_usuario() << endl;
    out << "Endereco: " << obj.get_endereco() << endl;
    out << endl;
    return out;
}
istream &operator>>(istream &in, PontoColeta &obj)
{
    string nome = "";
    string endereco = "";

    clearBuffer(in);

    cout << "Informe o nome do local: ";
    getline(in, nome, '\n');

    cout << "Informe o endereço: ";
    getline(in, endereco, '\n');

    obj.set_nome(nome);
    obj.set_endereco(endereco);
    cout << endl;
    return in;
}

int PontoColeta::get_user_id() const{
    if(user!=nullptr){
        return user->get_id();
    }
    return 0;
}