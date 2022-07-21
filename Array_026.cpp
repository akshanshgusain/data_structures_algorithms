//
// Created by Akshansh Gusain on 12/07/21.
//
#include<stdc++.h>
using namespace std;

void solve(vector<int> arr, int k){
    int n = arr.size();
    int x = n/k;

    unordered_map<int, int> fre;
    for(auto it: arr){
        fre[arr[it]] ++;
    }

    for(auto i: fre){
        if(i.second > x){
            cout<< i.first<<" ";
        }
    }
}

int main(){
    vector<int> arr = { 1, 1, 2, 2, 3, 5, 4, 2, 2, 3, 1, 1, 1 };
    int k =4;
    solve(arr,k);
    return 0;
}
