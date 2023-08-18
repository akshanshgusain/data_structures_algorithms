//
// Created by Akshansh Gusain on 01/08/23.
//
#include<bits/stdc++.h>

using namespace std;


// Top-Down Heapify (Heapify-Up)
void topDownHeapify(vector<int> &heap, int idx) {
    if (idx == 0) {
        return;
    } // Reached the root of the heap, no need to heapify further

    int parentIdx =(idx - 1) / 2;
    if (heap[idx] > heap[parentIdx]) {
        swap(heap[idx], heap[parentIdx]);
        topDownHeapify(heap, parentIdx); // Recursively heapify upwards
    }
}


// Bottom-Up Heapify (Heapify-Down)
void bottomUpHeapify(vector<int> &heap, int idx) {
    int heapSize = heap.size();
    int leftChildIdx = 2 * idx + 1;
    int rightChildIdx = 2 * idx + 2;
    int largestIdx = idx;

    if (leftChildIdx < heapSize && heap[leftChildIdx] > heap[largestIdx]) {
        largestIdx = leftChildIdx;
    }
    if (rightChildIdx < heapSize && heap[rightChildIdx] > heap[largestIdx]) {
        largestIdx = rightChildIdx;
    }

    if (largestIdx != idx) {
        swap(heap[idx], heap[largestIdx]);
        bottomUpHeapify(heap, largestIdx); // Recursively heapify downwards
    }
}

// Extract the maximum element (root) from the max-heap
int extractMax(vector<int> &heap) {
    if (heap.empty()) {
        cerr << "Heap is empty!" << endl;
        return -1; // Error value
    }

    int maxValue = heap[0];
    heap[0] = heap.back();
    heap.pop_back();
    bottomUpHeapify(heap, 0);
    return maxValue;
}


// Insert an element into the max-heap
void insert(vector<int> &heap, int element) {
    heap.push_back(element);
    topDownHeapify(heap, heap.size() - 1);
}




int main() {
    vector<int> maxHeap;
    insert(maxHeap, 3);
    insert(maxHeap, 8);
    insert(maxHeap, 2);
    insert(maxHeap, 5);

    cout << "Max-Heap: ";
    for (int num: maxHeap) {
        cout << num << " ";
    }
    cout << endl;

    int maxVal = extractMax(maxHeap);
    cout << "Extracted Maximum Value: " << maxVal << endl;

    cout << "Max-Heap after extracting maximum: ";
    for (int num: maxHeap) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}