//
// Created by Akshansh Gusain on 02/04/24.
//

// 1. Build a Heap
// 2. Extract Element and reduce the heap size
// 3. call heapify

#include<stdc++.h>

using namespace std;

void bottomUpHeapify(vector<int> &heap, int heapSize, int idx) {
    int largest = idx; // Initialize largest as root
    int leftChildIdx = 2 * idx + 1; // left = 2*i + 1
    int rightChildIdx = 2 * idx + 2; // right = 2*i + 2

    // If left child is larger than root
    if (leftChildIdx < heapSize && heap[leftChildIdx] > heap[largest])
        largest = leftChildIdx;

    // If right child is larger than largest so far
    if (rightChildIdx < heapSize && heap[rightChildIdx] > heap[largest])
        largest = rightChildIdx;

    // If largest is not root
    if (largest != idx) {
        swap(heap[idx], heap[largest]);

        // Recursively heapify the affected sub-tree
        bottomUpHeapify(heap, heapSize, largest);
    }
}

void printArray(vector<int> arr) {
    for (auto it: arr)
        cout << it << " ";
    cout << "\n";
}

void heapSort(vector<int> &arr) {
    int n = arr.size();

    // Build heap (rearrange array)
    for (int i = (n / 2) - 1; i >= 0; i--) {
        bottomUpHeapify(arr, n, i);
    }


    // One by one extract an element from heap
    for (int i = n - 1; i > 0; i--) {
        // Move current root to end
        swap(arr[0], arr[i]);

        // call max heapify on the reduced heap
        bottomUpHeapify(arr, i, 0);
    }
}


int main() {

    vector<int> arr = {12, 11, 13, 5, 6, 7};

    heapSort(arr);

    cout << "Sorted array is \n";
    printArray(arr);

    return 0;
}
