// Oscar Arreola (A01178076), Mariana Amy Martínez (A00836245) y Alejandra Coeto (A01285221)
// Última modificación: Martes 1 de Octubre
// Programa para leer archivos de transmisión y comprobar que no contengan código malicioso, 
// revisar similitud y comprobar palíndromos

#include <iostream>
#include "FileReader.h"
#include "Kmp.h"

using namespace std;

int main() { 
    string test = FileReader::readFile("transmission1.txt");
    string x = "abcdajsjsjsbvbca";
    string pat = "bac";

    vector<int> pre = KMP::preprocess(pat);

    vector<int> result = KMP::containsText(x,pat,pre);

    for (auto i : result) {
        cout << i << " ";
    }
    cout << endl;
    

    return 0;
}