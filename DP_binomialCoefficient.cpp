//
// Created by Akshansh Gusain on 31/05/21.
//
//nCr = n! / r! * (n-r)!
//Pascle triangle
//nCr = nC n-r

#include<stdc++.h>
using namespace std;

int binomialCoeff(int n, int k) {
    int C[k + 1];
    memset(C, 0, sizeof(C));

    C[0] = 1; // nC0 is 1

    for (int i = 1; i <= n; i++) {
        // Compute next row of pascal triangle using
        // the previous row
        for (int j = min(i, k); j > 0; j--)
            C[j] = C[j] + C[j - 1];
    }
    return C[k];
}

int main() {
    int n = 5, k = 2;
    printf("Value of C(%d, %d) is %d ", n, k,
           binomialCoeff(n, k));
    return 0;
}