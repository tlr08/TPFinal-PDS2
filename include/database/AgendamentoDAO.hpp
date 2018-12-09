#ifndef AGENDAMENTO_DAO_H
#define AGENDAMENTO_DAO_H
#include "stdafx.hpp"
#include "DbHelper.hpp"
#include "IModelDAO.hpp"
#include "Residuo.hpp"
#include "AgendamentoItens.hpp"
#include "Agendamento.hpp"

class AgendamentoDAO : public IModelDAO<Agendamento>{
    private:
        Agendamento* getPontoColeta(Row* row);
    public:
        AgendamentoDAO(DbHelper* helper);
        ~AgendamentoDAO();
        bool create(Agendamento* obj);
        bool update(Agendamento* obj);
        std::list<Agendamento*>* list_all();
        Agendamento* find(int id);
        virtual bool remove(int id);
        virtual bool remove(Agendamento* obj);
    
};
#endif