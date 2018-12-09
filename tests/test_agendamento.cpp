#include "doctest.h"
#include "Agendamento.hpp"

TEST_CASE("Teste - Construtor Agendamento")
{
    Usuario *doador;
    Usuario *receptor;
    PontoColeta *local;
    Status status = REALIZADO;
    Agendamento *agendamento = new Agendamento(1,"21/09/2018","14:30",doador,receptor,local,status);
    CHECK(agendamento->get_id() == 1);
    CHECK(agendamento->get_data_agendada() == "21/09/2018");
    CHECK(agendamento->get_hora_agendada()== "14:30");
    CHECK(agendamento->get_doador() == doador);
    CHECK(agendamento->get_receptor() == receptor);
    CHECK(agendamento->get_local() == local );
    CHECK(agendamento->get_status() == REALIZADO);
}