
/*
 * Oscar Arreola (A01178076), Mariana Amy Martínez (A00836245) y Alejandra Coeto (A01285221)
 * Última modificación: Domingo 29 de Noviembre
 */

#ifndef TSP
#define TSP

#include "libs.h"

using namespace std;

namespace algorithms
{

    /**
     Top-down dp to compute results for the TSP problem.
     node: Current node to visit
     mask: nodes visited until the moment
     cost: matrix containing costs of connections
     dp: store results for subproblems. Use [node][mask] as state
     path: store results for nodes visited

     Time complexity : O(n * n * 2 ^ n)
    */
    int route_cost(int node, int mask, vector<vector<int> > &cost, vector<vector<int> > &dp, vector<vector<int> > &path)
    {
        int n = cost.size();

        // If all the nodes have been explored, return the cost of returning to the original node.
        if (mask == ((1 << n) - 1))
        {
            path[node][mask] = 0;
            return cost[node][0];
        }

        // If answer was already computed, skip calculations

        if (dp[node][mask] != -1)
            return dp[node][mask];

        int visitCost = INT_MAX;

        for (int i = 0; i < n; i++)
        {
            if (!(mask & 1 << i))
            {
                int possibleCost = cost[node][i] + route_cost(i, mask | (1 << i), cost, dp, path);
                if (possibleCost < visitCost)
                {
                    visitCost = possibleCost;
                    path[node][mask] = i;
                }
            }
        }
        // Save and return the result
        return dp[node][mask] = visitCost;
    }

    /**
     Top-down dp to compute results for the TSP probelm.
     path: the paths saved when computing the optimum solution.
     n: the number of nodes in the graph.
     Returns: a vector of characters indicating the order of cities. 'A' corresponds to the first city, 'B' to the second and so on.
     Time complexity : O(n)
    */
    vector<char> get_path(vector<vector<int> > &path, int n)
    {
        vector<char> charPath{'A'};

        // Handle special case where there is only one city.
        if (n == 1)
            return charPath;

        int mask = 1;
        int current = 0;
        for (int i = 0; i < n; i++)
        {
            charPath.push_back(path[current][mask] + 'A');
            current = path[current][mask];
            mask |= 1 << current;
        }

        return charPath;
    }

    /**
     Wrapper to solve the problem. First uses helper method to compute solution.
     Then calls method to compute path in expected format.
    */
    vector<char> shortest_route(vector<vector<int> > &cost)
    {
        int n = cost.size();
        vector<vector<int> > dp(n, vector<int>(pow(2, n), -1));
        vector<vector<int> > path = dp;

        route_cost(0, 1, cost, dp, path);

        return get_path(path, n);
    }
}

#endif
