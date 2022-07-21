//
// Created by Akshansh Gusain on 12/07/21.
//
#include<stdc++.h>
using namespace std;
#define MAX 500


int multiply(int x, int res[], int res_size){
    int carry = 0;

    for(int i =0; i<res_size ; i++){
        int prod = res[i] * x + carry;

        res[i] = prod%10;

        carry  = prod/10;
    }

    while(carry){
        res[res_size] = carry%10;
        carry = carry/10;
        res_size++;
    }

    return res_size;
}

int factorial(int num){
    int res[MAX];

    res[0] = 1;
    int res_size = 1;
    for(int i =1; i <= num; i++){
        res[i] = multiply(i, res, res_size);
    }

    for(int i = res_size -1 ; i >=0 ;  i++){
        cout<<res[i];
    }
}

int main(){
    factorial(100);
    return 0;
}
