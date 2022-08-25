//
// Created by Akshansh Gusain on 24/08/22.
//
#include<bits/stdc++.h>

using namespace std;

int findMinShopDays(int n, int s, int m) {

    // Base Case
    if (m > n or ((s > 6) and (6 * n) < (7 * m))) {
        return 0;
    }

    int days = (m * s) / n;

    if ((m * s) % n != 0) {
        days++;
    }

    return days;
}

int main() {
    int n = 16, s = 10, m = 2;
    cout << findMinShopDays(n, s, m);
    return 0;
}