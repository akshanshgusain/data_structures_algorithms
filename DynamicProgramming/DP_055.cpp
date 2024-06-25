//
// Created by Akshansh Gusain on 30/12/21.
//
#include<stdc++.h>
using namespace std;

int T[100];

int fibo(int n){
    if(n <= 1){
        return n;
    }

    if(T[n] != -1){
        return T[n];
    }

    return T[n] = fibo(n-1) + fibo(n-2);
}
int main(){
    memset(T, -1, sizeof T);
    int n =9;
    cout<< fibo(n);
    return 0;
}
