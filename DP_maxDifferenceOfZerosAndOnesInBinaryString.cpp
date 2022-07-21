//
// Created by Akshansh Gusain on 01/06/21.

// Given a binary string of 0s and 1s. The task is to find the maximum difference of
// the number of 0s and the number of 1s (number of 0s – number of 1s) in the substrings
// of a string.
//https://www.geeksforgeeks.org/maximum-difference-zeros-ones-binary-string-set-2-time/
//Kadane's Algorithm

#include<stdc++.h>
using namespace std;

int maxDifference(vector<int> arr){
    int n = arr.size();
    for(int i =0; i < n ;i++){
        if(arr[i] == 0){
            arr[i]=1;
        }else{
            arr[i] = -1;
        }
    }
    int maxi = INT_MIN;
    int maxTH = 0;
    for(int i=1; i<=n ;i++){
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
    vector<int> arr = {1,1,0,0,0,0,1,0,0,0,1};
    cout<<maxDifference(arr);
    return 0;

}
