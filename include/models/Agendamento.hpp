#ifndef AGENDAMENTO_H
#define AGENDAMENTO_H
#include "Usuario.hpp"
#include "PontoColeta.hpp"
#include "Residuo.hpp"
#include <string>
#include <vector>

using namespace std;

enum Status{
    NAO_REALIZADO = 0,
    REALIZADO = 1
};

string status_to_string(Status status);
Status int_to_status(int);
class Agendamento
{
    public:
        Agendamento();
        Agendamento(int id,string dataAgendada,string HoraAgendada,int id_doador,int id_receptor,int id_residuo,int id_PontoColeta);
        Status coleta_realizada() const;
        string get_dataAgendada() const;
        string get_HoraAgendada() const;
        bool set_dataAgendada(string dataAgendada);
        bool set_HoraAgendada(string horaAgendada);
        int get_id() const;
        int get_id_Doador() const;
        int get_id_Receptor() const;
        std::vector<int>::iterator  get_id_Residuo() ;
        int get_id_Ponto_coleta() const;
        bool set_id(int id);
        bool set_id_Doador(int idDoador);
        bool set_id_Receptor(int idReceptor);
        bool set_id_Residuos(int idResiduos);
        bool set_id_Ponto_coleta(int idPontoColeta);
        void set_coleta(Status realizado);
        void add_residuos(int idResiduos);
        bool remove_residuos(int idResiduos);

        friend ostream& operator<<(ostream& out,const Agendamento& obj);
        friend istream& operator>>(istream& in,Agendamento& obj);

    private:
        string _data_Agendada, _horario_Agendado;
        int _ID,_id_doador,_id_receptor,_id_Ponto_coleta;
        vector <int> _id_residuos; 
        Status coletado; 

};

#endif // AGENDAMENTO_H
