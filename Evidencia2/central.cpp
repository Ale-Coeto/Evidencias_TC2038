#include "libs.h"
using namespace std;

namespace algorithms
{
    double computeDistance(pair<int, int> p1, pair<int, int> p2)
    {
        return sqrt(pow(p1.first - p2.first, 2.0) + pow(p1.second - p2.second, 2.0));
    }

    pair<int, int> closestCentral(vector<pair<int, int> > centrals, pair<int, int> newCentral)
    {
        if (centrals.size() == 0)
        {
            cout << "Error: No centrls provided, returning location of new service.\n";
            return newCentral;
        }

        pair<int, int> closest = centrals[0];
        double minDiff = computeDistance(newCentral, closest);

        for (int i = 1; i < centrals.size(); i++)
        {
            double distance = computeDistance(centrals[i], newCentral);
            if (distance < minDiff)
            {
                closest = centrals[i];
                minDiff = distance;
            }
        }

        return closest;
    }
}

int main()
{
    vector<pair<int, int> > centrals{{200, 500}, {300, 100}, {450, 150}, {520, 480}};
    pair<int, int> target{400, 300};

    pair<int, int> res = algorithms::closestCentral(centrals, target);

    cout << "(" << res.first << ", " << res.second << ")\n";
    return 0;
}
