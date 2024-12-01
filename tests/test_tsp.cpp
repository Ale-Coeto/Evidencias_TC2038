#include "../src/TSP.h"
#include <cassert>
#include <catch2/catch_test_macros.hpp>

using namespace std;

TEST_CASE("TSP Algorithm")
{
    SECTION("Case 1: Sample input with 4 cities")
    {
        std::vector<std::vector<int> > cost = {
            {0, 16, 45, 32},
            {16, 0, 18, 21},
            {45, 18, 0, 7},
            {32, 21, 7, 0}};
        std::vector<char> expected_path = {'A', 'B', 'C', 'D', 'A'};

        REQUIRE(algorithms::shortest_route(cost) == expected_path);
    }

    SECTION("Case 2: Another input with 4 cities")
    {
        std::vector<std::vector<int> > cost = {
            {0, 10, 15, 20},
            {10, 0, 35, 25},
            {15, 35, 0, 30},
            {20, 25, 30, 0}};
        std::vector<char> expected_path = {'A', 'B', 'D', 'C', 'A'};

        REQUIRE(algorithms::shortest_route(cost) == expected_path);
    }

    SECTION("Case 3: Graph with a single city")
    {
        std::vector<std::vector<int> > cost = {
            {0}};
        std::vector<char> expected_path = {'A'};

        REQUIRE(algorithms::shortest_route(cost) == expected_path);
    }

    SECTION("Case 4: Graph with two cities")
    {
        std::vector<std::vector<int> > cost = {
            {0, 10000},
            {10000, 0}};
        std::vector<char> expected_path = {'A', 'B', 'A'};

        REQUIRE(algorithms::shortest_route(cost) == expected_path);
    }
}
