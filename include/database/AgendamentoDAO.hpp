#ifndef AGENDAMENTO_DAO_H
#define AGENDAMENTO_DAO_H
#include "stdafx.hpp"
#include "DbHelper.hpp"
#include "IModelDAO.hpp"
#include "Agendamento.hpp"
#include "AgendamentoItens.hpp"
#include "AgendamentoItensDAO.hpp"
#include "PontoColetaDAO.hpp"
#include "UsuarioDAO.hpp"
class AgendamentoDAO : public IModelDAO<Agendamento>{
    private:
        AgendamentoItensDAO* itensDAO;
        UsuarioDAO* usuarioDAO; 
        PontoColetaDAO* coletaDAO;
        Agendamento* getAgendamento(Row* row);
    public:
        AgendamentoDAO(DbHelper* helper);
        virtual ~AgendamentoDAO();
        bool create(Agendamento* obj);
        bool update(Agendamento* obj);
        std::list<Agendamento*>* list_all();
        Agendamento* find(int id);
        virtual bool remove(int id);
        virtual bool remove(Agendamento* obj);
    
};
#endif