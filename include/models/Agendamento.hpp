#ifndef AGENDAMENTO_H
#define AGENDAMENTO_H
#include "Usuario.hpp"
#include "PontoColeta.hpp"
#include "Residuo.hpp"
#include <string>
using namespace std;

class Agendamento
{
    public:
        Agendamento();
        Agendamento(int id,string dataAgendada,string HoraAgendada,int id_doador,int id_receptor,int id_residuo);
        bool coleta_realizada();
        string get_dataAgendada() const;
        string get_HoraAgendada() const;
        bool set_dataAgendada(string dataAgendada);
        bool set_HoraAgendada(string horaAgendada);
        int get_id() const;
        int get_id_Doador() const;
        int get_id_Receptor() const;
        int get_id_Residuo() const;
        bool set_id(int id);
        bool set_id_Doador(int idDoador);
        bool set_id_Receptor(int idReceptor);
        bool set_id_Residuos(int idResiduos);

        friend ostream& operator<<(ostream& out,const Agendamento& obj);
        friend istream& operator>>(istream& in,Agendamento& obj);

    private:
        string _data_Agendada, _horario_Agendado;
        int _ID,_id_doador,_id_receptor,_id_residuo;

};

#endif // AGENDAMENTO_H
