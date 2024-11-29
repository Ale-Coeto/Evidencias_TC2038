#include "../src/FordFulkenson.h"
#include <cassert>
#include <catch2/catch_test_macros.hpp>

TEST_CASE("BFS in a Cyclic Graph") {
    // Graph: adjacency list
    vector<vector<pair<int, int>>> graph = {
        {{1, 8}, {2, 10}},  // Node 0 connections
        {{2, 5}},           // Node 1 connections
        {{1, 3}, {3, 7}},   // Node 2 connections (cycle: 2 → 1)
        {}                  // Node 3 (sink)
    };

    // Capacity: adjacency matrix
    vector<vector<int>> capacity = {
        {0, 8, 10, 0},   // Capacities from Node 0
        {0, 0,  5, 0},   // Capacities from Node 1
        {0, 3,  0, 7},   // Capacities from Node 2 (cycle: 2 → 1)
        {0, 0,  0, 0}    // Capacities from Node 3
    };

    vector<int> parent(graph.size());

    SECTION("Path Exists") {
        int flow = algorithms::bfs(0, 3, parent, graph, capacity);

        // Check returned flow
        REQUIRE(flow == 7); // Path 0 → 2 → 3, constrained by edge (2 → 3)

        // Check parent vector
        REQUIRE(parent[3] == 2); // Sink (3) was reached via Node 2
        REQUIRE(parent[2] == 0); // Node 2 was reached via Source (0)
    }

    SECTION("No Path Exists After Blocking Edges") {
        // Block all paths to the sink
        capacity[2][3] = 0;
        int flow = algorithms::bfs(0, 3, parent, graph, capacity);

        // Check returned flow
        REQUIRE(flow == 0);

        // Ensure sink node is unreachable
        REQUIRE(parent[3] == -1);
    }
}