//
// Created by Akshansh Gusain on 31/12/21.
//

#include<stdc++.h>

using namespace std;

int catalanNumber(int n) {
    int T[n];
    T[0] = T[1] = 1;
    for (int i = 2; i < n; i++) {
        for(int j = 0; j < i; j++){
            T[i] += T[j] * T[i-j-1];
        }
    }

    return T[n];
}

int main() {
    int n = 10;
    cout << catalanNumber(n);
    return 0;
}