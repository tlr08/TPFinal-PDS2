#include "PontoColetaDAO.hpp"

PontoColetaDAO::PontoColetaDAO(DbHelper *helper)
{
    this->helper = helper;
    this->usuarioDAO = new UsuarioDAO(helper);
}
PontoColetaDAO::~PontoColetaDAO(){
    delete this->usuarioDAO;
    this->usuarioDAO = nullptr;
}

bool PontoColetaDAO::create(PontoColeta *obj)
{
    list<variant *> *params = new list<variant *>();

    const char *sql = "INSERT INTO PONTOCOLETA (NOME, ENDERECO,ID_USUARIO) VALUES (?,?,?);";
    params->push_back(getVariant(obj->get_nome()));
    params->push_back(getVariant(obj->get_endereco()));
    params->push_back(getVariant(obj->get_user_id()));


    sqlite3_stmt *stmt;
    int rc = helper->prepareStatementSQL(sql, params, &stmt);
    rc = sqlite3_step(stmt);
    if(rc!=SQLITE_DONE)
        cout << sqlite3_errmsg(helper->getDatabase()) << endl;
    params->clear();
    delete params;
    return rc == SQLITE_DONE;
}
bool PontoColetaDAO::update(PontoColeta *obj)
{
    const char *sql = "UPDATE PONTOCOLETA SET NOME = ?, ENDERECO = ?, ID_USUARIO = ? WHERE ID = ?;";
    
    list<variant *> *params = new list<variant*>();
    params->push_back(getVariant(obj->get_nome()));
    params->push_back(getVariant(obj->get_endereco()));
    params->push_back(getVariant(obj->get_user_id()));


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
std::list<PontoColeta *> *PontoColetaDAO::list_all()
{
    PontoColeta* pontoColeta = nullptr;
    const char *sql = "select * from PONTOCOLETA";
    list<PontoColeta*> * listPontoColeta = new list<PontoColeta*>();

    std::list<Row *> *rows = nullptr;
    list<variant *> *params = new list<variant *>();

    rows = helper->read(sql, params);
    
    list<Row *>::iterator it;
    
    for (it = rows->begin(); it != rows->end(); ++it)
    {
        pontoColeta = getPontoColeta(*it);
        if(pontoColeta!=nullptr)
            listPontoColeta->push_back(pontoColeta);
    }
    pontoColeta = nullptr;
    return listPontoColeta;
}
PontoColeta *PontoColetaDAO::find(int id)
{
    const char *sql = "select * from PONTOCOLETA  where ID = ? limit 1";
    
    PontoColeta *pontoColeta = nullptr;
    std::list<Row *> *rows = nullptr;

    list<variant *> *params = new list<variant *>();
    params->push_back(getVariant(id));
    rows = helper->read(sql, params);
    list<Row *>::iterator it;
    list<Field *>::iterator itF;
    for (it = rows->begin(); it != rows->end(); ++it)
    {
        pontoColeta = getPontoColeta(*it);
    }


    return pontoColeta;
}
bool PontoColetaDAO::remove(int id)
{
    sqlite3_stmt *stmt;
    const char *sql = "DELETE FROM PONTOCOLETA WHERE ID = ?";
    sqlite3_prepare_v2(helper->getDatabase(), sql, strlen(sql), &stmt, nullptr);
    sqlite3_bind_int(stmt, 1, id);
    int rc = sqlite3_step(stmt);

    return  rc == SQLITE_DONE;
}
bool PontoColetaDAO::remove(PontoColeta *obj)
{
    return this->remove(obj->get_id());
}

PontoColeta* PontoColetaDAO::getPontoColeta(Row* row)
{


    PontoColeta* pontoColeta = new PontoColeta();
    list<Field *>::iterator itF;
    for (itF = row->fields->begin(); itF != row->fields->end(); ++itF)
    {
        Field *field = *itF;
        string fieldName = field->name;
        
        if (fieldName.compare("ID") == 0)
        {
            pontoColeta->set_id(getInt(field->data));
        }
        else if (fieldName.compare("NOME") == 0)
        {
            pontoColeta->set_nome(getString(field->data));
        }
        else if (fieldName.compare("ENDERECO") == 0)
        {
            pontoColeta->set_endereco(getString(field->data));
        }
        else if (fieldName.compare("ID_USUARIO") == 0)
        {
            Usuario* usuario = usuarioDAO->find(getInt(field->data));
            pontoColeta->set_Usuario(usuario);
            usuario = nullptr;
        }

    }
    return pontoColeta;
}