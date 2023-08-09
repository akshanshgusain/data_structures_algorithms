//
// Created by Akshansh Gusain on 25/07/22.
//
#include<stdc++.h>

using namespace std;

// To heapify a subtree rooted with node i which is
// an index in arr[]. N is size of heap
void bottomUpHeapify(vector<int> &heap, int idx) {
    int largestIndex = idx;
    int leftChildIdx = 2 * idx + 1;
    int rightChildIdx = 2 * idx + 2;
    int heapSize = heap.size();

    //if lest child is larger than root
    if (leftChildIdx < heapSize and heap[leftChildIdx] > heap[largestIndex]) {
        largestIndex = leftChildIdx;
    }
    if (rightChildIdx < heapSize and heap[rightChildIdx] > heap[largestIndex]) {
        largestIndex = rightChildIdx;
    }

    if (largestIndex != idx) {
        swap(heap[idx], heap[largestIndex]);
        //Recursively heapify the affected sub-tree
        bottomUpHeapify(heap, largestIndex);
    }
}

// O(NlogN)
void buildHeap(vector<int> &arr) {
    int n = arr.size();

    //Index of last non-leaf node,< parent of the last element >
    int startIndex = (n / 2) - 1;

    // Perform reverse level order traversal from last non-leaf node and heapify each node
    for (int i = startIndex; i >= 0; i--) {
        bottomUpHeapify(arr,  i);
    }
}

int main() {
    // Binary heap = Binary Tree Representation
    // Binary Tree Representation
    // of input array
    //              1
    //           /     \
    //         3         5
    //      /    \     /  \
    //     4      6   13  10
    //    / \    / \
    //   9   8  15 17
    vector<int> arr = {1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17};

    buildHeap(arr);

    return 0;
}