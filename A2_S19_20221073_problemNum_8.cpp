//File   :A2_S19_20221073_problemNum_8.cpp
//Purpose:A fractal pattern .
//Author :Salma Gamal Kamel Mohamed Radwan.
//Section:S19.
//ID     :20221073.
//TA     :Mohamed Talet.
//Date   : 5 Nov 2023.
// Q.8
#include <bits/stdc++.h>
using namespace std;
void Pattern(int n,int i) //n:# of stars.  i:# of spaces.
{
    if(n==1) //The base case
    {
       for(int j=0;j<i;j++)
      {
         cout<<" ";
      }
      cout<<"*"<<"\n";
    }
    else
    {
       Pattern(n/2,i); //print the top half.

         for(int j=0;j<i;j++)
         {
           cout<<" ";
         }
        for(int j=0;j<n;j++)
         {
         cout<<"*";
         }
        cout<<endl;

      Pattern(n/2,i+n/2); //print the bottom half.

    }
  }
    int main()
    {

       int n,i;
       cout<<"Please,enter the number of stars :"<<endl;
       cin>>n;
       cout<<"Please,enter the number of spaces :"<<endl;
       cin>>i;
       Pattern(n,i);
       return 0;

    }




