// Title: Lab 1 - Formatting.cpp
//
// Purpose: **<state your purpose here>
//
// Class: CSC 2430 Winter 2022
// Author: **<your name goes here>

#include <cassert>

#include "Formatting.h"
#include <iostream>
using std :: cout;
using std :: string;
using std:: cout;
using std:: cin;
using std :: endl;

// Returns CSV header as a string
//
// Parameters:
//      None
// Returns:
//      CSV header
string CSVHeader() {


    return "firstName, lastName, Age, Height, Nationality";
}

// Converts one JSON formatted line to CSV, returning the CSV
// representation as a string
//
// Parameters:
//      json - JSON formatted line
// Returns:
//      CSV formatted line
string FormatAsCSV(string json) {


    string firstName;
    string lastName;
    string age;
    string nationality;
    string comma = ",";
    string format;

    string fName = "FirstName";

    int length = json.length();
    size_t found = json.find(fName);

    if (found!=std::string::npos) {
        for (int i = found + 12; i < length; i++){
            if (!isalpha(json.at(i)) && json.at(i) != '"') {
                continue;
            }

            else if (isalpha(json.at(i))) {

                firstName += json.at(i);

            }
            else {
                break;
            }
        }
    }

    if (!found) {
        firstName = " ";
    }

// Pick up from here: do the same thing for lastName, age, and nationality as I did for the code above

    format = firstName + comma + lastName + comma + age + comma + nationality;

    return format;
}

// Return the age value stored in a JSON
// formatted line.  The return value is a string
// If age doesn't appear, returns empty string
//
// Parameters:
//      json - JSON formatted line
// Returns:
//      age as string, or empty if age doesn't appear
string GetAge(string json) {


    string age = "Age";
    string personAge;


    int length = json.length();
    size_t found = json.find(age);


    if (found!=std::string::npos) {
        for (int i = found; i < length; i++){
            if (!isdigit(json.at(i)) && json.at(i) != ' ') {
                continue;

            }

            else if (isdigit(json.at(i))) {

                personAge += json.at(i);


            }

            else {
                break;
            }

        }

    }

    return personAge;
}
