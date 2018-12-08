#include "UsuarioDAO.hpp"

UsuarioDAO::UsuarioDAO(DbHelper *helper)
{
    this->helper = helper;
}
UsuarioDAO::~UsuarioDAO(){    
}

bool UsuarioDAO::create(Usuario *obj)
{
    list<variant *> *params = new list<variant *>();

    const char *sql = "INSERT INTO USUARIO (NOME, NOME_USUARIO, ENDERECO, SENHA, CPF, CNPJ) VALUES (?, ?, ?, ?, ?, ?);";
    params->push_back(getVariant(obj->get_nome()));
    params->push_back(getVariant(obj->get_nome_usuario()));
    params->push_back(getVariant(obj->get_endereco()));
    params->push_back(getVariant(obj->get_senha()));

    if (PessoaFisica *pf = dynamic_cast<PessoaFisica *>(obj))
    {
        params->push_back(getVariant(pf->get_cpf()));
        params->push_back(getVariant(""));
    }
    else if (PessoaJuridica *pj = dynamic_cast<PessoaJuridica *>(obj))
    {
        params->push_back(getVariant(""));
        params->push_back(getVariant(pj->get_cnpj()));
    }

    sqlite3_stmt *stmt;
    int rc = helper->prepareStatementSQL(sql, params, &stmt);
    rc = sqlite3_step(stmt);
    if (rc != SQLITE_DONE)
    {
        cout << sqlite3_errmsg(helper->getDatabase()) << endl;
    }
    params->clear();
    delete params;
    return rc == SQLITE_DONE;
}
bool UsuarioDAO::update(Usuario *obj)
{
    const char *sql = "UPDATE USUARIO SET NOME = ?, NOME_USUARIO = ?, ENDERECO = ?, SENHA = ?, CPF = ?, CNPJ = ? WHERE ID = ?";
    list<variant *> *params = new list<variant *>();

    params->push_back(getVariant(obj->get_nome()));
    params->push_back(getVariant(obj->get_nome_usuario()));
    params->push_back(getVariant(obj->get_endereco()));
    params->push_back(getVariant(obj->get_senha()));

    if (PessoaFisica *pf = dynamic_cast<PessoaFisica *>(obj))
    {
        params->push_back(getVariant(pf->get_cpf()));
        params->push_back(getVariant(""));
    }
    else if (PessoaJuridica *pj = dynamic_cast<PessoaJuridica *>(obj))
    {
        params->push_back(getVariant(""));
        params->push_back(getVariant(pj->get_cnpj()));
    }
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
std::list<Usuario *> *UsuarioDAO::list_all()
{
    Usuario* usuario;
    const char *sql = "select (u.cpf = '')+1 as TIPO ,u.* from usuario u";
    list<Usuario*> * listUsuario = new list<Usuario*>();

    std::list<Row *> *rows = nullptr;
    list<variant *> *params = new list<variant *>();

    rows = helper->read(sql, params);
    
    list<Row *>::iterator it;
    
    for (it = rows->begin(); it != rows->end(); ++it)
    {
        usuario = getPessoa(*it);
        if(usuario!=nullptr)
            listUsuario->push_back(usuario);
    }

    return listUsuario;
}
Usuario *UsuarioDAO::find(int id)
{
    const char *sql = "select (u.cpf = '')+1 as TIPO ,u.* from usuario u  where u.id = ? limit 1";
    
    Usuario *usuario = nullptr;
    std::list<Row *> *rows = nullptr;

    list<variant *> *params = new list<variant *>();
    params->push_back(getVariant(id));
    rows = helper->read(sql, params);
    list<Row *>::iterator it;
    list<Field *>::iterator itF;
    for (it = rows->begin(); it != rows->end(); ++it)
    {
        usuario = getPessoa(*it);
    }

    return usuario;
}
bool UsuarioDAO::remove(int id)
{
    sqlite3_stmt *stmt;
    const char *sql = "DELETE FROM USUARIO WHERE ID = ?";
    sqlite3_prepare_v2(helper->getDatabase(), sql, strlen(sql), &stmt, nullptr);
    sqlite3_bind_int(stmt, 1, id);
    return sqlite3_step(stmt) == SQLITE_DONE;
}
bool UsuarioDAO::remove(Usuario *obj)
{
    return this->remove(obj->get_id());
}

Usuario *UsuarioDAO::getPessoa(Row* row)
{
    Usuario* usuario;
    list<Field *>::iterator itF;
    for (itF = row->fields->begin(); itF != row->fields->end(); ++itF)
    {
        Field *field = *itF;
        string fieldName = field->name;
        if (fieldName.compare("TIPO") == 0)
        {
            switch (getInt(field->data))
            {
            case 1:
                usuario = new PessoaFisica();
                break;
            case 2:
                usuario = new PessoaJuridica();
                break;
            }
        }
        else if (fieldName.compare("ID") == 0)
        {
            usuario->set_id(getInt(field->data));
        }
        else if (fieldName.compare("NOME") == 0)
        {
            usuario->set_nome(getString(field->data));
        }
        else if (fieldName.compare("NOME_USUARIO") == 0)
        {
            usuario->set_nome_usuario(getString(field->data));
        }
        else if (fieldName.compare("ENDERECO") == 0)
        {
            usuario->set_endereco(getString(field->data));
        }
        else if (fieldName.compare("SENHA") == 0)
        {
            usuario->set_senha(getString(field->data));
        }
        else if (fieldName.compare("CPF") == 0)
        {
            if (PessoaFisica *pf = dynamic_cast<PessoaFisica *>(usuario))
            {
                pf->set_cpf(getString(field->data));
            }
        }
        else if (fieldName.compare("CNPJ") == 0)
        {
            if (PessoaJuridica *pj = dynamic_cast<PessoaJuridica *>(usuario))
            {
                pj->set_cnpj(getString(field->data));
            }
        }
    }
    return usuario;
}