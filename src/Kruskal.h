
/*
 * Oscar Arreola (A01178076), Mariana Amy Martínez (A00836245) y Alejandra Coeto (A01285221)
 * Última modificación: Domingo 29 de Noviembre
 */
#ifndef KRUSKAL
#define KRUSKAL

#include <iostream>
#include <vector>
#include <algorithm>
#include "libs.h"

using namespace std;
#define INF 10000000

/**
  class Edge

    Used to represent edges in the adjacency graph.

 */
struct Edge
{
    int first;  // The first element
    int second; // The second element
    int weight; // The edge weight
    Edge(int f, int s, int w)
    {
        this->first = f;
        this->second = s;
        this->weight = w;
    }
};

bool operator<(const Edge &a, const Edge &b) {
    return a.weight < b.weight;
}

namespace algorithms
{

    class DSU
    {
        int *parent;
        int *rank;

    public:
        DSU(int n)
        {
            parent = new int[n];
            rank = new int[n];

            for (int i = 0; i < n; i++)
            {
                parent[i] = -1;
                rank[i] = 1;
            }
        }

        // Find function
        int find(int i)
        {
            if (parent[i] == -1)
                return i;

            return parent[i] = find(parent[i]);
        }

        // Union function
        void unite(int x, int y)
        {
            int s1 = find(x);
            int s2 = find(y);

            if (s1 != s2)
            {
                if (rank[s1] < rank[s2])
                {
                    parent[s1] = s2;
                }
                else if (rank[s1] > rank[s2])
                {
                    parent[s2] = s1;
                }
                else
                {
                    parent[s2] = s1;
                    rank[s1] += 1;
                }
            }
        }
    };

    vector<pair<int, int> > kruskal(int size, vector<Edge> &edges)
    {
        sort(edges.begin(), edges.end());
        vector<pair<int, int> > answer;
        DSU s(size);
        for (auto edge : edges)
        {
            if (s.find(edge.first) != s.find(edge.second))
            {
                s.unite(edge.first, edge.second);
                answer.push_back(pair(edge.first, edge.second));
            }
        }
        return answer;
    }
}

#endif
