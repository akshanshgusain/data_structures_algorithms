//
// Created by Akshansh Gusain on 01/06/21.
//
//Find the contiguous sub-array with maximum sum.
#include<stdc++.h>
using namespace std;

int findMax(vector<int> arr){
    int n = arr.size();
    int maxi = INT_MIN;
    int maxTH = 0;

    for(int i = 1; i<=n ;i++){
        maxTH += arr[i];
        if(maxTH > maxi){
            maxi = maxTH;
        }
        if(maxTH < 0){
            maxTH = 0;
        }
    }
    return maxi;
}

int main(){
    vector<int> arr = {7,5,-13,5,10,-2,5};
    cout<<findMax(arr);
    return 0;
}
