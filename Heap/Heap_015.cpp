//
// Created by Akshansh Gusain on 28/07/22.
//

// The problem might look complex at first look. But our final goal is to only build the max heap.
// The idea is very simple – we simply build Max Heap without caring about the input. We start from
// bottom-most and rightmost internal mode of min Heap and heapify all internal modes in bottom up
// way to build the Max heap.

#include<stdc++.h>

using namespace std;

// to heapify a subtree with root at given index
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

// This function basically builds max heap
void convertMaxHeap(vector<int> arr) {
    int n = arr.size();
    // Start from bottommost and rightmost
    // internal mode and heapify all internal
    // modes in bottom up way
    for (int i = (n - 2) / 2; i >= 0; --i)
        bottomUpHeapify(arr, i);
}

// A utility function to print a given array
// of given size
void printArray(vector<int> arr) {
    int size = arr.size();

    for (int i = 0; i < size; ++i)
        printf("%d ", arr[i]);
}

// Driver program to test above functions
int main() {
    // array representing Min Heap
    vector<int> arr = {3, 5, 9, 6, 8, 20, 10, 12, 18, 9};

    printf("Min Heap array : ");
    printArray(arr);

    convertMaxHeap(arr);

    printf("\nMax Heap array : ");
    printArray(arr);

    return 0;
}
