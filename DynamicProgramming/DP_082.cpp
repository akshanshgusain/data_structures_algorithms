//
// Created by Akshansh Gusain on 06/01/22.
//
#include<stdc++.h>

using namespace std;
/*Let us take few example values of n for x = 3, y = 4.
n = 0 A can not pick any coin so he losses
n = 1 A can pick 1 coin and win the game
n = 2 A can pick only 1 coin. Now B will pick 1 coin and win the game
n = 3 4 A will win the game by picking 3 or 4 coins
n = 5, 6 A will choose 3 or 4 coins. Now B will have to choose from 2 coins so A will win.*/

// We can observe that A wins game for n coins only when B
// loses for coins n-1 or n-x or n-y.

bool findWinner(int x, int y, int n) {
    // To store results
    int T[n + 1];

    // Initial values
    T[0] = false;
    T[1] = true;

    for (int i = 2; i < n; i++) {
        // If A looses any of i-1 or i-x or i-y game then he will
        // definitely win ith game
        if(i-1 >=0 and T[i - 1] == false){
            T[i] = true;
        }
        else if(i-x >=0 and T[i - x] == false){
            T[i] = true;
        }
        else if(i-y >=0 and T[i - x] == false){
            T[i] = true;
        }else{
            T[i] = false;
        }
    }

    return T[n];
}

int main() {
    int x = 3, y = 4, n = 5;
    if (findWinner(x, y, n))
        cout << 'A';
    else
        cout << 'B';

    return 0;
}
