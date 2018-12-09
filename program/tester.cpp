#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "DbHelper.hpp"
#include "constants.hpp"
TEST_CASE("SHOULD CONNECT TO DB"){
    DbHelper *db = new DbHelper(DEFAULT_DBNAME);
    CHECK_EQ(db->startConnection(), true);
}

