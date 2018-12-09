#include "AgendamentoDAO.hpp"

AgendamentoDAO::AgendamentoDAO(DbHelper *helper)
{
    this->helper = helper;
    this->usuarioDAO = new UsuarioDAO(helper);
    this->coletaDAO = new PontoColetaDAO(helper);
    this->itensDAO = new AgendamentoItensDAO(helper);
}
AgendamentoDAO::~AgendamentoDAO()
{
    delete this->usuarioDAO;
    delete this->coletaDAO;
    delete this->itensDAO;
    this->coletaDAO = nullptr;
    this->itensDAO = nullptr;
    this->usuarioDAO = nullptr;
}

bool AgendamentoDAO::create(Agendamento*obj)
{
    list<variant *> *params = new list<variant *>();

    const char *sql = "INSERT INTO AGENDAMENTO (ID_DOADOR, ID_RECEPTOR, STATUS, ID_LOCAL, DATA_AGENDADO, HORARIO_AGENDADO) VALUES (?,?,?,?,?,?);";
    params->push_back(getVariant(obj->get_id_doador()));
    params->push_back(getVariant(obj->get_id_receptor()));
    params->push_back(getVariant(status_to_int(obj->get_status())));
    params->push_back(getVariant(obj->get_id_local()));
    params->push_back(getVariant(obj->get_data_agendada()));
    params->push_back(getVariant(obj->get_hora_agendada()));

    sqlite3_stmt *stmt;
    int rc = helper->prepareStatementSQL(sql, params, &stmt);
    rc = sqlite3_step(stmt);
    if (rc != SQLITE_DONE)
        cout << sqlite3_errmsg(helper->getDatabase()) << endl;
    params->clear();
    delete params;

    int last_id = sqlite3_last_insert_rowid(helper->getDatabase());

    list<AgendamentoItens*>* itens = obj->get_itens();
    for(auto it = itens->begin(); it!=itens->end();++it)
    {
        (*it)->set_id_agendamento(last_id);
        itensDAO->create(*it);
    }
    return rc == SQLITE_DONE;
}
bool AgendamentoDAO::update(Agendamento*obj)
{
    const char *sql = "UPDATE AGENDAMENTO SET ID_DOADOR = ?, ID_RECEPTOR = ?, STATUS = ?, ID_LOCAL = ?, DATA_AGENDADO = ?, HORARIO_AGENDADO = ? WHERE ID = ?;";
    list<variant *> *params = new list<variant *>();
    params->push_back(getVariant(obj->get_id_doador()));
    params->push_back(getVariant(obj->get_id_receptor()));
    params->push_back(getVariant(status_to_int(obj->get_status())));
    params->push_back(getVariant(obj->get_id_local()));
    params->push_back(getVariant(obj->get_data_agendada()));
    params->push_back(getVariant(obj->get_hora_agendada()));
    params->push_back(getVariant(obj->get_id()));

    sqlite3_stmt *stmt;
    int rc = helper->prepareStatementSQL(sql, params, &stmt);
    rc = sqlite3_step(stmt);
    if (rc != SQLITE_DONE)
    {
        cout << sqlite3_errmsg(helper->getDatabase()) << endl;
    }
    params->clear();
    delete params;

    itensDAO->remove(obj->get_id());

    list<AgendamentoItens*>* itens = obj->get_itens();

    for(auto it = itens->begin(); it!=itens->end();++it)
    {
        (*it)->set_id_agendamento(obj->get_id());
        itensDAO->create(*it);
    }

    return sqlite3_step(stmt) == SQLITE_DONE;
}
std::list<Agendamento*> *AgendamentoDAO::list_all()
{
    Agendamento* agendamento = nullptr;
    const char *sql = "SELECT * from AGENDAMENTO";
    list<Agendamento*> *listAgendamento = new list<Agendamento*>();

    std::list<Row *> *rows = nullptr;
    list<variant *> *params = new list<variant *>();

    rows = helper->read(sql, params);

    for (auto it = rows->begin(); it != rows->end(); ++it)
    {
        agendamento = getAgendamento(*it);
        if (agendamento != nullptr)
            listAgendamento->push_back(agendamento);
    }
    agendamento = nullptr;
    return listAgendamento;
}
Agendamento*AgendamentoDAO::find(int id)
{
    const char *sql = "SELECT * from AGENDAMENTO where ID = ? limit 1";

    Agendamento* agendamento = nullptr;
    std::list<Row *> *rows = nullptr;

    list<variant *> *params = new list<variant *>();
    params->push_back(getVariant(id));
    rows = helper->read(sql, params);
    for (auto it = rows->begin(); it != rows->end(); ++it)
    {
        agendamento = getAgendamento(*it);
    }

    return agendamento;
}

bool AgendamentoDAO::remove(int id)
{
    sqlite3_stmt *stmt;
    const char *sql = "DELETE FROM AGENDAMENTO WHERE ID = ?";
    sqlite3_prepare_v2(helper->getDatabase(), sql, strlen(sql), &stmt, nullptr);
    sqlite3_bind_int(stmt, 1, id);
    int rc = sqlite3_step(stmt);
    this->itensDAO->remove(id);
    return rc == SQLITE_DONE ;
}
bool AgendamentoDAO::remove(Agendamento*obj)
{
    return this->remove(obj->get_id());
}

Agendamento* AgendamentoDAO::getAgendamento(Row *row)
{
    Agendamento* agendamento = new Agendamento();
    agendamento->set_id(getInt(row->getValue("ID")));

    Usuario* doador = usuarioDAO->find(getInt(row->getValue("ID_DOADOR")));
    Usuario* receptor = usuarioDAO->find(getInt(row->getValue("ID_RECEPTOR")));
    PontoColeta* local = coletaDAO->find(getInt(row->getValue("ID_LOCAL")));
    
    list<AgendamentoItens*>* itens = itensDAO->list_by_id_agendamento(
        agendamento->get_id()
    );

    agendamento->set_doador(doador);
    agendamento->set_recepetor(receptor);
    agendamento->set_local(local);
    agendamento->set_data_agendada(getString(row->getValue("DATA_AGENDADO")));
    agendamento->set_hora_agendada(getString(row->getValue("HORARIO_AGENDADO")));
    agendamento->set_itens(itens);
    agendamento->set_status(int_to_status(getInt(row->getValue("STATUS"))));
    return agendamento;
}

