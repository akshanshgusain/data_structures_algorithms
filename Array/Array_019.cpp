//
// Created by Akshansh Gusain on 07/07/21.
//
#include<stdc++.h>
using namespace std;

void printPairs(vector<int> arr, int sum){
    int n = arr.size();
    sort(arr.begin(), arr.end());
    int l =0, r = n-1;

    while(l <= r){
        if(arr[l]+arr[r] == sum){
            cout<<"{ "<<arr[l]<<", "<<arr[r]<<" }"<<endl;
        }
        if(arr[l]+arr[r] > sum){
            r--;
        }else{
            l++;
        }
    }
}
int main(){
    vector<int> arr = {2, 3, 4, -2, 6, 8, 9, 11};
    int sum = 6;
    printPairs(arr, sum);
    return 0;
}

