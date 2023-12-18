// File:A2_S19_20221073_problemNum_11.cpp
// Purpose:File Comparison(character by character)OR(word by word)
// Author :Salma Gamal Kamel Mohamed Radwan.
// Section:S19.
// ID:20221073.
// TA:Mohamed Talet.
// Date: 5 Nov 2023.
//  Q.11
#include <bits/stdc++.h>
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
using namespace std;
bool Compare_characterBycharacter(ifstream &file1, ifstream &file2)
{
    char ch1, ch2;
    int lineCount =1 ,charCount =0;
    while(file1.get(ch1)&&file2.get(ch2))
    {
        charCount++;
        // Compare characters from the two files.
        if(ch1 != ch2)
        {
            cout<<"Files are different at line :"<<lineCount<<", character "<<charCount<<"\n";
            return false;
        }

        if(ch1=='\n')
        {
            // Newline ,move to the next line.
            lineCount++;
            charCount =0;
        }
    }
    //Check if both files reached the end of file.
    if(file1.eof()&&file2.eof())
    {
        cout<<"Files have idential ."<<endl;
        return true;
    }
    else
    {
        cout<<"Files have different lengths."<<endl;
        return false;
    }
}

bool Compare_wordByword(ifstream &file1, ifstream &file2)
{
  string word1,word2;
  int lineCount =1;
  while (file1>>word1 && file2>>word2)
  {
    if(word1!=word2)
    {
        cout<<"Files are different at line "<<lineCount<<", word"<<word1<<"and"<<word2<<"\n";
        return false;
    }
  }

  if(file1.eof()&&file2.eof())
  {
    cout<<"Files are identical."<<endl;
    return true;
  }
  else
  {
    cout<<"Files have different lengths."<<endl;
    return false;
  }
}
int main()
{
     string file_name_1, file_name_2,compareType;
    cout<<"Please,enter the 1st filename :"
        <<endl;
    cin>>file_name_1;
    cout << "Please,enter the 2nd filename :"
         << endl;
    cin >> file_name_2;
    cout<<"Choose the comparison type character OR word :"
        <<endl;
    cin>>compareType;

    ifstream file1(file_name_1);
    ifstream file2(file_name_2);

    //check if files were opened .
    if(!file1 || !file2)
    {
        cout << "Failed to open files.\n";
            return 1;
    }
    if(compareType=="character") Compare_characterBycharacter(file1,file2);
    else if (compareType=="word") Compare_wordByword(file1,file2);
    else  cout<<"Invaild\n";

    //close
    file1.close();
    file2.close();

    return 0;
}