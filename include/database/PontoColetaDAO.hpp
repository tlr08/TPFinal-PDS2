#ifndef PontoColeta_DAO_H
#define PontoColeta_DAO_H
#include "stdafx.hpp"
#include "DbHelper.hpp"
#include "IModelDAO.hpp"
#include "PontoColeta.hpp"
#include "UsuarioDAO.hpp"
class PontoColetaDAO : public IModelDAO<PontoColeta>{
    private:
        UsuarioDAO* usuarioDAO;
        PontoColeta* getPontoColeta(Row* row);
    public:
        PontoColetaDAO(DbHelper* helper);
        ~PontoColetaDAO();
        bool create(PontoColeta* obj);
        bool update(PontoColeta* obj);
        std::list<PontoColeta*>* list_all();
        PontoColeta* find(int id);
        virtual bool remove(int id);
        virtual bool remove(PontoColeta* obj);
    
};
#endif