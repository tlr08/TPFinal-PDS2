#ifndef AGENDAMENTO_ITENS_H
#define AGENDAMENTO_ITENS_H
#include "stdafx.hpp"
#include "Residuo.hpp"

class AgendamentoItens {
    private:
        Residuo* residuo;
        double quantidade;
        int id_agendamento, id;
    public:
        AgendamentoItens();
        AgendamentoItens(int agendamento, Residuo* residuo, double quantidade);

        ~AgendamentoItens();
        
        bool set_quantidade(double quantidade);
        bool set_residuo(Residuo* residuo);
        bool set_id_agendamento(int agendamento);
        bool set_id(int id);
        int get_id() const;
        int get_id_agendamento() const;
        double get_quantidade() const;
        Residuo* get_residuo() const;
        int get_id_residuo() const;
        
        friend ostream& operator<<(ostream& out,const AgendamentoItens& obj);
        friend istream& operator>>(istream& in,AgendamentoItens & obj);

};

#endif
