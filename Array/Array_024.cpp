//
// Created by Akshansh Gusain on 12/07/21.
//
#include<stdc++.h>
using namespace std;

// Time: O(N) , Space: O(1)

int maxProduct(vector<int> arr){
    int n = arr.size();

    int ma = arr[0];
    int mi = arr[0];
    int prod = arr[0];

    for(int i =1; i <n ;i++){
        if(arr[i] < 0){
            swap(ma,mi);
        }
        ma = max(arr[i], ma * arr[i]);
        mi = min(arr[i], mi * arr[i]);

        if(ma > prod){
            prod = ma;
        }
    }

    return prod;
}

int main(){
    vector<int> arr = {6, -3, -10, 0, 2}; // 180  // The subarray is {6, -3, -10}
    vector<int> arr2 = {-1, -3, -10, 0, 60}; // 60  // The subarray is {60}
    vector<int> arr3 = {-2, -40, 0, -2, -3}; // 80  // The subarray is {-2, -40}

    cout<<maxProduct(arr);
    return 0;
}

