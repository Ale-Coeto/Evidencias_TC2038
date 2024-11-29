#include "../src/LinearSearch.h"
#include <cassert>
#include <catch2/catch_test_macros.hpp>

TEST_CASE("Closest Central Algorithm")
{
    SECTION("Case 1: Teacher's sample input")
    {
        vector<pair<int, int> > centrals{{200, 500}, {300, 100}, {450, 150}, {520, 480}};
        pair<int, int> target{400, 300};
        vector<pair<int, int> > expected{{450, 150}};

        REQUIRE(algorithms::closestCentral(centrals, target) == expected);
    }

    SECTION("Case 2: Central in same spot as existing")
    {
        vector<pair<int, int> > centrals{{200, 500}, {300, 100}, {450, 150}, {520, 480}};
        pair<int, int> target{520, 480};
        vector<pair<int, int> > expected{{520, 480}};

        REQUIRE(algorithms::closestCentral(centrals, target) == expected);
    }

    SECTION("Case 3: Graph with single central")
    {
        vector<pair<int, int> > centrals{{200, 500}};
        pair<int, int> target{400, 300};
        vector<pair<int, int> > expected{{200, 500}};

        REQUIRE(algorithms::closestCentral(centrals, target) == expected);
    }

    SECTION("Case 4: Graph with no central")
    {
        vector<pair<int, int> > centrals{};
        pair<int, int> target{400, 300};

        vector<pair<int, int> > expected{};

        REQUIRE(algorithms::closestCentral(centrals, target) == expected);
    }

    SECTION("Case 5: 2 centrals at the same distance")
    {
        vector<pair<int, int> > centrals{{300, 300}, {500, 300}, {900, 100}};
        pair<int, int> target{400, 300};
        vector<pair<int, int> > expected{{300, 300}, {500, 300}};

        REQUIRE(algorithms::closestCentral(centrals, target) == expected);
    }
}