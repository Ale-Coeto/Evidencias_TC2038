#include <iostream>
#include "FileReader.h"

using namespace std;

int main() { 
    string test = FileReader::readFile("transmission1.txt");
    cout << test << endl; 
    return 0;
}