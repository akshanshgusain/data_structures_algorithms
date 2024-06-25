//
// Created by Akshansh Gusain on 13/01/22.
//
#include<stdc++.h>
using namespace std;

int maxProfit(vector<int> arr, int fee) {
    int oldBuyStateProfit = -arr[0];
    int oldSellStateProfit = 0;

    for(int i = 1; i < arr.size(); i++){
        int newBuyStateProfit = 0;
        int newSellStateProfit = 0;

        if(oldSellStateProfit - arr[i] > oldBuyStateProfit){
            newBuyStateProfit = oldBuyStateProfit - arr[i];
        }else{
            newBuyStateProfit = oldBuyStateProfit;
        }

        if(oldBuyStateProfit + arr[i] - fee > oldSellStateProfit){
            newSellStateProfit = oldBuyStateProfit + arr[i] - fee;
        }else{
            newSellStateProfit = oldSellStateProfit;
        }

        oldBuyStateProfit = newBuyStateProfit;
        oldSellStateProfit = newSellStateProfit;
    }

    return oldSellStateProfit;
}

int main(){
    vector<int> arr = {10, 20, 30};
    int fee = 2;
    cout << maxProfit(arr, fee);
    return 0;
}
