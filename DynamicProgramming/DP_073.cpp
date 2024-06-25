//
// Created by Akshansh Gusain on 01/01/22.
//
#include<stdc++.h>
using namespace std;
#define N 4
#define M 6

int maxSubArraySum(int a[], int size){
    int MAX_SO_FAR = INT_MIN, MAX_ENDING_HERE = 0;

    for(int i =0 ; i < size; i++){

        MAX_ENDING_HERE += a[i];
        if(MAX_ENDING_HERE > MAX_SO_FAR){
            MAX_SO_FAR = MAX_ENDING_HERE;
        }

        if(MAX_ENDING_HERE < 0){
            MAX_ENDING_HERE = 0;
        }
    }

    return MAX_SO_FAR;
}

int main(){
    int a[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = sizeof(a)/sizeof(a[0]);
    int max_sum = maxSubArraySum(a, n);
    cout << "Maximum contiguous sum is " << max_sum;

    return 0;
}

