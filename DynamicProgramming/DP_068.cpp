//
// Created by Akshansh Gusain on 31/12/21.
////https://www.youtube.com/watch?v=ju8vrEAsa3Q
#include<stdc++.h>

using namespace std;

long countWays(int n, int k) {
    int same = k * 1;
    int different = k * (k - 1);

    int total = same + different;

    for (int i = 3; i <= n; i++) {
        same = different * 1;
        different = total * (k - 1);
        total = same + different;
    }

    return total;
}

int main() {
    int n = 8, k = 3;
    cout << countWays(n, k);
    return 0;
}