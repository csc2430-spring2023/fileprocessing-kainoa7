// Title: Lab 1 - FileProcessing.cpp
//
// Purpose: **<state your purpose here>
//
// Class: CSC 2430 Winter 2022
// Author: **<your name goes here>

#include <cassert>
#include "Formatting.h"
#include "FileProcessing.h"
#include <string>
#include <iostream>
#include <fstream>
using std :: string;
using std:: cout;
using std:: cin;
using std :: endl;
using std :: ifstream;
using std :: ofstream;

// Operates in a loop so multiple files can be processed.
// On each iteration, reads name of input and output files from user and opens them
// Then calls ProcessFile to do the actual file processing
// - If user enters a blank line for the input file, loop ends
// - If either file cannot be opened, loop restarts
//
// Parameters:
//      none
// Returns:
//      nothing

void ProcessFile(string inputFileName, string outputFileName);

void ProcessFiles() {
    string inputFileName;
    string outputFileName;
    bool inputDone = false;

    while (!inputDone) {
        cout << "Enter input file name or blank to quit: ";
        getline(cin, inputFileName);
        if (inputFileName == "") {
            inputDone = true;
            break;
        }

        cout << endl;

        cout << "Enter output file name: "  ;
        getline(cin, outputFileName);

        ifstream inputFile(inputFileName);

        if (!inputFile.is_open()) {

            cout << "Could not open file: " << inputFileName;
            continue;

        }

        ofstream outputFile(outputFileName);
        if (!outputFile.is_open()) {
            cout << "Could not open file: " << outputFileName;
            continue;
        }




    }





}

void ProcessFile(string inputFileName, string outputFileName);

