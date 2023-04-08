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
    string height;
    string nationality;
    string comma = ",";
    string format;

    string fName = "FirstName";

    int length = json.length();
    size_t foundFirst = json.find(fName);

    if (foundFirst!=std::string::npos) {
        for (int i = foundFirst + 12; i < length; i++){
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

    if (!foundFirst) {
        firstName = "";
    } //this finds the first name

// Pick up from here: do the same thing for lastName, age, and nationality as I did for the code above *checkpoint

    string lName = "LastName";
    size_t foundLast = json.find(lName);

    if (foundLast!=std::string::npos) {
        for (int i = foundLast + 11; i < length; i++){
            if (!isalpha(json.at(i)) && json.at(i) != '"') {
                continue;

            }

            else if (isalpha(json.at(i))) {

                lastName += json.at(i);

            }

            else {
                break;
            }

        }

    }

    if (!foundLast) {
        lastName = "";
    }

    // finding person's last name if they have one and putting it into a string. blank if it doesn't exist.

    string ageNum = "Age";
    size_t foundAge = json.find(ageNum);


    if (foundAge!=std::string::npos) {
        for (int i = foundAge; i < length; i++){
            if (!isdigit(json.at(i)) && json.at(i) != ',') {
                continue;

            }

            else if (isdigit(json.at(i))) {

                age += json.at(i);


            }

            else {
                break;
            }

        }


    }

    if (!foundAge) {
        age = "";
    }
    format = firstName + comma + lastName + comma + age + comma + height + comma + nationality;;

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
