#include "Agendamento.hpp"

Agendamento::Agendamento()
{
    _data_Agendada = "";
    _horario_Agendado = "";
    _ID = 0;
    _id_doador = 0;
    _id_receptor = 0;
    _id_residuo = 0;
}

Agendamento::Agendamento(int id,string dataAgendada,string HoraAgendada,int id_doador,int id_receptor,int id_residuo)
{
    _data_Agendada = dataAgendada;
    _horario_Agendado = HoraAgendada;
    _ID = id;
    _id_doador = id_doador;
    _id_receptor = id_receptor;
    _id_residuo = id_residuo;
}
string Agendamento::get_dataAgendada() const
{
    return this->_data_Agendada;
}
string Agendamento::get_HoraAgendada() const
{
    return this->_horario_Agendado;
}
bool Agendamento::set_dataAgendada(string dataAgendada)
{
     if(!dataAgendada.empty()){
        this->_data_Agendada = dataAgendada;
        return true;
    }
    return false;
}
bool Agendamento::set_HoraAgendada(string horaAgendada)
{
    if(!horaAgendada.empty()){
        this->_horario_Agendado = horaAgendada;
        return true;
    }
    return false;
}

int Agendamento::get_id_Doador() const
{
    return this->_id_doador;
}
int Agendamento::get_id() const
{
    return this->_ID;
}
int Agendamento::get_id_Receptor() const
{
    return this->_id_receptor;
}
int Agendamento::get_id_Residuo() const
{
    return this->_id_residuo;
}
bool Agendamento::set_id(int id)
{
    if(!(id == 0)){
        this->_ID = id;
        return true;
    }
    return false;
}
bool Agendamento::set_id_Doador(int idDoador)
{
    if(!(idDoador == 0)){
        this->_id_doador = idDoador;
        return true;
    }
    return false;
}
bool Agendamento::set_id_Receptor(int idReceptor)
{
     if(!(idReceptor == 0)){
        this->_id_receptor = idReceptor;
        return true;
    }
    return false;
}
bool Agendamento::set_id_Residuos(int idResiduos)
{
     if(!(idResiduos == 0)){
        this->_id_residuo = idResiduos;
        return true;
    }
    return false;
}

ostream& operator<<(ostream& out,const Agendamento& obj)
        {
            out << "ID: " << obj.get_id() << endl;
            out << "Data: " << obj.get_dataAgendada() << endl;
            out << "Hora: " << obj.get_HoraAgendada() << endl;
            out << endl;
            return out;
        }
istream& operator>>(istream& in,Agendamento& obj)
        {
            string dataAgendada = "";
            string HoraAgendada = "";
            int idDoador = 0;
            int idReceptor = 0;
            int idResiduos = 0;



            clearBuffer(in);


            cout << "Informe a data para agendamento(DD/MM/AAAA): ";
            getline(in,dataAgendada,'\n');

            cout << "Informe o horário para agendamento(HH:MM): ";
            getline(in,HoraAgendada,'\n');

            cout << "Informe o ID do Doador: ";
            in >> idDoador;

            cout << "Informe o ID do Receptor: ";
            in >> idReceptor;

            cout << "Informe o ID do Residuo: ";
            in >> idResiduos;

            obj.set_dataAgendada(dataAgendada);
            obj.set_HoraAgendada(HoraAgendada);
            obj.set_id_Doador(idDoador);
            obj.set_id_Receptor(idReceptor);
            obj.set_id_Residuos(idResiduos);
           

            return in;
        }
