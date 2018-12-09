#include "doctest.h"
#include "PontoColeta.hpp"

TEST_CASE("Teste - Construtor")
{
    Usuario *user;
    PontoColeta *local = new PontoColeta(1,"BH Shopping","BH",user);
    CHECK(local->get_id() == 1);
    CHECK(local->get_nome() == "BH Shopping");
    CHECK(local->get_endereco() == "BH");
    CHECK(local->get_usuario() == user);

}