/*
 * Oscar Arreola (A01178076), Mariana Amy Martínez (A00836245) y Alejandra Coeto (A01285221)
 * Última modificación: Domingo 29 de Noviembre
 */

#include "libs.h"
using namespace std;

namespace algorithms
{
    /**
        Encontrar distancia entre 2 puntos
        Complejidad: O(1)
    */
    double compute_distance(pair<int, int> p1, pair<int, int> p2)
    {
        return sqrt(pow(p1.first - p2.first, 2.0) + pow(p1.second - p2.second, 2.0));
    }

    /**
        Encontrar centrales más cercanas a nuevo servicio
        Complejidad: O(n) -> n es el numero de centrales
    */
    vector<pair<int, int> > closest_central(vector<pair<int, int> > centrals, pair<int, int> newCentral)
    {
        if (centrals.size() == 0)
        {
            cout << "Error: No centrls provided, returning empty.\n";
            return {};
        }

        vector<pair<int, int> > closest = {centrals[0]};
        double minDiff = compute_distance(newCentral, closest[0]);

        for (int i = 1; i < centrals.size(); i++)
        {
            double distance = compute_distance(centrals[i], newCentral);
            if (distance < minDiff)
            {
                closest = {centrals[i]};
                minDiff = distance;
            }
            else if (distance == minDiff)
            {
                closest.push_back(centrals[i]);
            }
        }

        return closest;
    }
}

// int main()
// {
//     vector<pair<int, int> > centrals{{200, 500}, {300, 100}, {450, 150}, {520, 480}};
//     pair<int, int> target{400, 300};

//     vector<pair<int, int> > res = algorithms::closest_central(centrals, target);

//     for (auto x : res)
//     {
//         cout << "(" << x.first << ", " << x.second << ")\n";
//     }
//     return 0;
// }
