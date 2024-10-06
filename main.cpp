// Oscar Arreola (A01178076), Mariana Amy Martínez (A00836245) y Alejandra Coeto (A01285221)
// Última modificación: Martes 1 de Octubre
// Programa para leer archivos de transmisión y comprobar que no contengan código malicioso, 
// revisar similitud y comprobar palíndromos

#include <iostream>
#include "FileReader.h"
#include "Kmp.h"

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
    containedText(transmissions, mcodes);

    // Palindrome

    // LCS
    
    


    
    

    return 0;
}