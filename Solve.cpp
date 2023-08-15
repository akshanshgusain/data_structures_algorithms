#include<bits/stdc++.h>
using namespace std;

void printFirstNegativeInteger(vector<int> &arr, int k){
    int n = arr.size();
    deque<int> q;

    int i = 0;
    for(; i <k ;i ++){
        if(arr[i] < 0){
            q.push_back(i);
        }
    }

    for(;i < n; i++){

        if(!q.empty()){
            cout<< arr[q.front()]<<" ";
        }else{
            cout<<"0 ";
        }

        // shrink the window
        while(!q.empty() and q.front() < (i -k + 1)){
            q.pop_front();
        }

        if(arr[i] < 0) {
            q.push_back(i);
        }
    }

    if(!q.empty()){
        cout<< arr[q.front()]<<" ";
    }else{
        cout<<"0 ";
    }

}

int main(){

    vector<int> arr = {12, -1, -7, 8, -15, 30, 16, 28};
    int k = 3;
    printFirstNegativeInteger(arr, k);
    return 0;

}