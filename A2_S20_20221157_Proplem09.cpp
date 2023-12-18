
// File: A2_S20_20221157_Proplem09.cpp
// Purpose: question 9 ,task 1
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
static bool teddybear(int n) {
    vector< bool > static visited(n+1 , false);
    //my algorithm is to check every possible solution of the possible solutions
    if(n==42) return true;
    else if(n<42 || visited[n]) return false;
    else{
        if(n%2==0){
            return teddybear(n/2);
        }
        if(n%3==0||n%4==0){
            return teddybear((n%10)*(n%100));
        }
        if(n%5==0) return teddybear(42);
        if(n%2!=0&&n%3!=0&&n%4!=0&&n%5!=0) return false;
    }
}
int main() {
    cout<<"inter the number you want to try on: ";
    int n;
    cin>>n;
    if(teddybear(n)) cout<<"true";
    else cout<<"false";

}