#include <cassert>
#include <iostream>
#include <fstream>
#include <catch2/catch_test_macros.hpp>

using namespace std;

TEST_CASE("Main Functionality") {
    // Paths to executable and files
    const string executable = "./Evidencia2";
    const string tempOutputFile = "temp_output.txt";
    const string expectedOutputFile = "expected_output.txt";
    const string inputFile = "../src/in.txt";

    // Run the executable and redirect output to a temporary file
    const string command = executable + " < " + inputFile + " > " + tempOutputFile;
    REQUIRE(system(command.c_str()) == 0);

    // // Read the temporary output file
    ifstream tempFile(tempOutputFile);
    REQUIRE(tempFile.is_open());
    string tempOutput((istreambuf_iterator<char>(tempFile)),
                            istreambuf_iterator<char>());

    // // Read the expected output file
    ifstream expectedFile(expectedOutputFile);
    REQUIRE(expectedFile.is_open());
    string expectedOutput((istreambuf_iterator<char>(expectedFile)),
                                istreambuf_iterator<char>());
    
    cout << "Temp Output: " << tempOutput << endl;
    // Compare the two outputs
    REQUIRE(tempOutput == expectedOutput);

    // Clean up
    std::remove(tempOutputFile.c_str());
}