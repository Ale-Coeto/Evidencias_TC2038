#include "../src/FordFulkenson.h"
#include <cassert>
#include <catch2/catch_test_macros.hpp>

TEST_CASE("MaxFlow Algorithm") {
    SECTION("Case 1: Simple Graph") {
        vector<vii> graph = {
            {{1, 10}, {2, 10}},
            {{2, 2}, {3, 4}},
            {{1, 6}, {3, 6}},
            {}
        };
        vector<vi> capacity = {
            {0, 10, 10, 0},
            {0, 0,  2, 4},
            {0, 6,  0, 6},
            {0, 0,  0, 0}
        };

        REQUIRE(algorithms::maxflow(0, 3, graph, capacity) == 10);
    }

    SECTION("Case 2: Disconnected Graph") {
        vector<vii> graph = {
            {{1, 10}},
            {},
            {},
            {}
        };
        vector<vi> capacity = {
            {0, 10, 0, 0},
            {0, 0, 0, 0},
            {0, 0, 0, 0},
            {0, 0, 0, 0}
        };

        REQUIRE(algorithms::maxflow(0, 3, graph, capacity) == 0);
    }

    SECTION("Case 3: Graph with Multiple Paths") {
        vector<vii> graph = {
            {{1, 10}, {2, 10}},
            {{3, 4}},
            {{3, 6}},
            {}
        };
        vector<vi> capacity = {
            {0, 10, 10, 0},
            {0, 0,  0, 4},
            {0, 0,  0, 6},
            {0, 0,  0, 0}
        };

        REQUIRE(algorithms::maxflow(0, 3, graph, capacity) == 10);
    }
}