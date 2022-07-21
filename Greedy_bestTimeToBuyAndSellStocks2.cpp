//
// Created by Akshansh Gusain on 22/03/21.
/*
 * In a stock market, there is a product with its infinite stocks. The stock prices are given for N days,
 * where arr[i] denotes the price of the stock on the ith day. There is a rule that a customer can buy at
 * most i stock on the ith day. If the customer has an amount of k amount of money initially, find out the
 * maximum number of stocks a customer can buy.
 * */

#include<stdc++.h>
using namespace std;

int buyMaximumProducts(int n, int k, int price[]){
   vector<pair<int, int>> v;

   //making pair of product cost on nth day and nth day
   for(int i= 0; i<n ;i++){
       v.push_back(make_pair(price[i], i+1));
   }
   //Sort the given vector
   sort(v.begin(), v.end());

   int ans =0;
   for(int i=0; i<n; i++){
       ans += min(v[i].second, k/v[i].first);
       k -= v[i].first * min(v[i].second, k/v[i].first);
   }
   return ans;
}

int main(){
    int price[] = { 10, 7, 19 };
    int n = sizeof(price)/sizeof(price[0]);
    int k = 45;

    cout << buyMaximumProducts(n, k, price) << endl;
    return 0;
}
