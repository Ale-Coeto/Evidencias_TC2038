// Oscar Arreola (A01178076), Mariana Amy Martínez (A00836245) y Alejandra Coeto (A01285221)
// Última modificación: Martes 1 de Octubre
// Programa para leer archivos de transmisión y comprobar que no contengan código malicioso,
// revisar similitud y comprobar palíndromos

#include <iostream>
#include "FileReader.h"
#include "Kmp.h"
#include "Lcs.h"
#include "longest_palindrome.h"

using namespace std;

void containedText(vector<string> & transmissions, vector<string> & mcodes) {
    vector<vector<int> > mcodesPre;
    
    for (int i = 0; i < 3; i++) {
        mcodesPre.push_back(KMP::preprocess(mcodes[i]));
    }
  
    for (auto transmission : transmissions) {
        for (int i = 0; i < mcodes.size(); i++) {
            vector<int> result = KMP::containsText(transmission,mcodes[i],mcodesPre[i]);

            if (result.size() <= 0) {
                cout << "False" << endl;
            } else {
                cout << "True ";
                for (auto i : result) {
                    cout << i << " ";
                }
                cout << endl;
            }
        }
    }
}

int main() { 
    // Read input
    string transmission1 = FileReader::readFile("txts/transmission1.txt");
    string transmission2 = FileReader::readFile("txts/transmission2.txt");
    vector<string> transmissions = { transmission1, transmission2 };
    
    string mcode1 = FileReader::readFile("txts/mcode1.txt");
    string mcode2 = FileReader::readFile("txts/mcode2.txt");
    string mcode3 = FileReader::readFile("txts/mcode3.txt");
    vector<string> mcodes = { mcode1, mcode2, mcode3 };


    // Check if mcode is contained in transmission files

    // Palindrome

    // Parte 3. Analizar que tan similares son los archivos de transmisión. Encontrar substring comun más largo.
    // LCS
    try
    {
        pair<int, int> indices = algorithms::longestCommonSubstring("a", "b");
        string t = "a";
        cout << indices.first << " " << indices.second << " " << t.substr(indices.first - 1, indices.second - indices.first + 1) << endl;
    }
    catch (exception e)
    {
        cout << e.what() << endl;
    }

    return 0;
}