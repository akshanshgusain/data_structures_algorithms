//
// Created by Akshansh Gusain on 05/06/21.
//
#include<stdc++.h>

using namespace std;

unsigned int countSetBits(int n) {
    unsigned int count = 0;
    while (n) {
        n &= (n - 1);// rsbm
        count++;
    }
    return count;
}

int main() {
    int i = 9;
    cout <<countSetBits(i);
    return 0;
}