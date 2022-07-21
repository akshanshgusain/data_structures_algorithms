//
// Created by Akshansh Gusain on 16/09/21.
//

// DP Approach,  O((n-1)!).

// Before Optimization

//#include<stdc++.h>
//using namespace std;
//
//int n = 4;
//int dist[10][10] = {
//        {0,20,42,25},
//        {20,0,30,34},
//        {42,30,0,10},
//        {25,34,10,0}
//};
//
//int VISITED_ALL = (1<<n) - 1;
//
//int tsp(int mask, int pos){
//
//    if(mask == VISITED_ALL){
//        return dist[pos][0];
//    }
//
//    int ans = INT_MAX;
//    // try to go to an unvisited city
//    for(int city = 0 ; city< n ; city++){
//
//        // If current city is not visited
//        if((mask&(1<<city))==0){
//            int newAns = dist[pos][city] + tsp(mask|(1<<city), city);
//            ans = min(ans, newAns);
//        }
//    }
//    return ans;
//}
//
//int main(){
//    cout<<tsp(1,0)<<endl;
//    return 0;
//}


// After Optimization

// Time: O(2^N * N),
#include<stdc++.h>
using namespace std;

int n = 4;
int dist[10][10] = {
        {0,20,42,25},
        {20,0,30,34},
        {42,30,0,10},
        {25,34,10,0}
};

int VISITED_ALL = (1<<n) - 1;
int dp[16][4];

int tsp(int mask, int pos){
    // the mask can take 2^N values and pos take N values. Therefore, dp[2^N][N].

    if(mask == VISITED_ALL){
        return dist[pos][0];
    }

    // Lookup
    if(dp[mask][pos] != -1){
        return dp[mask][pos];
    }

    int ans = INT_MAX;
    // try to go to an unvisited city
    for(int city = 0 ; city< n ; city++){

        // If current city is not visited
        if((mask&(1<<city))==0){
            int newAns = dist[pos][city] + tsp(mask|(1<<city), city);
            ans = min(ans, newAns);
        }
    }
    return dp[mask][pos] = ans;
}

int main(){
    memset(dp,-1, sizeof dp);
    cout<<tsp(1,0)<<endl;
    return 0;
}