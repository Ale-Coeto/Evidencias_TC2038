#include "../src/FordFulkenson.h"
#include <cassert>
#include <catch2/catch_test_macros.hpp>

TEST_CASE("MaxFlow Algorithm") {
    SECTION("Case 1: Simple Graph") {
        vector<vector<pair<int,int>>> graph = {
            {{1, 10}, {2, 10}},
            {{2, 2}, {3, 4}},
            {{1, 6}, {3, 6}},
            {}
        };
        vector<vector<int>> capacity = {
            {0, 10, 10, 0},
            {0, 0,  2, 4},
            {0, 6,  0, 6},
            {0, 0,  0, 0}
        };

        REQUIRE(algorithms::maxflow(0, 3, graph, capacity) == 10);
    }

    SECTION("Case 2: Disconnected Graph") {
        vector<vector<pair<int,int>>> graph = {
            {{1, 10}},
            {},
            {},
            {}
        };
        vector<vector<int>> capacity = {
            {0, 10, 0, 0},
            {0, 0, 0, 0},
            {0, 0, 0, 0},
            {0, 0, 0, 0}
        };

        REQUIRE(algorithms::maxflow(0, 3, graph, capacity) == 0);
    }

    SECTION("Case 3: Graph with Multiple Paths") {
        vector<vector<pair<int,int>>> graph = {
            {{1, 10}, {2, 10}},
            {{3, 4}},
            {{3, 6}},
            {}
        };
        vector<vector<int>> capacity = {
            {0, 10, 10, 0},
            {0, 0,  0, 4},
            {0, 0,  0, 6},
            {0, 0,  0, 0}
        };

        REQUIRE(algorithms::maxflow(0, 3, graph, capacity) == 10);
    }
};

TEST_CASE("BFS in MaxFlow Algorithm") {

    vector<vector<pair<int, int>>> graph = {
        {{2, 10}, {1, 10}}, 
        {{2, 2}, {3, 4}}, 
        {{1, 6}, {3, 6}},  
        {}                  
    };

    vector<vector<int>> capacity = {
        {0, 10, 10, 0},  
        {0, 0,  2, 4}, 
        {0, 6,  0, 6}, 
        {0, 0,  0, 0}    
    };

    vector<int> parent(graph.size());
    int flow = algorithms::bfs(0, 3, parent, graph, capacity);
    REQUIRE(flow == 6);
    REQUIRE(parent[3] == 2);
    REQUIRE(parent[2] == 0); 
    
};