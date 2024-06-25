//
// Created by Akshansh Gusain on 14/01/22.
//

// https://www.youtube.com/watch?v=IN3uTs8afz4&t=1155s


#include<stdc++.h>
using namespace std;

int getCount(char keypad[][3], int key) {
    int dp[key+1][10];
    memset(dp ,0, sizeof dp);
    vector<vector<int>> moves = {{0, 8},
                                 {1, 2, 4},
                                 {1, 2, 3, 5},
                                 {2, 3, 6},
                                 {1, 4, 5, 7},
                                 {2, 4, 5, 6, 8},
                                 {3, 5, 6, 9},
                                 {4, 7, 8},
                                 {5, 7, 8, 9, 0},
                                 {6, 8, 9}};

    for(int i= 1; i <= key; i++){
        for(int j=0; j <=9; j++){
            if(i == 1){
                dp[i][j] = 1;
            }else{
                for(int prev : moves[j]){
                    dp[i][j] += dp[i-1][prev];
                }
            }
        }
    }

    int sum = 0;
    for(int i = 0; i <=9; i++){
        sum += dp[key][i];
    }

    return sum;
}

int main() {
    char keypad[4][3] = {{'1', '2', '3'},
                         {'4', '5', '6'},
                         {'7', '8', '9'},
                         {'*', '0', '#'}};

    cout << getCount(keypad, 1)<<endl;
    cout << getCount(keypad, 2)<<endl;
    cout << getCount(keypad, 3)<<endl;
    cout << getCount(keypad, 4)<<endl;
    cout << getCount(keypad, 5)<<endl;
    return 0;
}
