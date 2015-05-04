#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "solver.h"

SCENARIO( "test pass" ) {

    WHEN ("1 9") {
	REQUIRE(solve(1, 9) == 1);
	REQUIRE(solve(1, 10) == 2);
	REQUIRE(solve(3, 40) == 3);
	REQUIRE(solve(1, 1000000000000000000) == 707106780);
	REQUIRE(solve(10000000000000000, 1000000000000000000) == 49);
    }
}
