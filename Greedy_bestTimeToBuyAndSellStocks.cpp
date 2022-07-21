//
// Created by Akshansh Gusain on 22/03/21.


// 1. Valley Approach

#include<stdc++.h>
using namespace std;

int buyMaximumProducts(int n, const int price[]){
    int diff =0;
    for(int i = 1; i<n ; i++){
        if(price[i]> price[i-1]){
            diff += price[i]-price[i-1];
        }
    }
    return diff;
}

int main(){
    int price[] = { 7,1,5,3,6,4 };
    int n = sizeof(price)/sizeof(price[0]);

    cout << buyMaximumProducts(n, price) << endl;
    return 0;
}
