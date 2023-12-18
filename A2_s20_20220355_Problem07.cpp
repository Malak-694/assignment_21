// File: A2_s20_20220355_Problem07.cpp
// Purpose:Print the solution of the domino chain
// Author: Nadra Mahmoud saad
// Section: S20
// ID: 20220355
// TA: Mohamed talat
// Date:5 Nov 2023
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct dominos {
    int frist_dots;
    int scand_dots;
};

int x;
vector <dominos> vec , output;
vector <bool> isUsed ;

void solve (vector<dominos> vec , vector <bool> isUsed ,int perlift ,int index)
{
    //(output.size() = x)  that mean the solution is found
    if(output.size() == x)
    {

        for (int i = 0; i < x; ++i) {
            // print the solution
            cout << output[i].frist_dots << '|' << output[i].scand_dots << " - ";

        }
        cout <<'\n';
        return;
    } // protect program from infint loops
    if(index == x)
    {
        return;
    }
    // that is what the solve function if their exist domino not use
    //and make all possible chains
    for (int i = 0; i < x; ++i) {
        if(!isUsed[i]){
            if(perlift == vec[i].frist_dots)
            {
                output.push_back(vec[i]);
                isUsed[i]= true;
                solve(vec ,isUsed ,vec[i].scand_dots,index+1);
                output.pop_back();
                isUsed[i]= false;
            }
        }
    }
    return;
}

void front_domino ()
{
    for (int i = 0; i < x; ++i) {
        //clear the output everytime
        output.clear();
        // isUsed is a vector check if the the piece of domino isUsed or not
        vector isUsed (x+1,false) ;
        // put the piece of domino in the output vector
        output.push_back(vec[i]);
        // then make  isUsed[i] = true , the piece of domino is used
        isUsed[i] = true;
        //call the solve function
        solve(vec , isUsed , vec[i].scand_dots ,0) ;
    }
}

int main() {
    // take the num of the domino from user
    cin >> x;
    int a,b;
    // take the  domino from user and store it in vector
    for (int i = 0; i < x; ++i) {
        cin >> a>>b;
        vec.push_back({a,b});
    }
    // call the function  front_domino .
    front_domino();
    return 0;
}