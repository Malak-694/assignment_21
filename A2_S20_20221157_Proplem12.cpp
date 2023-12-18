
// File: A2_S20_20221157_Proplem12.cpp
// Purpose: question 12 ,task 1
// Author: Malak Ahmed
// Section: 20
// ID: 20221157
// TA: Mohamed Talaat
// Date: 20 Oct 2023
#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <bits/stdc++.h>
#include<iostream>
#include<fstream>
using namespace std;
void phishing() {
    string name;
    cin>>name;
    fstream file;
    string s;
    int sum =0;
    file.open(name.c_str());
    vector<string> v;
    vector<string> word {"account","security","update","verify","urgent", "suspicious","login",
                         "credentials" , "information","confirm" , " access" , "limited","reset",
                         "phishing","scam","fraud","notification", "breach", "assistance", "identity",
                         "validate","offer","blocked","Prize","free",
                         "microsoft","apple","google","paypal","amazon"};
    vector <int> rank {1,3,2,3,3,2,2,3,1,1,2,3,3,3,1,2,1,2,3,2,2,3,2,1,2,3,2,3,2,2};

    while (file>>s){
        //enter the email and make every single word in an index after make it all in lowercases to
        //increase the efficiency of the program
        for (int x=0; x<s.size(); x++)
            s[x]=tolower(s[x]);
        v.push_back(s);
    }
    for(int i=0;i<30 ;i++){
        int n= count(v.begin(),v.end(),word[i]); //count the suspicious words in the email
        if(n>0) cout<<"word: ("<<word[i]<<") number of occurrence: ("<<n<<") total points: ("<<rank[i]*n<<")\n";
        sum+=(rank[i]*n);
    }
    cout<<"total point of phishing : "<<sum;
}
int main() {

    phishing();

}