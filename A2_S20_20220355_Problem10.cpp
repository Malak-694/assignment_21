// File: A2_S20_20220355_Problem10.cpp
// Purpose: make a program that replace word with another one
// Author: Nadra Mahmoud Saad
// Section: S20
// ID: 20220355
// TA: Mohamed Talat
// Date: 5 Nov 2023
#include <iostream>
#include <fstream>
#include <map>
#include <string>
using namespace std;
int main() {
    // set a input file and output and lookup table
    const string inputFileName = "input.txt";
    const string outputFileName = "output.txt";
    // the key in the map is the first word in lookup table that I want to replace
    // the value in the map is the second word
    map<string, string> wordReplacements;
    ifstream lookupFile("lookup_table.txt", ios::in);
    // chick if the file is open
    if (!lookupFile.is_open()) {
        cerr << "Failed to open lookup table file 1." << endl;
        return 1;
    }
    //this loop to set each key word (word) to its value(alternative)
    string line;
    while (getline(lookupFile, line)) {
        size_t spacePos = line.find(' ');
        if (spacePos != string::npos) {

            string word = line.substr(0, spacePos);
            string alternative = line.substr(spacePos + 1);
            wordReplacements[word] = alternative;
        }
    }
    // we must close the lookup table file
    lookupFile.close();
    // take from the user the input file name
    ifstream inputFile(inputFileName);
    // chick if the file is open
    if (!inputFile.is_open()) {
        cerr << "Failed to open input file ." << endl;
        return 1;
    } // chick if the file is open
    ofstream outputFile(outputFileName);
    if (!outputFile.is_open()) {
        cerr << "Failed to create output file ." << endl;
        return 1;
    }
    string word;
    // this loop to loop in input and replace the word with its alternative
    while (inputFile >> word) {
        auto it = wordReplacements.find(word);
        if (it != wordReplacements.end()) {
            outputFile << it->second << " ";
        } else {
            outputFile << word << " ";
        }
    }// close the files
    inputFile.close();
    outputFile.close();
    cout << "Message alteration completed. The result is in 'output.txt'." << endl;
    return 0;
}