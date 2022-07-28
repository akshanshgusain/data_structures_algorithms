//
// Created by Akshansh Gusain on 25/07/22.
//
#include<stdc++.h>

using namespace std;

// To heapify a subtree rooted with node i which is
// an index in arr[]. N is size of heap
void heapify(vector<int> &arr, int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    //if lest child is larger than root
    if (l < n and arr[l] > arr[largest]) {
        largest = l;
    }
    if (r < n and arr[r] > arr[largest]) {
        largest = r;
    }

    if (largest != i) {
        swap(arr[i], arr[largest]);
        //Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

void buildHeap(vector<int> &arr) {
    int n = arr.size();

    //Index of last non-leaf node
    int startIndex = (n / 2) - 1;

    // Perform reverse level order traversal from last non-leaf node and heapify each node
    for (int i = startIndex; i >= 0; i--) {
        heapify(arr, n, i);
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