/*
 * Oscar Arreola (A01178076), Mariana Amy Martínez (A00836245) y Alejandra Coeto (A01285221)
 * Última modificación: Domingo 29 de Noviembre
 */

#include <iostream>
#include <vector>
#include "FordFulkenson.h"
#include "Kruskal.h"
 
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define pb push_back

int main() {
    int n, a, b;
    cin >> n;
    vector<vii> graph(n);
    vector<vi> capacity(n, vi(n, 0));
    vector<edge> edges;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a;
            if(i != j && a > 0) 
                graph[i].pb({j, a});
            if (i > j ){
                edges.pb(edge(i, j, a));
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a;
            capacity[i][j] = a;
        }
    }

    cout << "1. Kruskal: " << endl;
    for (ii i : algorithms::kruskal(n, edges)){
        cout << i.first << " " << i.second << endl;
    }

    cout << "3. Max Flow: ";
    cout << algorithms::maxflow(0, n-1, graph, capacity) << endl;
    
    return 0;
}
