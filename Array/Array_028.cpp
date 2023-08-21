//
// Created by Akshansh Gusain on 12/07/21.
//

#include<stdc++.h>
using namespace std;

//tut: https://www.youtube.com/watch?v=K8iHi8AW1ls&t=387s
// Best time to buy and sell stock 2 (Any # of transactions) - leetcode
// Valley Peek approach

int solve(vector<int> prices){
    int n = prices.size();
    int diff = 0;

    for(int i =1; i < n; i++){
        if(prices[i] > prices[i -1]){
            diff += prices[i] - prices[i-1];
        }
    }

    return diff;
}

int main(){
    vector<int> prices = { 100, 180, 260, 310, 40, 535, 695 };
    cout<<solve(prices);
    return 0;
}