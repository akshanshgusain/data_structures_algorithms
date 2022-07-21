//
// Created by Akshansh Gusain on 01/01/22.
//

#include<stdc++.h>
using namespace std;


int subSequences(vector<int> &ip, int k){
        int n = ip.size();

        int T[k+1][n+1];
        memset(T, 0, sizeof T);

        // there will 2 sol.: 1. not involving jth element and 1 involving jth element

        // 1st Solution will have 1 component:
        // 1st: Previous Answer,

        // 2nd Solution will have 2 component:
        // 1st: will be 1(a subsequence with only the j-1 th element in it),  if(ip[j-1] <= i),
        // 2nd: i/ip[j-1] th row and j-1 column:, (All the subsequence whose product was i/ip[j-1])

        for(int i = 1; i <= k; i++){
            for(int j =1; j <= n; j++){
                T[i][j] = T[i][j-1];

                if(ip[j-1] <= i and ip[j-1] >= 0){
                    T[i][j] += T[i/ip[j-1]][j-1] + 1;
                }
            }
        }

        return T[k][n];
}

int main(){
    vector<int> ip = {1,2,3,4};
    int  k = 10;
    cout<<subSequences(ip, k);
    return 0;
}