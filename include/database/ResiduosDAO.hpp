#ifndef RESIDUOS_DAO_H
#define RESIDUOS_DAO_H
#include "stdafx.hpp"
#include "sqlite3.h"
#include "DbHelper.hpp"
#include "IModelDAO.hpp"
#include "Residuo.hpp"

class ResiduosDAO : public IModelDAO<Residuo>{
    private:
        DbHelper* helper;
        Residuo* getResiduo(Row* row);
    public:
        ResiduosDAO(DbHelper* helper);
        ~ResiduosDAO();
        bool create(Residuo* obj);
        bool update(Residuo* obj);
        std::list<Residuo*>* list_all();
        Residuo* find(int id);
        virtual bool remove(int id);
        virtual bool remove(Residuo* obj);
    
};
#endif