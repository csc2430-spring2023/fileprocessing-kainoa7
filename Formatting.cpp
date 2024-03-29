// Title: Lab 1 - Formatting.cpp
//
// Purpose: **Format from json to csv format. also, finding just the age of individual in the GetAge function.
//
// Class: CSC 2430 Winter 2022
// Author: **Kainoa Aqui

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

string header = "firstName, lastName, Age, Height, Nationality"; //json format
    return header;
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
            }}}

    if (!foundFirst) {
        firstName = "";
    }
    //*above code: this finds the first name and stores it into a string. returns blank if not found.

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
            }}}

    if (!foundLast) {
        lastName = "";
    }

    // *above code: finding person's last name if they have one and putting it into a string. blank if it doesn't exist.

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
            }}}

    if (!foundAge) {
        age = "";
    }
    // *above code: finds persons age if they have on and puts it into a string and blank if not

    string heightNum = "Height";
    size_t foundHeight = json.find(heightNum);


    if (foundHeight!=std::string::npos) {
        for (int i = foundHeight + 8; i < length; i++){
            if (!isdigit(json.at(i)) && json.at(i) != ',') {
                continue;
            }

            else if (isdigit(json.at(i))) {
                height += json.at(i);
            }

            else {
                break;
            }}}

    if (!foundHeight) {
        height = "";
    }

    // *above code: finds height and puts it into a string. string is blank if height doesn't exist.

    string nationalityName = "Nationality";
    size_t foundNationality = json.find(nationalityName);


    if (foundNationality!=std::string::npos) {
        for (int i = foundNationality + 14; i < length; i++){
            if (!isalpha(json.at(i)) && json.at(i) != '"') {
                continue;
            }

            else if (isalpha(json.at(i))) {
                nationality += json.at(i);
            }

            else {
                break;
            }}}

    if (!foundNationality) {
        nationality = "";
    }

    // *above code: finds nationality and puts it into a string. string is blank if nationality doesn't exist.

    format = firstName + comma + lastName + comma + age + comma + height + comma + nationality;

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
        for (int i = found + 5; i < length; i++){
            if (!isdigit(json.at(i)) && json.at(i) != ',') {
                continue;
            }

            else if (isdigit(json.at(i))) {
                personAge += json.at(i);
            }

            else {
                break;
            }}}

    return personAge;
}
// above code starts at the index where Age is found and adds 5 to it where the age begins. the code loops, storing
// --> the integer values and breaks once it reaches a comma
