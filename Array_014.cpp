//
// Created by Akshansh Gusain on 01/07/21.
//
// Kadane's Algorithm
#include<stdc++.h>
using namespace std;

int findMax(vector<int> arr){
    int maxTH = 0;
    int maxi = INT_MIN;

    for(int i=1; i < arr.size()-1; i++){
        maxTH += arr[i];
        if(maxi < maxTH){
            maxi = maxTH;
        }
        if (maxTH < 0){
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
