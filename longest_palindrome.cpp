#ifndef palindrome
#define palindrome

#include "FileReader.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace palindrome {
    pair<int, int> longestPalidrome(string s){
        pair <int, int> ans = {0, 0};
        int n = 2 * s.size() + 1; 
        vector<int> lenPalndrm (n, 0);
        lenPalndrm[1] = 1; 
        int centerIndex = 1; 
        int rightIndex = 2; 
        int right = 0, left; 
        int maxPalLength = 0, maxCenterIndex = 0; 
        int start = -1, end = -1, diff = -1; 
        for (right = 2; right < n; right++) {
            left = 2 * centerIndex - right;
            int diff = rightIndex - right; 
            if(diff > 0){
                lenPalndrm[right] = min(lenPalndrm[left], diff);
            }
            while ( ((right + lenPalndrm[right]) < n && (right - lenPalndrm[right]) > 0) &&
                (((right + lenPalndrm[right] + 1) % 2 == 0) || 
                (s[(right + lenPalndrm[right] + 1)/2] == s[(right - lenPalndrm[right] - 1)/2]))) {
                lenPalndrm[right]++;
            }
            if(lenPalndrm[right] > lenPalndrm[maxCenterIndex]) {    
                maxCenterIndex = right;
            }
            if (right + lenPalndrm[right] > rightIndex) {
                centerIndex = right;
                rightIndex = right + lenPalndrm[right];
            }
        }
        ans.first = (maxCenterIndex - lenPalndrm[maxCenterIndex])/2 + 1;
        ans.second = ans.first + lenPalndrm[maxCenterIndex] - 1;
        return ans;
    }
    
};

int main() { 
    string test = FileReader::readFile("transmission1.txt");
    string test2 = FileReader::readFile("transmission2.txt");
    test.erase(std::remove(test.begin(), test.end(), '\n'), test.cend());
    test2.erase(std::remove(test2.begin(), test2.end(), '\n'), test2.cend());
    
    pair<int, int> indices = palindrome::longestPalidrome(test);
    pair<int, int> indices2 = palindrome::longestPalidrome(test2);

    cout << indices.first << " " << indices.second << " " << test.substr(indices.first - 1, indices.second - indices.first + 1) << endl;
    cout << indices2.first << " " << indices2.second << " " << test2.substr(indices2.first - 1, indices2.second - indices2.first + 1) << endl;

    return 0;
}
#endif
