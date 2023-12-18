// File:// File:A2_S19_20221073_problemNum_2.cpp
// Purpose:Convert from male speech to male and female speech.
// Author :Salma Gamal Kamel Mohamed Radwan.
// Section:S19
// ID:20221073.
// TA:Mohamed Talet.
// Date: 5 Nov 2023.
//  Q.2
#include <bits/stdc++.h>
using namespace std;

void Replace_Pronouns(string& s)
{
    // Array of search words.
    string search_word[] = {"He", "His", "him", "his"};

    // Array of replace words.
    string replace_word[] = {"He or she", "His or her", "him or her", "his or her"};

    // Replace "he" with "he or she"
    size_t o = s.find("he"); // Find the position of the substring "he" in the input string
    if (o != string::npos)
    {
        s.replace(o, string("he").length(), "he or she"); // Replace "he" with "he or she"
    }

    //  Replace other pronouns .
    for (int i = 0; i < 4; i++)
     {
        size_t pos = s.find(search_word[i]); // Find the position of the current search word.
        while (pos != string::npos)
        {
         // While the search word is found in the input string
            s.replace(pos, search_word[i].length(), replace_word[i]);
            pos = s.find(search_word[i], pos + replace_word[i].length()); // Find the next occurrence of the search word
        }
    }
}

int main() {
    string str;
    cout << "Please enter your statement:\n";
    getline(cin, str); // Read the input statement including spaces.

    Replace_Pronouns(str);

    cout << "The statement after modification:\n";
    cout << str;

    return 0;
}

