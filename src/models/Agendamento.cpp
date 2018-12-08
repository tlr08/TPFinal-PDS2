#include "Agendamento.hpp"

string status_to_string(Status status){
    switch(status){
        case NAO_REALIZADO:
            return "Coleta não realizada";
        case REALIZADO:
            return "Coleta Realizada";
        default:
            return "";
    }
}

Status int_to_status(int value){
    switch(value){
        case 0:
            return NAO_REALIZADO;
        case 1:
            return REALIZADO;

        default:
            return NAO_REALIZADO;
    }
}

Agendamento::Agendamento()
{
    _data_Agendada = "";
    _horario_Agendado = "";
    _ID = 0;
    _id_doador = 0;
    _id_receptor = 0;
    set_id_Residuos(0);
    _id_Ponto_coleta = 0;
    coletado = NAO_REALIZADO;
}

Agendamento::Agendamento(int id,string dataAgendada,string HoraAgendada,int id_doador,int id_receptor,int id_residuo,int id_PontoColeta)
{
    _data_Agendada = dataAgendada;
    _horario_Agendado = HoraAgendada;
    _ID = id;
    _id_doador = id_doador;
    _id_receptor = id_receptor;
    set_id_Residuos(id_residuo);
    _id_Ponto_coleta = id_PontoColeta;
    coletado = NAO_REALIZADO;
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
std::vector<int>::iterator Agendamento::get_id_Residuo() 
{
    return _id_residuos.begin();
}
int Agendamento::get_id_Ponto_coleta() const{
    return this->_id_Ponto_coleta;
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
        _id_residuos.push_back(idResiduos);
        return true;
    }
    return false;
}
bool Agendamento::set_id_Ponto_coleta(int idPontoColeta)
{
    if(!(idPontoColeta == 0)){
        this->_id_Ponto_coleta = idPontoColeta;
        return true;
    }
    return false;
}
Status Agendamento::coleta_realizada() const
{
    return this->coletado;
}

void Agendamento::set_coleta (Status realizado)
{
    this->coletado = realizado;
}
ostream& operator<<(ostream& out,const Agendamento& obj){
        out << "ID: " << obj.get_id() << endl;
        out << "Data: " << obj.get_dataAgendada() << endl;
        out << "Hora: " << obj.get_HoraAgendada() << endl;
        out << "Status Coleta: " << status_to_string(obj.coleta_realizada()) << endl;
        out << endl;
        return out;
}
istream& operator>>(istream& in,Agendamento& obj){
            string dataAgendada = "";
            string HoraAgendada = "";
            int idDoador = 0;
            int idReceptor = 0;
            int idResiduos = 0;
            int idPontoColeta = 0;
            int realizado = 0;


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
            obj.set_id_Residuos(idResiduos);

            cout << "Informe o ID do Ponto de Coleta: ";
            in >> idPontoColeta;

            cout << "Informe o Status da Coleta (0 - Não Realizado | 1 - Realizado): ";
             in >> realizado;


            obj.set_id_Ponto_coleta(idPontoColeta);
            obj.set_dataAgendada(dataAgendada);
            obj.set_HoraAgendada(HoraAgendada);
            obj.set_id_Doador(idDoador);
            obj.set_id_Receptor(idReceptor);
            obj.set_coleta(int_to_status(realizado));
           
            return in;
        }
void Agendamento::add_residuos(int idResiduos)
{
    vector<int>::iterator it;
    it = _id_residuos.end();
    _id_residuos.insert(it,idResiduos);
}
bool Agendamento::remove_residuos(int idResiduos)
{
    vector<int>::iterator it;
    it = _id_residuos.begin();
    if(_id_residuos.empty())
    {
        cout << "Não há residuos a ser removido ";
        return false;
    }
    else {
            while(it != _id_residuos.end()){
             if(*it == idResiduos)
                break;
             it++;
            }
            if(it != _id_residuos.end())
                _id_residuos.erase(it);
            else
                cout << "Resíduo não encontrado! ";
    }
    return true;
}

Agendamento::~Agendamento()
{
    _data_Agendada.clear();
    _horario_Agendado.clear();
    _id_residuos.clear();
}