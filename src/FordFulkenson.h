#ifndef FORD_FULKENSON
#define FORD_FULKENSON

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 10000000

namespace algorithms {

    /*
        BFS para encontrar augmenting paths
        Complejidad: O(e), donde e = número de edges
    */
    int bfs(int s, int t, vi & parent, vector<vii> & graph, vector<vi> & capacity) {
        fill(parent.begin(), parent.end(), -1);
        parent[s] = -2;
        queue<pair<int, int>> q;
        q.push({s, INF});

        while (!q.empty()) {
            int cur = q.front().first;
            int flow = q.front().second;
            q.pop();

            for (ii next : graph[cur]) {
                if (parent[next.first] == -1 && capacity[cur][next.first]) {
                    parent[next.first] = cur;
                    int new_flow = min(flow, capacity[cur][next.first]);
                    if (next.first == t)
                        return new_flow;
                    q.push({next.first, new_flow});
                }
            }
        }

        return 0;
    }

    /*
        Complejidad: O(fe), donde f = max flow y e = número de edges
    */
    int maxflow(int s, int t, vector<vii> & graph, vector<vi> & capacity) {
        int flow = 0;
        vi parent(graph.size());
        int new_flow;

        while ((new_flow = bfs(s, t, parent, graph, capacity))) {
            flow += new_flow;
            int cur = t;
            while (cur != s) {
                int prev = parent[cur];
                capacity[prev][cur] -= new_flow;
                capacity[cur][prev] += new_flow;
                cur = prev;
            }
        }
        return flow;
    }
}

#endif
