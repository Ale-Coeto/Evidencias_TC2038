
/*
 * Oscar Arreola (A01178076), Mariana Amy Martínez (A00836245) y Alejandra Coeto (A01285221)
 * Última modificación: Domingo 29 de Noviembre
 */

#include <iostream>
#include <vector>
#include "FordFulkenson.h"
#include "Kruskal.h"
#include "TSP.h"
#include "LinearSearch.h"
 
using namespace std;

#define pb push_back

void call_kruskal(int & n, vector<Edge> & edges) {
    cout << "1. Kruskal: " << endl;
    for (pair<int,int> i : algorithms::kruskal(n, edges)){
        char ac = i.first + 'A';
        char bc = i.second + 'A';
        cout << '(' << ac << ", " << bc << ')' << endl;
    }
}

void call_tsp(vector<vector<int>> & cost) {
    cout << "\n2. TSP: " << endl;
    vector<char> path = algorithms::shortest_route(cost);
    for (auto stop : path) {
        cout << stop << " ";
    }
    cout << "\n";
}

void call_maxflow(int & n, vector<vector<pair<int,int>>> & graph, vector<vector<int>> & capacity) {
    cout << "\n3. Max Flow: \n";
    cout << algorithms::maxflow(0, n-1, graph, capacity) << endl;
}

void call_central(int & n) {
    int a, b;
    char x;
    cout << "\n4. Closest Central: " << endl;
    vector<pair<int, int> > centrals;
    
    for (int i = 0; i < n; i++) {
        cin >> x >> a >> x >> b >> x;
        centrals.pb({a,b});
    }

    pair<int,int> target;
    cin >> x >> target.first >> x >> target.second >> x;
    vector<pair<int, int> > res = algorithms::closest_central(centrals, target);

    for (auto x : res)
    {
        cout << "(" << x.first << ", " << x.second << ")\n";
    }
}

int main() {
    int n, a, b;
    cin >> n;
    vector<vector<pair<int,int>>> graph(n);
    vector<vector<int>> cost(n, vector<int>(n, 0));
    vector<vector<int>> capacity(n, vector<int>(n, 0));
    vector<Edge> edges;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a;
            if(i != j && a > 0) 
                graph[i].pb({j, a});
            if (i > j ) {
                edges.pb(Edge(i, j, a));
            }
            cost[i][j] = a;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a;
            capacity[i][j] = a;
        }
    }

    call_kruskal(n, edges);
    call_tsp(cost);
    call_maxflow(n, graph, capacity);
    call_central(n);
    
    return 0;
}
