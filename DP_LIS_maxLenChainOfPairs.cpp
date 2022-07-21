//
// Created by Akshansh Gusain on 01/06/21.
//
#include<stdc++.h>
using namespace std;

int maxChainLen(vector<pair<int, int>> p, int n ){
    int dp[n];
    sort(p.begin(),p.end()); //sort based on first element
    int i, j;
    for(i = 0; i<n;i++){
        dp[i] = 1;
    }

    for(i =1; i<n ;i++){
        for(j=0; j<i ;j++){
            if(p[j].second < p[i].first){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    int ma = INT_MIN;
    for(int i=0; i< n; i++){
        ma = max(ma, dp[i]);
    }
    return ma;
}

int main(){
    vector<pair<int, int>>  arr ={make_pair(5,24), make_pair(39, 60), make_pair(15,28), make_pair(27,40), make_pair(50,90)};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<maxChainLen(arr, 5);
    return 0;
}
