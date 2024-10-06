// Oscar Arreola (A01178076), Mariana Amy Martínez (A00836245) y Alejandra Coeto (A01285221)
// Última modificación: Domingo 6 de Octubre
// Programa para leer archivos de transmisión y comprobar que no contengan código malicioso,
// revisar similitud y comprobar palíndromos

// Las explicaciones de la complejidad temporal vienen en cada una de las implementaciones de los algoritmos

#include <iostream>
#include "FileReader.h"
#include "Kmp.h"
#include "Lcs.h"
#include "longest_palindrome.h"

using namespace std;

void containedText(vector<string> &transmissions, vector<string> &mcodes)
{
    vector<vector<int> > mcodesPre;

    for (int i = 0; i < 3; i++)
    {
        mcodesPre.push_back(KMP::preprocess(mcodes[i]));
    }

    for (auto transmission : transmissions)
    {
        for (int i = 0; i < mcodes.size(); i++)
        {
            vector<int> result = KMP::containsText(transmission, mcodes[i], mcodesPre[i]);

            if (result.size() <= 0)
            {
                cout << "false" << endl;
            }
            else
            {
                cout << "true ";
                for (auto i : result)
                {
                    // 1-indexed
                    cout << i + 1 << " ";
                }
                cout << endl;
            }
        }
    }
}

int main()
{
    // Read input
    string transmission1 = FileReader::readFile("transmission1.txt");
    string transmission2 = FileReader::readFile("transmission2.txt");
    vector<string> transmissions = {transmission1, transmission2};

    string mcode1 = FileReader::readFile("mcode1.txt");
    string mcode2 = FileReader::readFile("mcode2.txt");
    string mcode3 = FileReader::readFile("mcode3.txt");
    vector<string> mcodes = {mcode1, mcode2, mcode3};

    // Parte 1. Checar is los archivos de transmisión contienen código malicioso
    cout << "Parte 1:" << endl;
    containedText(transmissions, mcodes);

    // Parte 2. Encontrar el palíndromo más largo en los archivos de transmisión
    // Palindrome
    cout << "Parte 2:" << endl;

    pair<int, int> indices = algorithms::longestPalidrome(transmission1);
    pair<int, int> indices2 = algorithms::longestPalidrome(transmission2);

    cout << indices.first << " " << indices.second << " " << transmission1.substr(indices.first - 1, indices.second - indices.first + 1) << endl;
    cout << indices2.first << " " << indices2.second << " " << transmission2.substr(indices2.first - 1, indices2.second - indices2.first + 1) << endl;

    // Parte 3. Analizar que tan similares son los archivos de transmisión. Encontrar substring comun más largo.
    // LCS
    cout << "Parte 3:" << endl;
    try
    {
        pair<int, int> indices = algorithms::longestCommonSubstring(transmission1, transmission2);
        cout << indices.first << " " << indices.second << " " << transmission1.substr(indices.first - 1, indices.second - indices.first + 1) << endl;
    }
    catch (std::invalid_argument e)
    {
        cout << "Error: " << e.what() << endl;
    }
    catch (exception e)
    {
        cout << "Hubo un error al buscar el substring más largo:" << e.what() << endl;
    }

    return 0;
}