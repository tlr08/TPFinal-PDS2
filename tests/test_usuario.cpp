#include "doctest.h"
#include "Usuario.hpp"
#include "PessoaFisica.hpp"
#include "PessoaJuridica.hpp"

TEST_CASE("Teste - Upcasting")
{
    Usuario *user; 
    PessoaFisica *ptest = new PessoaFisica(1,"Lucas","bispera","R. Lume","1234","01999");
    user = ptest;
    CHECK(user->get_id() == 1);
    CHECK(user->get_nome() == "Lucas");
    CHECK(user->get_nome_usuario() == "bispera");
    CHECK(user->get_endereco() == "R. Lume");
    CHECK(user->get_senha() == "1234");
}
TEST_CASE("Teste - Pessoa Física")
{
    PessoaFisica *ptest = new PessoaFisica(2,"Bruno","brun0","Rio de Janeiro","4321","0000");
    CHECK(ptest->get_id() == 2);
    CHECK(ptest->get_nome() == "Bruno");
    CHECK(ptest->get_nome_usuario() == "brun0");
    CHECK(ptest->get_endereco() == "Rio de Janeiro");
    CHECK(ptest->get_senha() == "4321");
    CHECK(ptest->get_cpf() == "0000");
}
TEST_CASE("Teste - Pessoa Jurídica")
{
    PessoaJuridica *ptest = new PessoaJuridica(3,"Luis","luis","São Paulo","1111","1112");
    CHECK(ptest->get_id() == 3);
    CHECK(ptest->get_nome() == "Luis");
    CHECK(ptest->get_nome_usuario() == "luis");
    CHECK(ptest->get_endereco() == "São Paulo");
    CHECK(ptest->get_senha() == "1111");
    CHECK(ptest->get_cnpj() == "1112");
}
