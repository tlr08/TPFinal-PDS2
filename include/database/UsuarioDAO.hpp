#ifndef USUARIO_DAO_H
#define USUARIO_DAO_H
#include "stdafx.hpp"
#include "sqlite3.h"
#include "DbHelper.hpp"
#include "IModelDAO.hpp"
#include "Usuario.hpp"
#include "PessoaFisica.hpp"
#include "PessoaJuridica.hpp"

class UsuarioDAO : public IModelDAO<Usuario>{
    private:
        Usuario* getPessoa(Row* row);
    public:
        UsuarioDAO(DbHelper* helper);
        ~UsuarioDAO();
        bool create(Usuario* obj);
        bool update(Usuario* obj);
        std::list<Usuario*>* list_all();
        Usuario* find(int id);
        virtual bool remove(int id);
        virtual bool remove(Usuario* obj);
    
};
#endif