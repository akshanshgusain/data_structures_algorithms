//
// Created by Akshansh Gusain on 05/06/21.
//
#include<stdc++.h>
using namespace std;

//All power of two numbers has only a one-bit set.
// So count the no. of set bits and if you get 1 then the number is a power of 2

int countBits(int n){
    int count =0;
    while(n){
        n &= (n-1);
        count++;
    }
    return count;
}

int main(){
    if(countBits(9) == 1){
        cout<<"YES";
    }else{
        cout<<"NO";
    }
    return 0;
}

