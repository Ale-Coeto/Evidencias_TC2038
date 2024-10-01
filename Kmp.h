#ifndef KMP_
#define KMP_

#include <iostream>

using namespace std;

class KMP {
    public:
        /*
            KMP algorithm to check if a text is contained in anotherone
            Params: text (string that could contain other text)
                    lps (vector of the string that could be contained on text)
            Returns: vector (positions where the string is contained int text)
        */ 
        static vector<int> containsText(string & text, vector<int> & lps) {
            return vector<int> ();
        }

        /* 
            Algorithm to obtain the longest proper prefix vector
            Params: text (string to be preprocessed)
            Return: vector (vector with longest prefix values)
        */
        static vector<int> preprocess(string text) {
            vector<int> lps(text.size(), 0);
            int j = 0;

            for (int i = 1; i < text.size(); i++) {
                if (text[i] == text[j]) {
                    lps[i] = ++j;
                } else if (j > 0) {
                    j = lps[j-1];
                    i--;
                }
            }

            for (int i = 0; i < text.size(); i++) {
                cout << text[i] << " " << lps[i] << endl;
            }
            cout << "END \n";

            return lps;
        }
    
        
};

#endif //KMP