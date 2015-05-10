#define CATCH_CONFIG_MAIN
#include <catch.hpp>
#include "main.cpp"

SCENARIO( "test" ) {
    //    REQUIRE(solve({{1, 1, 12}, {359, 1, 12}, {2, 1, 12}, {358, 1, 12}}) == 0);
    REQUIRE(solve({{180, 1, 100000}, {180, 1, 1}}) == 1);
}
