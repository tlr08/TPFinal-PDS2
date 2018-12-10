#include "AgendamentoItensDAO.hpp"

AgendamentoItensDAO::AgendamentoItensDAO(DbHelper *helper)
{
    this->helper = helper;
    this->residuosDAO = new ResiduosDAO(helper);
}
AgendamentoItensDAO::~AgendamentoItensDAO()
{
    delete this->residuosDAO;
    this->residuosDAO= nullptr;
}

bool AgendamentoItensDAO::create(AgendamentoItens*obj)
{
    list<variant *> *params = new list<variant *>();

    const char *sql = "INSERT INTO AGENDAMENTO_ITENS (ID_AGENDAMENTO, ID_RESIDUO, QUANTIDADE) VALUES (?,?,?);";
    params->push_back(getVariant(obj->get_id_agendamento()));
    params->push_back(getVariant(obj->get_id_residuo()));
    params->push_back(getVariant(obj->get_quantidade()));

    sqlite3_stmt *stmt;
    int rc = helper->prepareStatementSQL(sql, params, &stmt);
    rc = sqlite3_step(stmt);
    if (rc != SQLITE_DONE)
        cout << sqlite3_errmsg(helper->getDatabase()) << endl;
    params->clear();
    delete params;
    return rc == SQLITE_DONE;
}
bool AgendamentoItensDAO::update(AgendamentoItens* obj)
{
    const char *sql = "UPDATE AGENDAMENTO_ITENS SET ID_AGENDAMENTO = ?, ID_RESIDUO = ?, QUANTIDADE = ? WHERE ID = ?;";
    list<variant *> *params = new list<variant *>();
    params->push_back(getVariant(obj->get_id_agendamento()));
    params->push_back(getVariant(obj->get_id_residuo()));
    params->push_back(getVariant(obj->get_quantidade()));
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

    return sqlite3_step(stmt) == SQLITE_DONE;
}
std::list<AgendamentoItens*>* AgendamentoItensDAO::list_by_id_agendamento(int id)
{
    AgendamentoItens* itemAgendamento = nullptr;
    const char *sql = "SELECT * from AGENDAMENTO_ITENS WHERE ID_AGENDAMENTO = ?";
    list<AgendamentoItens*> *listAgendamentoItens = new list<AgendamentoItens*>();
    std::list<Row *> *rows = nullptr;

    list<variant *> *params = new list<variant *>();
    
    params->push_back(getVariant(id));
    
    rows = helper->read(sql, params);

    for (auto it = rows->begin(); it != rows->end(); ++it)
    {
        itemAgendamento = getAgendamentoItens(*it);
        if (itemAgendamento != nullptr)
            listAgendamentoItens->push_back(itemAgendamento);
    }
    itemAgendamento = nullptr;
    return listAgendamentoItens;
}
std::list<AgendamentoItens*> *AgendamentoItensDAO::list_all()
{
    AgendamentoItens* itemAgendamento = nullptr;
    const char *sql = "SELECT * from AGENDAMENTO_ITENS";
    list<AgendamentoItens*> *listAgendamentoItens = new list<AgendamentoItens*>();

    std::list<Row *> *rows = nullptr;
    list<variant *> *params = new list<variant *>();

    rows = helper->read(sql, params);

    for (auto it = rows->begin(); it != rows->end(); ++it)
    {
        itemAgendamento = getAgendamentoItens(*it);
        if (itemAgendamento != nullptr)
            listAgendamentoItens->push_back(itemAgendamento);
    }
    itemAgendamento = nullptr;
    return listAgendamentoItens;
}
AgendamentoItens*AgendamentoItensDAO::find(int id)
{
    const char *sql = "SELECT * from AGENDAMENTO_ITENS where ID = ? limit 1";

    AgendamentoItens* item = nullptr;
    std::list<Row *> *rows = nullptr;

    list<variant *> *params = new list<variant *>();
    params->push_back(getVariant(id));
    rows = helper->read(sql, params);
    for (auto it = rows->begin(); it != rows->end(); ++it)
    {
        item = getAgendamentoItens(*it);
    }
    return item;
}

bool AgendamentoItensDAO::remove(int id)
{
    sqlite3_stmt *stmt;
    const char *sql = "DELETE FROM AGENDAMENTO_ITENS WHERE ID_AGENDAMENTO = ?";
    sqlite3_prepare_v2(helper->getDatabase(), sql, strlen(sql), &stmt, nullptr);
    sqlite3_bind_int(stmt, 1, id);
    int rc = sqlite3_step(stmt);
    
    return rc == SQLITE_DONE;
}
bool AgendamentoItensDAO::remove(AgendamentoItens*obj)
{
    return this->remove(obj->get_id());
}

AgendamentoItens* AgendamentoItensDAO::getAgendamentoItens(Row *row)
{
    AgendamentoItens* item = new AgendamentoItens();
    Residuo* residuo = residuosDAO->find(getInt(row->getValue("ID_RESIDUO")));
    
    item->set_id(getInt(row->getValue("ID")));
    item->set_id_agendamento(getInt(row->getValue("ID_AGENDAMENTO")));
    item->set_residuo(residuo);
    item->set_quantidade(getDouble(row->getValue("QUANTIDADE")));
   
    return item;
}

