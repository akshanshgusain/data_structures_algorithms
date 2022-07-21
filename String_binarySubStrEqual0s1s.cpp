//
// Created by Akshansh Gusain on 20/01/21.
//
//Split the binary string into substrings with equal number of 0s and 1s
#include<stdc++.h>
using namespace std;

int maxSubStr(string str, int n){

    int count0 = 0, count1 = 0;

    int countMax=0;
    int start = 0;
    for(int i=0;i<n;i++){

         if(str[i]=='0'){
             count0++;
         }else{
             count1++;
         }
         if(count0 == count1){
             cout<<str.substr(start, i+1)<<endl;
             countMax++;
             start = i+1;
         }
    }
    if(countMax > 0){
        return countMax;
    }else{
        return -1;
    }
}

int main(){
    string str = "0100110101";
    cout<<maxSubStr(str, str.length())<<endl;
    return 0;
}
