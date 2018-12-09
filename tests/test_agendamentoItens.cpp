#include "doctest.h"
#include "AgendamentoItens.hpp"

TEST_CASE("Teste - Construtor Agendamento Itens")
{
    Residuo *residuo = nullptr;
    double quantidade = 3;
    int id_agendamento = 1;

    AgendamentoItens *agendaItens = new AgendamentoItens(id_agendamento,residuo,quantidade);
    CHECK( agendaItens->get_id_agendamento() == 1);
    CHECK(agendaItens->get_residuo() == residuo);
    CHECK(agendaItens->get_quantidade() == 3);
}