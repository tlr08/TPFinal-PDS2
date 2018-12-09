#include "AgendamentoItens.hpp"

AgendamentoItens::AgendamentoItens()
{
    this->residuo = nullptr;
    this->quantidade = 0;
}
AgendamentoItens::AgendamentoItens(Residuo *residuo, double quantidade)
{   
    this->residuo =residuo;
    this->quantidade = quantidade;
}

AgendamentoItens::~AgendamentoItens()
{
    this->quantidade = 0;
    this->residuo = nullptr;
}
bool AgendamentoItens::set_quantidade(double quantidade)
{
    if(quantidade>0)
        this->quantidade =  quantidade;
    return quantidade>0;
}
bool AgendamentoItens::set_residuo(Residuo *residuo)
{
    if(residuo!=nullptr)
        this->residuo = residuo;
    return residuo!=nullptr;
}
double AgendamentoItens::get_quantidade() const
{
    return this->quantidade;
}
Residuo* AgendamentoItens::get_residuo() const
{
    return this->residuo;
}

friend ostream &operator<<(ostream &out, const AgendamentoItens &obj)
{
    out << obj.get_residuo()->get_id()
        << " - "
        << obj.get_residuo()->get_nome_residuo()
        << "  "
        << obj.get_quantidade()
        << " "
        << obj.get_residuo()->get_Unidade() << endl;
    return out;
}
friend istream &operator>>(istream &in, AgendamentoItens &obj)
{
    return in;
}