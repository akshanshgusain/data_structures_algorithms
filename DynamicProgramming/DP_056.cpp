//
// Created by Akshansh Gusain on 30/12/21.
//https://www.geeksforgeeks.org/count-ways-reach-nth-stair/


/* The person can reach nth stair from either (n-1)th stair or from (n-2)th stair.
 * Hence, for each stair n, we try to find out the number of ways to reach n-1th stair and n-2th stair and add them to give the answer for the nth stair.
 * ways(n) = ways(n-1) + ways(n-2) */
#include<stdc++.h>
using namespace std;
int T[100];

int fibo(int n){
    if( n <= 1){
        return n;
    }
    if(T[n] != -1){
        return T[n];
    }
    return T[n] = fibo(n-1) + fibo(n-2);
}

int countWays(int steps){
    return fibo(steps+1);
}

int main(){
    memset(T, -1, sizeof T);
    int steps = 4;
    cout << countWays(steps);
    return 0;
}