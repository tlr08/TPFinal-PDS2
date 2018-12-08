#include "ResiduosDAO.hpp"

ResiduosDAO::ResiduosDAO(DbHelper *helper)
{
    this->helper = helper;
}
ResiduosDAO::~ResiduosDAO(){
    
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
    int rc = helper->prepareStatementSQL(sql, params, &stmt);
    rc = sqlite3_step(stmt);
    if(rc!=SQLITE_DONE)
        cout << sqlite3_errmsg(helper->getDatabase()) << endl;
    params->clear();
    delete params;
    return rc == SQLITE_DONE;
}
bool ResiduosDAO::update(Residuo *obj)
{
    const char *sql = "UPDATE  Residuo SET NOME = ?, FORMA = ?, TIPO = ?, QUANTIDADE = ?, UNIDADE = ? WHERE ID = ?;";
    
    list<variant *> *params = new list<variant*>();

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
    int rc = 0;
    Residuo* residuo;
    const char *sql = "select * from RESIDUO";
    sqlite3_stmt *stmt;
    list<Residuo*> * listResiduo = new list<Residuo*>();

    std::list<Row *> *rows = NULL;
    list<variant *> *params = new list<variant *>();

    rows = helper->read(sql, params);
    
    list<Row *>::iterator it;
    
    for (it = rows->begin(); it != rows->end(); ++it)
    {
        residuo = getResiduo(*it);
        if(residuo!=NULL)
            listResiduo->push_back(residuo);
    }

    return listResiduo;
}
Residuo *ResiduosDAO::find(int id)
{
    int rc = 0;
    const char *sql = "select * from RESIDUO  where ID = ? limit 1";
    sqlite3_stmt *stmt;

    Residuo *residuo = NULL;
    std::list<Row *> *rows = NULL;

    list<variant *> *params = new list<variant *>();
    params->push_back(getVariant(id));
    rows = helper->read(sql, params);
    list<Row *>::iterator it;
    list<Field *>::iterator itF;
    for (it = rows->begin(); it != rows->end(); ++it)
    {
        residuo = getResiduo(*it);
    }


    return residuo;
}
bool ResiduosDAO::remove(int id)
{
    sqlite3_stmt *stmt;
    const char *sql = "DELETE FROM Residuo WHERE ID = ?";
    sqlite3_prepare_v2(helper->getDatabase(), sql, strlen(sql), &stmt, NULL);
    sqlite3_bind_int(stmt, 1, id);
    int rc = sqlite3_step(stmt);

    return  rc == SQLITE_DONE;
}
bool ResiduosDAO::remove(Residuo *obj)
{
    return this->remove(obj->get_id());
}

Residuo* ResiduosDAO::getResiduo(Row* row)
{

    Residuo* residuo = new Residuo();
    list<Field *>::iterator itF;
    for (itF = row->fields->begin(); itF != row->fields->end(); ++itF)
    {
        Field *field = *itF;
        string fieldName = field->name;
        
        if (fieldName.compare("ID") == 0)
        {
            residuo->set_id(getInt(field->data));
        }
        else if (fieldName.compare("NOME") == 0)
        {
            residuo->set_nome_residuo(getString(field->data));
        }
        else if (fieldName.compare("FORMA") == 0)
        {
            residuo->set_forma_armazenamento(getString(field->data));
        }
        else if (fieldName.compare("TIPO") == 0)
        {
            residuo->set_tipo_residuo(int_to_tipo(getInt(field->data)));
        }
        else if (fieldName.compare("QUANTIDADE") == 0)
        {
            residuo->set_Quantidade(getDouble(field->data));
        }
        else if (fieldName.compare("UNIDADE") == 0)
        {
            residuo->set_Unidade(getString(field->data));
        }
    }
    return residuo;
}