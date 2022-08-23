//
// Created by Akshansh Gusain on 23/08/22.
//

#include<bits/stdc++.h>

using namespace std;


int findMaxStocks(vector<int> &stocks, int k) {
    int maxi = INT_MIN;
    int count = 0;
    for(int i= 0; i <  stocks.size(); i++){
        if( (i+1) * stocks[i] <= k){
            count += i+1;
        }else{
            count += k/stocks[i];
        }
        k -= (i+1) * stocks[i];
    }
    return count;
}

int main() {
//    int k = 45;
//    vector<int> stocks = {10, 17,19};

    int k = 100;
    vector<int> stocks = {7, 10, 4};


    cout << findMaxStocks(stocks, k);
    return 0;
}