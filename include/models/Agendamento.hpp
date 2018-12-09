#ifndef AGENDAMENTO_H
#define AGENDAMENTO_H
#include "Usuario.hpp"
#include "PontoColeta.hpp"
#include "Residuo.hpp"
#include "AgendamentoItens.hpp"
#include "stdafx.hpp"

using namespace std;

enum Status{
    NAO_REALIZADO = 0,
    REALIZADO = 1
};

string status_to_string(Status status);
Status int_to_status(int value);
int status_to_int (Status value);

class Agendamento
{
    public:
        Agendamento();
        Agendamento(int id, string dataAgendada,
                    string HoraAgendada,Usuario* doador,
                    Usuario* receptor,PontoColeta* local,
                    Status status);
        
        int get_id() const;
        string get_data_agendada() const;
        string get_hora_agendada() const;
        list<AgendamentoItens*>* get_itens() const;
        Usuario* get_doador() const;
        Usuario* get_receptor() const;
        PontoColeta* get_local() const;
        Status get_status() const;

        int get_id_doador() const;
        int get_id_receptor() const;
        int get_id_local() const;

        bool set_id(int id);
        bool set_doador(Usuario* doador);
        bool set_recepetor(Usuario* receptor);
        bool set_local(PontoColeta* local);
        bool set_data_agendada(string data_agendada);
        bool set_hora_agendada(string hora_agendada);
        bool set_itens(list<AgendamentoItens*>* list);
        void set_status(Status status);

        bool add_residuo(Residuo* residuo, double quantidade);
        bool remove_residuo(Residuo* residuo);

        
        
        ~Agendamento();

        friend ostream& operator<<(ostream& out,const Agendamento& obj);
        friend istream& operator>>(istream& in,Agendamento& obj);

    private:
        int id;
        string data_agendado, horario_agendado;
        Usuario* doador, *receptor;
        PontoColeta* local;
        Status status; 
        list<AgendamentoItens*>* itens_agendamento;
};

#endif // AGENDAMENTO_H

