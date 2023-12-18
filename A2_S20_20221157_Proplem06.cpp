
// File: A2_S20_20221157_Proplem06.cpp
// Purpose: question 6 ,task 1
// Author: Malak Ahmed
// Section: 20
// ID: 20221157
// TA: Mohamed Talaat
// Date: 20 Oct 2023
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
static void binaryPrint (int n){
    if (n==0) {
        //if the final digit resulting from dividing =0 dont print it to not get leading zero;
        return ;
    }
    // Recursive call
    binaryPrint(n / 2); //cout the moduls of the digit after dividing the digit by 2;
    cout << n % 2;
}
static void numbers(string prefix, int k){
    int y=pow(2,k); //the range of numbers
    int power=0;
    for(int i=0;i<y;i++){
        if(pow(2,power)==i){
            //if the log2(number) is a pure number then , it will take another digit to be represented
            // so ,I want to reduce the number of zeros by 1
            k-=1;
            power++;
            //if(k<=0) the for loop wont work
        }
        cout<<prefix;
        for(int j=0;j<k;j++) {
            cout<<"0";
        }
        binaryPrint(i);
        cout<<"\n";

    }

}
int main(){
    binaryPrint(5);
    cout<<"\n";
    numbers("001",4);
}