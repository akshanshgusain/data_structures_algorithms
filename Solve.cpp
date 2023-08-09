#include<bits/stdc++.h>

using namespace std;

void bottomUpHeapify(vector<int> &heap, int heapSize, int idx){
    int largestIndex = idx;
    int leftChildIndex = 2 * idx + 1;
    int rightChildIndex = 2 * idx + 2;

    if(heapSize < leftChildIndex and heap[leftChildIndex] > heap[idx]){
        largestIndex = leftChildIndex;
    }

    if(heapSize < rightChildIndex and heap[rightChildIndex] > heap[idx]){
        largestIndex = rightChildIndex;
    }

    if(idx != largestIndex){
        swap(heap[idx], heap[largestIndex]);
        bottomUpHeapify(heap, heapSize, largestIndex);
    }
}

int kthSmallest(vector<int> &arr, int k) {
    int n = arr.size();
    int parentIdx = (n - 1) / 2;

    for (int i = parentIdx; i >= 0; i--) {
        bottomUpHeapify(arr, n, 0);
    }

    // one by one extract elements from the heap and reduce the heap.
    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        bottomUpHeapify(arr, i, 0);
    }

    return arr[k-1];
}

vector<int> mergeKArrays(vector<vector<int>> &arr){
    priority_queue<int, vector<int>,greater<>> heap;
    for(auto i : arr){
        for(auto it: i){
            heap.push(it);
        }
    }

    vector<int> res;
    while(!heap.empty()){
        res.push_back(heap.top());
        heap.pop();
    }
    return res;
}

int main() {
    vector<vector<int>> arr = { { 2, 6, 12 },{ 1, 9 },{ 23, 34, 90, 2000 } };
    vector<int> output = mergeKArrays(arr);
    cout << "Merged array is " << endl;
    for (auto x : output)
        cout << x << " ";

    return 0;
}