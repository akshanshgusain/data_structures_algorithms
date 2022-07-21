//
// Created by Akshansh Gusain on 13/01/22.
//
// https://www.youtube.com/watch?v=3YILP-PdEJA&t=1826s


#include<stdc++.h>

using namespace std;

int maxProfit(vector<int> arr, int k) {
    int n = arr.size();
    int dp[k + 1][n];
    memset(dp, 0, sizeof dp);

    for (int t = 1; t <= k; t++) {
        int max = INT_MIN;

        for (int d = 1; d < n; d++) {


//            for(int pd = 0; pd < d; pd++){
//                int profitTillTM1Tran = dp[t-1][pd];
//                int thProfit = arr[d] - arr[pd];
//
//                if(profitTillTM1Tran + thProfit > max){
//                    max = profitTillTM1Tran + thProfit;
//                }
//            }
//
//            dp[t][d] = max;
            if (dp[t - 1][d - 1] - arr[d - 1] > max) {
                max = dp[t - 1][d - 1] - arr[d - 1];
            }
            if(max + arr[d] > dp[t][d-1]){
                dp[t][d] = max + arr[d];
            }else{
                dp[t][d] = dp[t][d-1];
            }
        }
    }

    return dp[k][n - 1];
}

int main() {
    vector<int> arr = {10, 20, 30};
    int k = 1;
    cout << maxProfit(arr, k);
    return 0;
}