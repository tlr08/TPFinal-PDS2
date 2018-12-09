#include "AgendamentoItens.hpp"

AgendamentoItens::AgendamentoItens()
{
    this->residuo = nullptr;
    this->quantidade = 0;
}
AgendamentoItens::AgendamentoItens(int id_agendamento, Residuo *residuo, double quantidade)
{   
    this->id_agendamento = id_agendamento;
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

ostream &operator<<(ostream &out, const AgendamentoItens &obj)
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
istream &operator>>(istream &in, AgendamentoItens &obj)
{
    double quantidade = 0;

    std::cout << "Informe a quantidade de resíduo: ";    
    in >> quantidade;
    obj.set_quantidade(quantidade);
    return in;
}

bool AgendamentoItens::set_id_agendamento(int agendamento)
{
    if(agendamento>0)
        this->id_agendamento =agendamento;
    return agendamento>0;
}
bool AgendamentoItens::set_id(int id)
{
    if(id>0)
        this->id = id;
    return id>0;
}
int AgendamentoItens::get_id() const 
{
    return this->id;
}
int AgendamentoItens::get_id_agendamento() const
{
    return this->id_agendamento;
}

int AgendamentoItens::get_id_residuo() const
{
    if(residuo!=nullptr)
        return residuo->get_id();
    else    
        return 0;
}