#include "../src/Kruskal.h"
#include <cassert>
#include <catch2/catch_test_macros.hpp>

TEST_CASE("Kruskal Algorithm") {
    SECTION("Case 1: Simple Graph") {
        vector<edge> edges = {
            edge(0, 1, 16)
        }

        REQUIRE(algorithms::maxflow(0, edges) == vii{{0, 1}});
    }
}