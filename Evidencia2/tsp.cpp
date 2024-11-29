#include "libs.h"

using namespace std;

int routeCost(int node, int mask, vector<vector<int> > &cost, vector<vector<int> > &dp, vector<vector<int> > &path)
{
    int n = cost.size();

    // If all the nodes have been explored, return the cost of returning to the original node.
    if (mask == ((1 << n) - 1))
    {
        path[node][mask] = 0;
        return cost[node][0];
    }

    if (dp[node][mask] != -1)
        return dp[node][mask];

    int visitCost = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        if (!(mask & 1 << i))
        {
            int possibleCost = cost[node][i] + routeCost(i, mask | (1 << i), cost, dp, path);
            if (possibleCost < visitCost)
            {
                visitCost = possibleCost;
                path[node][mask] = i;
            }
        }
    }

    return dp[node][mask] = visitCost;
}

vector<char> getPath(vector<vector<int> > &path, int n)
{
    vector<char> charPath{'A'};
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

vector<char> shortestRoute(vector<vector<int> > &cost)
{
    int n = cost.size();
    vector<vector<int> > dp(n, vector<int>(pow(2, n), -1));
    vector<vector<int> > path = dp;

    cout << "Mincost: " << routeCost(0, 1, cost, dp, path) << "\n";

    return getPath(path, n);
}

int main()
{

    vector<vector<int> > cost{
        {0, 48, 12, 18},
        {52, 0, 42, 32},
        {18, 46, 0, 56},
        {24, 36, 52, 0}};

    // vector<vector<int> > cost = {{0, 10, 15, 20},
    //                              {10, 0, 35, 25},
    //                              {15, 35, 0, 30},
    //                              {20, 25, 30, 0}};

    vector<char> path = shortestRoute(cost);

    for (auto stop : path)
    {
        cout << stop << " ";
    }
    cout << "\n";

    return 0;
}