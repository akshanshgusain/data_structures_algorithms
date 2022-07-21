//
// Created by Akshansh Gusain on 30/03/21.
//
/*
 *  There are two cases.
1. The previous n – 1 elements are divided into k partitions, i.e S(n-1, k) ways. Put this nth element into one of the previous k partitions. So, count = k * S(n-1, k)
2. The previous n – 1 elements are divided into k – 1 partitions, i.e S(n-1, k-1) ways. Put the nth element into a new partition ( single element partition).So, count = S(n-1, k-1)
3. Total count = k * S(n-1, k) + S(n-1, k-1).
 */

#include<stdc++.h>
using namespace std;

int countP(int n, int k)
{
    // Base cases
    if (n == 0 || k == 0 || k > n)
        return 0;

    if (k == 1 || k == n)
        return 1;

    // S(n+1, k) = k*S(n, k) + S(n, k-1)
    return  k*countP(n-1, k) + countP(n-1, k-1);
}

int main(){
    cout <<  countP(3, 2);
    return 0;
}

