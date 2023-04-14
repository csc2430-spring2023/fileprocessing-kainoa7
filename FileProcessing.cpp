// Title: Lab 1 - FileProcessing.cpp
//
// Purpose: **Get the input of json file and output in csv format. finding the minimum, maximum, and average age
//
// Class: CSC 2430 Winter 2022
// Author: **Kainoa Aqui

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

void ProcessFile(ifstream& in,ofstream& out);

void ProcessFiles() {
    string inputFileName;
    string outputFileName;
    bool inputDone = false;

    while (!inputDone) {
        cout << "Input File Name: ";
        getline(cin, inputFileName);
        char period = '.';
        int foundPeriod = inputFileName.find(period);
        string findJson = "json";
        int foundJson = inputFileName.find(findJson);


        if (inputFileName == "") {
            break;
        }

        // breaks if blank entered

        if (foundPeriod == string::npos) {
            cout << "ERROR: " << inputFileName << " not found" << endl;
            continue;
        }

        // error message if no period is found

        if (foundPeriod != string::npos && foundJson == string::npos) {
            cout << "ERROR: Incorrect file format, please provide a JSON file" << endl;
            continue;
        }

        // error if period found but not in json format

        cout << "Output File Name: "  ;
        getline(cin, outputFileName);

        ifstream inputFile(inputFileName);

        if (!inputFile.is_open()) {

            cout << "Could not open file: " << inputFileName;
            cout << endl;
            continue;
            // checks if file exists
        }

        ofstream outputFile(outputFileName);
        if (!outputFile.is_open()) {
            cout << "Could not open file: " << outputFileName;
            cout << endl;
            continue;
        }

        ProcessFile(inputFile, outputFile);

        inputFile.close();
        outputFile.close();

    }

}

void ProcessFile(ifstream& in,ofstream& out) {
    string json;
    int minAge = INT_MAX;
    int maxAge = INT_MIN;
    int ageCount = 0;
    double aveAge;
    double totalAge = 0.0;

    while (getline(in, json)) {

        string personAge = GetAge(json);
        int stringAgeToInt = atoi(personAge.c_str());

        if (stringAgeToInt >= 0) {
            totalAge = totalAge + stringAgeToInt;
            ageCount++; // stores these values to calculate average

            if (stringAgeToInt > maxAge) {
                maxAge = stringAgeToInt;  // finding maximum age
            }

            if (stringAgeToInt < minAge) {
                minAge = stringAgeToInt; // finding minimum age
            }
        }
    }

    in.close();


    aveAge = totalAge / ageCount; // calculates average age

    cout << "Minimum age: " << minAge << endl;
    cout << "Maximum age: " << maxAge << endl;
    cout << "Average age: " << aveAge << endl;

}