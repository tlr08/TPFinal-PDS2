#ifndef AGENDAMENTO_ITENS_H
#define AGENDAMENTO_ITENS_H
#include "stdafx.hpp"
#include "Residuo.hpp"

class AgendamentoItens {
    private:
        Residuo* residuo;
        double quantidade;

    public:
        AgendamentoItens();
        AgendamentoItens(Residuo* residuo, double quantidade);

        ~AgendamentoItens();
        
        bool set_quantidade(double quantidade);
        bool set_residuo(Residuo* residuo);

        double get_quantidade() const;
        Residuo* get_residuo() const;

        friend ostream& operator<<(ostream& out,const AgendamentoItens& obj);
        friend istream& operator>>(istream& in,AgendamentoIte & obj);

};

#endif