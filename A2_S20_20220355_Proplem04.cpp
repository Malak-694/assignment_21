// File: A2_S20_20220355_problem04.cpp
// Purpose: generate a list of the primes
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
int main() {
    int n;
    cout << "if you want to generate a list of the primes between 2 and a given number ( Sieve of Eratosthenes ) "
         << endl<< " plase Enter the number : "<<endl;
// take the input from user and define two container
    cin >> n;
    deque<int> v ;
    deque<int> v2;
    // store number from i to n in v
    for (int i = 0; i <= n; i++)
        v.push_back(i);
//iterative loop on the numbers
    for (deque <int> :: iterator it =v.begin();it != v.end(); it ++){
        // if the num is not = 2 , 3 /  and num % (2 , 3 ) == 0 do nothing
        if ( ( *it != 2 && *it != 3) && ( *it % 2 == 0 || *it % 3 == 0) )
            continue;
        // otherwise v2.push_back(*it)
        v2.push_back(*it);
    }
    cout << " Sieve of Eratosthenes is : ";
    //print the number except 1 .
    for ( auto i : v2 ){
        if (i==1)
            continue;
        cout << i << " ";
    }}
