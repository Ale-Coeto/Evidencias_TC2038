#ifndef algorithms_
#define algorithms_

#include "FileReader.h"
#include <iostream>
#include <vector>

using namespace std;

namespace algorithms {
    
    // Given a string s, return the indices correspoding to the longest substring within the first string provided
    pair<int, int> longestSubstring(string s1, string s2){
        vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1, 0));
        int maxLen = 0;
        pair<int, int> ans = {0, 0};

        for(int i = 0; i < s1.size(); i++){
            for(int j = 0; j < s2.size(); j++){
                if(s1[i] == s2[j]){
                    dp[i + 1][j + 1] = dp[i][j] + 1;
                    if(dp[i + 1][j + 1] > maxLen){
                        maxLen = dp[i + 1][j + 1];
                        ans = {i - maxLen + 1, i};
                    }
                }
            }
        }

        // 1-indexed
        return {ans.first + 1, ans.second + 1};
    }
};

int main() { 
    string test = FileReader::readFile("transmission1.txt");
    string test2 = FileReader::readFile("transmission2.txt");
    
    pair<int, int> indices = algorithms::longestSubstring(test, test2);

    cout << indices.first << " " << indices.second << " " << test.substr(indices.first - 1, indices.second - indices.first + 1) << endl;

    return 0;
}
#endif