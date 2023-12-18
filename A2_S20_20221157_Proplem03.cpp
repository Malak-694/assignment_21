
// File: A2_S20_20221157_Proplem03.cpp
// Purpose: question 3 ,task 1
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
vector<string> split(string target, string delimiter);
int main(){
    string target,delimiter;
    cout<<"inter the string you want to split: ";
    getline(cin,target);
    cout<<"inter the delimiter: ";
    getline(cin,delimiter);
    vector v=split(target, delimiter);
    for(int i=0;i<v.size();i++) cout<<v[i]<<"  ";

}
vector<string> split(string target, string delimiter){
    vector <string> v;
    int n = target.size();
    int begin =0;

    for(int i=0 ; i<n; i++){
        string s (1, target[i]);
        if(s==delimiter){

            string cropped = target.substr(begin,i - begin );
            v.push_back(cropped);
            begin = i +1;
        }
        else{
            if(i==n-1){
                string cropped = target.substr(begin,n - begin );
                v.push_back(cropped);
            }
        }

    }
    return v;
}