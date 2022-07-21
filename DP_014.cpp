//
// Created by Akshansh Gusain on 12/11/21.
//

// using unbound Knapsack

#include<stdc++.h>

using namespace std;

int t[100][100];

int _cutRod(int price[], int n, int length[], int rod_length) {

    if (n == 0 or rod_length == 0) {
        return 0;
    }
    if (t[n][rod_length] != -1) {
        return t[n - 1][rod_length];
    }
    if (length[n - 1] > rod_length) {
         t[n][rod_length] = _cutRod(price, n - 1, length, rod_length);
    } else {
         t[n][rod_length] = max(price[n - 1] + _cutRod(price, n, length, rod_length - length[n - 1]),
                                          _cutRod(price, n - 1, length, rod_length));
    }

    return t[n][rod_length];
}


int cutRod(int price[], int n) {
    int length[n];
    for (int i = 0; i < n; i++) {
        length[i] = i + 1;
    }
    int rod_len = n;

    return _cutRod(price, n, length, rod_len);
}

int main() {
    memset(t, -1, sizeof t);
    int price[] = {1, 5, 8, 9, 10, 17, 17, 20};
    int size = sizeof(price) / sizeof(price[0]);
    cout << "Maximum Obtainable Value is :" << cutRod(price, size);
    return 0;
}