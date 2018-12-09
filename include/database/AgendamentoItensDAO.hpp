#ifndef AGENDAMENTOITENS_DAO_H
#define AGENDAMENTOITENS_DAO_H
#include "stdafx.hpp"
#include "DbHelper.hpp"
#include "IModelDAO.hpp"
#include "Residuo.hpp"
#include "ResiduosDAO.hpp"
#include "AgendamentoItens.hpp"
#include "Agendamento.hpp"

class AgendamentoItensDAO : public IModelDAO<AgendamentoItens>{
    private:
        ResiduosDAO* residuosDAO;
        AgendamentoItens* getPontoColeta(Row* row);
    public:
        AgendamentoItensDAO(DbHelper* helper);
        ~AgendamentoItensDAO();
        bool create(AgendamentoItens* obj);
        bool update(AgendamentoItens* obj);
        std::list<AgendamentoItens*>* list_all();
        AgendamentoItens* find(int id);
        virtual bool remove(int id);
        virtual bool remove(AgendamentoItens* obj);
    
};
#endif