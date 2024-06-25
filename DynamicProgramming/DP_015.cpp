//
// Created by Akshansh Gusain on 12/11/21.
//
#include<stdc++.h>
using namespace std;
int t[100][100];

int minCoins(int coins[], int n, int value){
    if(value == 0){
        return 1;
    }
    if(value < 0){
        return 0;
    }

    if(n <= 0 and value >=1){
        return 0;
    }

    if(t[n][value] != -1){
        return t[n][value];
    }

    t[n][value] = minCoins(coins, n - 1, value) +
                  minCoins(coins, n, value - coins[n - 1]);

    return t[n][value];
}

int main() {
//    vector<int> coins = {9, 6, 5, 1};
    memset(t, -1, sizeof t);
    int coins[] = {1,2,3};
    //int value = 11;
    int size = sizeof(coins)/ sizeof (coins[0]);
    int value = 5;
    cout << "Minimum coins required is: " << minCoins(coins, size, value);
    return 0;
}
