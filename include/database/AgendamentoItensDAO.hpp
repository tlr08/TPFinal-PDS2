#ifndef AGENDAMENTOITENS_DAO_H
#define AGENDAMENTOITENS_DAO_H
#include "stdafx.hpp"
#include "DbHelper.hpp"
#include "IModelDAO.hpp"
#include "ResiduosDAO.hpp"
#include "Residuo.hpp"
#include "Agendamento.hpp"
#include "AgendamentoItens.hpp"

class AgendamentoItensDAO : public IModelDAO<AgendamentoItens>{
    private:
        ResiduosDAO* residuosDAO;
        AgendamentoItens* getAgendamentoItens(Row* row);
    public:
        AgendamentoItensDAO(DbHelper* helper);
        ~AgendamentoItensDAO();
        bool create(AgendamentoItens* obj);
        bool update(AgendamentoItens* obj);
        std::list<AgendamentoItens*>* list_all();
        std::list<AgendamentoItens*>* list_by_id_agendamento(int id);
        AgendamentoItens* find(int id);
        virtual bool remove(int id);
        virtual bool remove(AgendamentoItens* obj);
    
};
#endif