//
// Created by Akshansh Gusain on 22/01/21.
//
//https://leetcode.com/problems/longest-common-prefix/
#include<stdc++.h>
using namespace std;

string longestCommonPrefix(string str[], int n){

    if(n<1){
        return "Null";
    }
    string s = str[0];

    //find the longest common prefix of all string
    for(int i=1;i<n;i++){
         int j=0;

         //compare the chars in the string to get the common prefix
         while( s[j] == str[i][j] && j < s.length() && j < str[i].length()){
             j++;
         }

         //Update the prefix
         s = s.substr(0, j);
    }
    return s;
}

int main(){
    string names[] = {"flower", "flow","flight"};
    cout<<longestCommonPrefix(names, 3)<<endl;
    return 0;
}
