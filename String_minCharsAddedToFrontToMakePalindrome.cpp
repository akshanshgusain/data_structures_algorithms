//
// Created by Akshansh Gusain on 30/01/21.
//
#include<stdc++.h>
using namespace std;

// DP Approach for finding Longest-Palindromic-SubString
vector<int> computerLPSArray(string str){
    int M = str.length();
    vector<int> lps(M);

    int len = 0;
    lps[0] =0; // lps oof zero is always zero
    int i=1;
    while(i<M){
            if(str[i] == str[len]){
                len++;
                lps[i] = len;
                i++;
            }else{
                if(len != 0 ){
                    len = lps[len-1];
                }else{
                    lps[i] = 0;
                    i++;
                }
            }
    }
    return lps;
}

int getMinCharToMakeStringPalindrome(string str){
    string revStr = str;
    reverse(revStr.begin(), revStr.end());


    string concat = str + "$" + revStr;
    vector<int> lps = computerLPSArray(concat);

    return(str.length() - lps.back());
}

int main(){
    string str= "AACECAAAA";
    cout<<getMinCharToMakeStringPalindrome(str);
    return 0;
}