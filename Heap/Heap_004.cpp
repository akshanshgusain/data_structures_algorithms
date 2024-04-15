//
// Created by Akshansh Gusain on 02/04/24.
//
#include<stdc++.h>
using namespace std;

int main(){
    vector<int> arr = { 11, 3, 2, 1, 15, 5, 4,45, 88, 96, 50, 45 };

    priority_queue<int> maxHeap;
    for(auto n : arr){
        maxHeap.push(n);
    }
    int k =4;

    for(int i = 0; i< k; i++){
        maxHeap.pop();
    }

    cout<<maxHeap.top();

    return 0;

}