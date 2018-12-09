#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Usuario.hpp"
#include "PessoaFisica.hpp"
#include "PessoaJuridica.hpp"

/*TEST_CASE("Teste - Upcasting(Pessoa Física)")
{
    Usuario *user; 
    PessoaFisica *ptest = new PessoaFisica(1,"Lucas","bispera","R. Lume","1234","01999");
    user = ptest;
    CHECK(user->get_id() == 1);
    CHECK(user->get_nome() == "Lucas");
    CHECK(user->get_nome_usuario() == "bispera");
    CHECK(user->get_endereco() == "R. Lume");
    CHECK(user->get_senha() == "1234");
    
}*/


