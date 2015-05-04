#define CATCH_CONFIG_MAIN
#include <catch.hpp>
#include "main.cpp"

SCENARIO( "test" ) {
    REQUIRE(solve(8, {3}) == 7);
    REQUIRE(solve(20, {3, 6, 14}) == 35);
}
