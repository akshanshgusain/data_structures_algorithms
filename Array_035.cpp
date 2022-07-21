//
// Created by Akshansh Gusain on 14/07/21.
//
#include<stdc++.h>
using namespace std;

int minSwap(vector<int> arr, int n, int k){

    int window = 0;
    for(int i =0 ; i< n; i++){
        if(arr[i] <= k)
            window++;
    }

    int missFits = 0;

    for(int i =0 ; i< window; i++){
        if(arr[i] > k){
            missFits++;
        }
    }

    int swaps = missFits;
    for(int i =0, j = window; j < n; i++, j++){

        if(arr[i] > k){
            missFits--;
        }

        if(arr[j] > k){
            missFits++;
        }

        swaps = min(swaps, missFits);
    }

    return swaps;
}

int main(){
    vector<int> arr = {2, 1, 5, 6, 3};
    int n = arr.size();
    int k = 3;
    cout << minSwap(arr, n, k) << "\n";

    vector<int> arr1 = {2, 7, 9, 5, 8, 7, 4};
    n = arr1.size();
    k = 5;
    cout << minSwap(arr1, n, k);
    return 0;
}
