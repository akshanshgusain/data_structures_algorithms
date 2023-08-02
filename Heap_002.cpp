//
// Created by Akshansh Gusain on 25/07/22.
//

// 1. Build a Heap
// 2. Extract Element
// 3. call heapify

#include<stdc++.h>

using namespace std;

void bottomUpHeapify(int arr[], int n, int i) {
    int largest = i; // Initialize largest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2

    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;

    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;

    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);

        // Recursively heapify the affected sub-tree
        bottomUpHeapify(arr, n, largest);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

void heapSort(int arr[], int n) {
    // Build heap (rearrange array)
    for (int i = (n / 2) - 1; i >= 0; i--)
        bottomUpHeapify(arr, n, i);

    // One by one extract an element from heap
    for (int i = n - 1; i > 0; i--) {
        // Move current root to end
        swap(arr[0], arr[i]);

        // call max heapify on the reduced heap
        bottomUpHeapify(arr, i, 0);
    }
}


int main() {

    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    heapSort(arr, n);

    cout << "Sorted array is \n";
    printArray(arr, n);

    return 0;
}
