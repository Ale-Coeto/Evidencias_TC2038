#ifndef LCS_
#define LCS_

#include "FileReader.h"
#include <iostream>
#include <vector>

using namespace std;

namespace algorithms
{

    // Given a string s, return the indices correspoding to the longest substring within the first string provided
    pair<int, int> longestCommonSubstring(string s1, string s2)
    {
        vector<int> dp(s2.size() + 1, 0);
        int maxLen = 0;
        pair<int, int> ans = {-1, -1};

        for (int i = 0; i < s1.size(); i++)
        {
            vector<int> nextRow(s2.size() + 1, 0);
            for (int j = 0; j < s2.size(); j++)
            {
                if (s1[i] == s2[j])
                {
                    nextRow[j + 1] = dp[j] + 1;
                    if (nextRow[j + 1] > maxLen)
                    {
                        maxLen = nextRow[j + 1];
                        ans = {i - maxLen + 1, i};
                    }
                }
            }
            dp = nextRow;
        }

        if (ans.first == -1 || ans.second == -1)
            throw std::invalid_argument("No se encontró un substring común");

        // 1-indexed
        return {ans.first + 1, ans.second + 1};
    }
};

namespace test
{
    void lcs_test()
    {
        string test = FileReader::readFile("transmission1.txt");
        string test2 = FileReader::readFile("transmission2.txt");

        pair<int, int> indices = algorithms::longestCommonSubstring(test, test2);

        cout << indices.first << " " << indices.second << " " << test.substr(indices.first - 1, indices.second - indices.first + 1) << endl;
    }
}

#endif