#include "doctest.h"
#include "Residuo.hpp"

TEST_CASE("Teste - Construtor Resíduo")
{
    
    Residuo *rtest = new Residuo(1,"Pedra","Sacos",SOLIDO,10,"KG");
    CHECK(rtest->get_id() == 1);
    CHECK(rtest->get_nome_residuo() == "Pedra");
    CHECK(rtest->get_Quantidade() == 10);
    CHECK(rtest->get_forma_armazenamento() == "Sacos");
    CHECK(rtest->get_Unidade() == "KG");
}