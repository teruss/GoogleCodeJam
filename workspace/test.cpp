#define CATCH_CONFIG_MAIN
#include <catch.hpp>
#include "main.cpp"

SCENARIO( "test" ) {
    REQUIRE(solve(1) == 1);
    REQUIRE(solve(2) == 2);
}
