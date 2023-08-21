//
// Created by Akshansh Gusain on 05/07/21.
//
// Max difference between 2 elements
#include<stdc++.h>
using namespace std;
// If you have to sell on ith day, then you will have to buy when stock price is lowest between 0 to n-1 days.

int maxProfit(int prices[], int n){
    int maProfit = 0;
    int min_price = prices[0];

    if(n == 0){
        return 0;
    }

    for(int i=0; i<n; i++){
        min_price = min(min_price, prices[i]);
        maProfit = max(maProfit, prices[i] - min_price);
    }

    return maProfit;
}
int main(){
    int prices[] = { 7, 1, 5, 3, 6, 4 };
    int N = sizeof(prices) / sizeof(prices[0]);

    cout << maxProfit(prices, N);
    return 0;
}
