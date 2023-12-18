// File: A2_S20_20220355_problem01.cpp
// Purpose: Handling a sentence
// Author: Nadra Mahmoud Saad
// Section: S20
// ID: 20220355
// TA: Mohamed Talat
// Date: 5 Nov 2023
#include <iostream>
#include<cstring>
#include <vector>
#include <deque>
using namespace std;
int main (){
    //define 2 char array to take input and output
    char input[100];
    char output[100];
    cout << " enter your string :" << endl;
    //take from the user a sentence till " . "
    string s;
    getline(cin, s ,'.');
    // set the string length
    int len = s.length(),
    //c is the variable that increment in output loop
    c = 0;
    // (strcpy) is a function that take from string s to the array input
    strcpy(input, s.c_str());
    // this loop  handling tne sentence
    for (int i = 0; i < len; i++) {
        // this condition handling tne spaces in the sentence
        if (input[i] == ' ' && input[i + 1] == ' ')
            continue;
        // this condition handling tne upperbound in the sentence
        if(input[i]>=65 && input[i]<=90){
            output[c]= input[i]+32;
            c++;
        }
        //otherwise output[c] = input[i]
        else {
            output[c] = input[i];
            c++;
        }

    }
    // make the first letter capital
    output[0] -= 32;
    cout<<" Your Output string is :"<<endl;
    cout<<endl;
    //print the handling sentence
    for(int w=0 ;w<c;w++){

        cout<<output[w];
        if ( w==c-1 )
            cout<<'.';
    }


}
