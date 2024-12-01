
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
  class Edge represents an edge in a graph
 */
struct Edge
{
    int first;  ///< The first element
    int second; ///< The second element
    int weight; ///< The edge weight
    
    /**
     constructor
     */

    Edge(int f, int s, int w)
    {
        this->first = f;
        this->second = s;
        this->weight = w;
    }
};

/**
  Overload the < operator for the Edge class
 */
bool operator<(const Edge &a, const Edge &b)
{
    return a.weight < b.weight;
}

namespace algorithms
{

    /**
        class DSU represents a Disjoint Set Union data structure
     */
    class DSU
    {
        int *parent;
        int *rank;

    public:
        /**
         * Constructor for the DSU class
         */
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

        /**
            Giveen a node, return its group. Use path compression.
         */
        int Find(int i)
        {
            if (parent[i] == -1)
                return i;

            return parent[i] = Find(parent[i]);
        }

        /**
            Given 2 nodes, make them of the same group. Merge by rank.
         */
        void Unite(int x, int y)
        {
            int s1 = Find(x);
            int s2 = Find(y);

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

    /**
        Kruskal's algorithm to find the minimum spanning tree of a graph
        Time complexity: O(E log E)
     */
    vector<pair<int, int> > kruskal(int size, vector<Edge> &edges)
    {
        sort(edges.begin(), edges.end());
        vector<pair<int, int> > answer;
        DSU s(size);
        for (auto edge : edges)
        {
            if (s.Find(edge.first) != s.Find(edge.second))
            {
                s.Unite(edge.first, edge.second);
                answer.push_back(pair(edge.first, edge.second));
            }
        }
        return answer;
    }
}

#endif
