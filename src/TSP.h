
/*
 * Oscar Arreola (A01178076), Mariana Amy Martínez (A00836245) y Alejandra Coeto (A01285221)
 * Última modificación: Domingo 29 de Noviembre
 */

#include "libs.h"

using namespace std;

namespace algorithms
{

    /**
     Top-down dp to compute results for the TSP probelm.
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

    vector<char> get_path(vector<vector<int> > &path, int n)
    {
        vector<char> charPath{'A'};

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

    vector<char> shortest_route(vector<vector<int> > &cost)
    {
        int n = cost.size();
        vector<vector<int> > dp(n, vector<int>(pow(2, n), -1));
        vector<vector<int> > path = dp;

        route_cost(0, 1, cost, dp, path);

        return get_path(path, n);
    }
}

// int main()
// {

//     // vector<vector<int> > cost{
//     //     {0, 48, 12, 18},
//     //     {52, 0, 42, 32},
//     //     {18, 46, 0, 56},
//     //     {24, 36, 52, 0}};
//     // vector<vector<int> > cost = {{0, 16, 45, 32},
//     //                              {16, 0, 18, 21},
//     //                              {45, 18, 0, 7},
//     //                              {32, 21, 7, 0}};

//     vector<vector<int> > cost = {{0, 10, 15, 20},
//                                  {10, 0, 35, 25},
//                                  {15, 35, 0, 30},
//                                  {20, 25, 30, 0}};

//     vector<char> path = algorithms::shortest_route(cost);

//     for (auto stop : path)
//     {
//         cout << stop << " ";
//     }
//     cout << "\n";

//     return 0;
// }
