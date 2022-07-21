//
// Created by Akshansh Gusain on 05/06/21.
//https://www.youtube.com/watch?v=k9Yxy-NhSTA

#include<stdc++.h>

using namespace std;

int divide(long long dividend, long long divisor) {
    // Calculate sign of divisor i.e.,
    // sign will be negative only iff
    // either one of them is negative
    // otherwise it will be positive
    int sign = ((dividend < 0) ^
                (divisor < 0)) ? -1 : 1;

    dividend = abs(dividend);
    divisor = abs(divisor);

    // Initialize the quotient
    long long quotient = 0, temp = 0;
    // test down from the highest bit(32 bit - INT) and
    // accumulate the tentative value for
    // valid bit
    for (int i = 31; i >= 0; --i) {

        if (temp + (divisor << i) <= dividend) {
            temp += divisor << i;
            quotient |= 1LL << i;
        }
    }

    return sign * quotient;
}

int main() {
    int a = 10, b = 3;
    cout << divide(a, b) << "\n";

    a = 43, b = -8;
    cout << divide(a, b);

    return 0;
}
