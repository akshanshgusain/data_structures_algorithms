//
// Created by Akshansh Gusain on 25/08/22.
//
#include<bits/stdc++.h>
using namespace std;

/*
1. The idea is to count the occurrence of positive and negative elements
2. If there are even number of negative numbers and no zeros, the result is simply the product of all
3. If there are odd number of negative numbers and no zeros,then the result is the product of all except the negative
integer with the least absolute value.
4. If there are zeros, the result is the product of all except these zeros with one exceptional case. The exceptional case
is when there is one negative number and all other elements are 0. In this case, the result is 0.
 */

int findMaxProduct(vector<int> &a){
    if(a.size() == 1){
        return a[0];
    }

    int leastAbsNeg = INT_MIN;
    int count_neg = 0;
    int count_zero = 0;
    int product = 1;
    int i;

    for(i = 0; i < a.size(); i++){

        // If number is 0, we don't multiply it with product.
        if (a[i] == 0) {
            count_zero++;
            continue;
        }

        // Count negatives and keep track of negative number with the least absolute value
        if (a[i] < 0) {
            count_neg++;
            leastAbsNeg = max(leastAbsNeg, a[i]);
        }

        product = product * a[i];
    }

    // Case 1 : If they are all zero
    if(count_zero == a.size()){
        return 0;
    }

    // Case 2: If there are odd numbers of negative numbers
    if(count_neg & 1){
        // case 2.1: Edge case - If there is only one negative number and all zeros
        if(count_neg ==1 and count_zero > 0 and count_zero+count_neg == a.size()){
            return 0;
        }

        // case 2.2: Otherwise result is product/leastAbsNeg
        product /= leastAbsNeg;
    }

    return product;
}

int main(){
    vector<int> arr = {-1, -1, -2, 4, 3};
    cout<<findMaxProduct(arr);
    return 0;
}