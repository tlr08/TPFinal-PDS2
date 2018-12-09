#include "ResiduosDAO.hpp"

ResiduosDAO::ResiduosDAO(DbHelper *helper)
{
    this->helper = helper;
}
ResiduosDAO::~ResiduosDAO()
{
}

bool ResiduosDAO::create(Residuo *obj)
{
    list<variant *> *params = new list<variant *>();

    const char *sql = "INSERT INTO Residuo (NOME, FORMA, TIPO, QUANTIDADE, UNIDADE) VALUES (?,?,?,?,?);";
    params->push_back(getVariant(obj->get_nome_residuo()));
    params->push_back(getVariant(obj->get_forma_armazenamento()));
    params->push_back(getVariant(tipo_to_int(obj->get_tipo_residuo())));
    params->push_back(getVariant(obj->get_Quantidade()));
    params->push_back(getVariant(obj->get_Unidade()));

    sqlite3_stmt *stmt;
    helper->prepareStatementSQL(sql, params, &stmt);
    int rc = sqlite3_step(stmt);
    if (rc != SQLITE_DONE)
        cout << sqlite3_errmsg(helper->getDatabase()) << endl;
    params->clear();
    delete params;
    return rc == SQLITE_DONE;
}
bool ResiduosDAO::update(Residuo *obj)
{
    const char *sql = "UPDATE  Residuo SET NOME = ?, FORMA = ?, TIPO = ?, QUANTIDADE = ?, UNIDADE = ? WHERE ID = ?;";

    list<variant *> *params = new list<variant *>();

    params->push_back(getVariant(obj->get_nome_residuo()));
    params->push_back(getVariant(obj->get_forma_armazenamento()));
    params->push_back(getVariant(tipo_to_int(obj->get_tipo_residuo())));
    params->push_back(getVariant(obj->get_Quantidade()));
    params->push_back(getVariant(obj->get_Unidade()));

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
std::list<Residuo *> *ResiduosDAO::list_all()
{
    Residuo *residuo = nullptr;
    std::list<Row *> *rows = nullptr;

    const char *sql = "select * from RESIDUO";
    list<Residuo *> *listResiduo = new list<Residuo *>();

    list<variant *> *params = new list<variant *>();

    rows = helper->read(sql, params);

    for (auto it = rows->begin(); it != rows->end(); ++it)
    {
        residuo = getResiduo(*it);
        if (residuo != nullptr)
            listResiduo->push_back(residuo);
    }

    return listResiduo;
}
Residuo *ResiduosDAO::find(int id)
{
    const char *sql = "select * from RESIDUO  where ID = ? limit 1";

    Residuo *residuo = nullptr;
    std::list<Row *> *rows = nullptr;

    list<variant *> *params = new list<variant *>();
    params->push_back(getVariant(id));
    rows = helper->read(sql, params);
    for (auto it = rows->begin(); it != rows->end(); ++it)
    {
        residuo = getResiduo(*it);
    }

    return residuo;
}
bool ResiduosDAO::remove(int id)
{
    sqlite3_stmt *stmt;
    const char *sql = "DELETE FROM Residuo WHERE ID = ?";
    sqlite3_prepare_v2(helper->getDatabase(), sql, strlen(sql), &stmt, nullptr);
    sqlite3_bind_int(stmt, 1, id);
    int rc = sqlite3_step(stmt);

    return rc == SQLITE_DONE;
}
bool ResiduosDAO::remove(Residuo *obj)
{
    return this->remove(obj->get_id());
}

Residuo *ResiduosDAO::getResiduo(Row *row)
{
    Residuo *residuo = new Residuo();
    residuo->set_id(getInt(row->getValue("ID")));
    residuo->set_nome_residuo(getString(row->getValue("NOME")));
    residuo->set_forma_armazenamento(getString(row->getValue("FORMA")));
    residuo->set_tipo_residuo(int_to_tipo(getInt(row->getValue("TIPO"))));
    residuo->set_Quantidade(getDouble(row->getValue("QUANTIDADE")));
    residuo->set_Unidade(getString(row->getValue("UNIDADE")));
    return residuo;
}