//
// Created by Akshansh Gusain on 31/12/21.
//
#include<stdc++.h>
using namespace std;
// T[i] will contain min. jumps from start to ith position.

int minJumps(vector<int> arr){
    int n = arr.size();
    int T[n];
    for(int i =0 ; i < n;i++){
        T[i] = INT_MAX;
    }
    T[0] = 0 ;

    for(int i = 1; i < n; i ++){
        for(int j = 0; j < i; j++){
            if(T[j] != INT_MAX and (arr[i]+j >= i)){
                if(T[j] + 1 < T[i]){
                    T[i] = T[j]+1;
                }
            }
        }
    }

    if(T[n-1] != INT_MAX) {
        return T[n-1];
    }
    else{
        return -1;
    }
}

int main(){
    vector<int> arr = {1, 3, 6, 1, 0, 9 };
    cout<<"Mini. number of jumps to reach end is: "<< minJumps(arr);
    return 0;
}
