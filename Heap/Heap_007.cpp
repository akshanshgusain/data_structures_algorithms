//
// Created by Akshansh Gusain on 28/07/22.
//
#include<bits/stdc++.h>

#define int long long int
#define F first
#define S second
#define pb push_back
#define all(p) p.begin(), p.end()

using namespace std;

void maxHeapify(vector<int> &merged, int index){

    if(index > merged.size()){
        return;
    }

    int l = (2 * index) + 1;
    int r = (2 * index) + 2;

    // Find largest of node and its children
    int max;
    if(l < merged.size() and merged[l] > merged[index]){
        max = l;
    }else{
        max = index;
    }
    if(r < merged.size() and merged[r] > merged[index]){
        max = r;
    }

    // Put maximum value at the root and recur for the child with the max. value
    if(max != index){
        swap(merged[max], merged[index]);

        maxHeapify(merged, max);
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
    mergeHeaps(a, b, merged);
    for (auto it: merged) {
        cout << it << " ";
    }
    return 0;
}