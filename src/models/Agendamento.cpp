#include "Agendamento.hpp"

string status_to_string(Status status)
{
    switch (status)
    {
    case NAO_REALIZADO:
        return "Coleta não realizada";
    case REALIZADO:
        return "Coleta Realizada";
    default:
        return "";
    }
}

Status int_to_status(int value)
{
    switch (value)
    {
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
    this->data_agendado = "";
    this->horario_agendado = "";
    this->id = 0;
    this->doador = nullptr;
    this->receptor = nullptr;
    this->local = nullptr;
    this->itens_agendamento = new list<AgendamentoItens *>();
    this->status = NAO_REALIZADO;
}

Agendamento::Agendamento(int id, string dataAgendada,
                    string HoraAgendada,Usuario* doador,
                    Usuario* receptor,PontoColeta* local,
                    Status status)
{
    this->itens_agendamento= new list<Agendamento*>();
    this->id = id;
    this->data_agendado = dataAgendada;
    this->horario_agendado = HoraAgendada;
    this->doador = doador;
    this->receptor = receptor;
    this->local = local;
    this->status = status;
}
Agendamento::Agendamento(int id, string dataAgendada, string HoraAgendada, int id_doador, int id_receptor, int id_residuo, int id_PontoColeta)
{
    this->id = id;
    this->data_agendado = dataAgendada;
    this->horario_agendado = HoraAgendada;
    this_
}

ostream &operator<<(ostream &out, const Agendamento &obj)
{
    out << "ID: " << obj.get_id() << endl;
    out << "Data: " << obj.get_dataAgendada() << endl;
    out << "Hora: " << obj.get_HoraAgendada() << endl;
    out << "Status Coleta: " << status_to_string(obj.coleta_realizada()) << endl;
    out << endl;
    return out;
}
istream &operator>>(istream &in, Agendamento &obj)
{
    string dataAgendada = "";
    string HoraAgendada = "";
    int idDoador = 0;
    int idReceptor = 0;
    int idResiduos = 0;
    int idPontoColeta = 0;
    int realizado = 0;

    clearBuffer(in);

    cout << "Informe a data para agendamento(DD/MM/AAAA): ";
    getline(in, dataAgendada, '\n');

    cout << "Informe o horário para agendamento(HH:MM): ";
    getline(in, HoraAgendada, '\n');

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

Agendamento::~Agendamento()
{
    this->doador = nullptr;
    this->receptor = nullptr;
    this->local = nullptr;
    this->data_agendado.clear();
    this->horario_agendado.clear();
    this->itens_agendamento->clear();
    this->id = 0;
    delete this->itens_agendamento;
}

int Agendamento::get_id() const 
{
    return this->id;
}
string Agendamento::get_data_agendada() const
{
    return this->data_agendado;
}
string Agendamento::get_hora_agendada() const 
{
    return this->horario_agendado;
}
list<AgendamentoItens *>* Agendamento::get_itens() const
{
    return this->itens_agendamento;
}
Usuario* Agendamento::get_doador() const{
    return this->doador;
}
Usuario* Agendamento::get_receptor() const{
    return this->receptor;
}
PontoColeta* Agendamento::get_local() const{
    return this->local;
}
Status Agendamento::get_status() const {
    return this->status;
}

bool Agendamento::set_id(int id){
    if(id>0)
        this->id  =id;
    return id>0;
}
bool Agendamento::set_doador(Usuario *doador){
    if(doador!=nullptr)
        this->doador =doador;
    return doador!=nullptr;
}
bool Agendamento::set_recepetor(Usuario *receptor){
    if(receptor!=nullptr)
        this->receptor = receptor;
    return receptor!=nullptr;
}
bool Agendamento::set_local(PontoColeta *local){
    if(local!=nullptr)
        this->local = local;
    return local!=nullptr;
}
bool Agendamento::set_data_agendada(string data_agendada){
    if(!data_agendada.empty())
        this->data_agendado = data_agendada;
    return !data_agendada.empty();
}
bool Agendamento::set_hora_agendada(string hora_agendada){
    if(!hora_agendada.empty())
        this->horario_agendado = hora_agendada;
    return !hora_agendada.empty();
}
void Agendamento::set_status(Status status){
    this->status = status;
}

bool Agendamento::add_residuo(Residuo *residuo, double quantidade){
    if(residuo!=nullptr && quantidade>0){
        this->itens_agendamento->push_back(new AgendamentoItens(residuo,quantidade));
        return true;
    }
    else{
        return false;
    }
}
bool Agendamento::remove_residuo(Residuo *residuo){
    bool removed = false
    for(auto it = itens_agendamento;it!= itens_agendamento.end();++it){
        if(residuo->get_id() == (*it)->get_residuo()->get_id()){
            itens_agendamento->remove(*it);
            removed = true;
            break;
        }
    }
    return removed;
}
bool Agendamento::set_itens(list<AgendamentoItens*>* itens){
    if(itens!=nullptr)
        this->itens_agendamento= itens;
    return itens!=nullptr;
}