
/*
 * Oscar Arreola (A01178076), Mariana Amy Martínez (A00836245) y Alejandra Coeto (A01285221)
 * Última modificación: Domingo 29 de Noviembre
 */

#include "../src/TSP.h"
#include <cassert>
#include <catch2/catch_test_macros.hpp>

TEST_CASE("TSP Algorithm")
{
    SECTION("Case 1: Teacher's sample input")
    {
        vector<vector<int> > cost = {{0, 16, 45, 32},
                                     {16, 0, 18, 21},
                                     {45, 18, 0, 7},
                                     {32, 21, 7, 0}};
        vector<char> path = {'A', 'B', 'C', 'D', 'A'};
        REQUIRE(algorithms::shortest_route(cost) == path);
    }

    SECTION("Case 2: graph with 4 cities")
    {
        vector<vector<int> > cost = {{0, 10, 15, 20},
                                     {10, 0, 35, 25},
                                     {15, 35, 0, 30},
                                     {20, 25, 30, 0}};

        vector<char> path = {'A', 'B', 'D', 'C', 'A'};

        REQUIRE(algorithms::shortest_route(cost) == path);
    }

    SECTION("Case 3: Graph with single city")
    {
        vector<vector<int> > cost = {
            {0},
        };

        vector<char> path = {'A'};

        REQUIRE(algorithms::shortest_route(cost) == path);
    }

    SECTION("Case 4: Graph with 2 cities")
    {
        vector<vector<int> > cost = {
            {{0}, {100000}}, {{10000}, {0}}};

        vector<char> path = {
            'A',
            'B',
            'A'};

        REQUIRE(algorithms::shortest_route(cost) == path);
    }
}
