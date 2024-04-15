//
// Created by Akshansh Gusain on 02/04/24.
//
#include<bits/stdc++.h>

#define int long long int
#define F first
#define S second
#define pb push_back
#define all(p) p.begin(), p.end()

using namespace std;

void maxHeapify(vector<int> &merged, int idx){
    if(idx > merged.size()){
        return;
    }

    int leftChildIdx = (2 * idx) + 1;
    int rightChildIdx = (2 * idx) + 2;
    int largestIdx = idx;

    // Find largest of node and its children
    if(leftChildIdx < merged.size() and merged[leftChildIdx] > merged[largestIdx]){
        largestIdx = leftChildIdx;
    }
    if(rightChildIdx < merged.size() and merged[rightChildIdx] > merged[largestIdx]){
        largestIdx = rightChildIdx;
    }

    // Put maximum value at the root and recur for the child with the max. value
    if(largestIdx != idx){
        swap(merged[largestIdx], merged[idx]);
        maxHeapify(merged, largestIdx);
    }
}

void buildMaxHeap(vector<int> &merged){
    // start with first non-leaf node
    for(int i = merged.size()/2 -1; i >= 0; i++){
        maxHeapify(merged, i);
    }
}

void mergeHeaps(vector<int> &merged, vector<int> &a, vector<int> &b) {
    // Copy elements of a[] and b[] one by one
    // to merged[]
    for (long long i : a){
        merged.push_back(i);
    }

    for (long long i : b){
        merged.push_back(i);
    }
    // build heap for the modified array of
    // size n+m
    buildMaxHeap(merged);
}

int32_t main() {
    vector<int> a = {10, 5, 6, 2};
    vector<int> b = {12, 7, 9};
    vector<int> merged;
    mergeHeaps(merged, a, b);
    for (auto it: merged) {
        cout << it << " ";
    }
    return 0;
}