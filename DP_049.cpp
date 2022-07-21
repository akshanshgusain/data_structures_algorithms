//
// Created by Akshansh Gusain on 29/12/21.
//
#include<stdc++.h>

using namespace std;
int T[1001][1001];

// Function to get minimum
// number of trials needed in worst
// case with n eggs and k floors
int eggDrop(int n, int k) {
    // If there are no floors,
    // then no trials needed.
    // OR if there is one floor,
    // one trial needed.
    if (k == 1 || k == 0)
        return k;

    // We need k trials for one
    // egg and k floors
    if (n == 1)
        return k;

    if(T[n][k] != -1){
        return T[n][k];
    }

    int mini = INT_MAX, x, res;

    // Consider all droppings from
    // 1st floor to kth floor and
    // return the minimum of these
    // values plus 1.
    for (x = 1; x <= k; x++) {
        res = 1 + max(
                eggDrop(n - 1, x - 1),
                eggDrop(n, k - x));

        mini = min(mini, res);
    }
    return T[n][k] = mini;
}

int main() {
    int n = 2, k = 10;
    memset(T, -1, sizeof T);
    printf("Minimum number of trials "
           "in worst case with %d eggs and "
           "%d floors is %d \n",
           n, k, eggDrop(n, k));
    return 0;
}