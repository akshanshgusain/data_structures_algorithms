//
// Created by Akshansh Gusain on 25/07/22.
//
#include<stdc++.h>

using namespace std;

//Method 1: Heap Sort = O(NlogN)
//Method 2: Min-Heap = O(n + kLogN)
//Method 3: Max-Heap = O(k + (n-k)*LogK)
//Method 4: STL = Time complexity: O(NLogK), Auxiliary Space: O(LogK)

//Min - Heap
// A C++ program to find kth-smallest element using min heap
#include <stdc++.h>

using namespace std;

//// Prototype of a utility function to swap two integers
//void swap(int *x, int *y);
//
//// A class for Min Heap
//class MinHeap {
//    vector<int> harr; // pointer to array of elements in heap
//    int capacity; // maximum possible size of min heap
//    int heap_size; // Current number of elements in min heap
//public:
//    MinHeap(vector<int> &a, int size);// Constructor
//
//    void MinHeapify(int i); // To minheapify subtree rooted with index i
//    int parent(int i) { return (i - 1) / 2; }
//
//    int left(int i) { return (2 * i + 1); }
//
//    int right(int i) { return (2 * i + 2); }
//
//    int extractMin(); // extracts root (minimum) element
//    int getMin() { return harr[0]; } // Returns minimum
//};
//
//MinHeap::MinHeap(vector<int> &a, int size) {
//    heap_size = size;
//    harr = a; // store address of array
//    int i = (heap_size - 1) / 2;
//    while (i >= 0) {
//        MinHeapify(i);
//        i--;
//    }
//}
//
//// Method to remove minimum element (or root) from min heap
//int MinHeap::extractMin() {
//    if (heap_size == 0)
//        return INT_MAX;
//
//    // Store the minimum vakue.
//    int root = harr[0];
//
//    // If there are more than 1 items, move the last item to root
//    // and call heapify.
//    if (heap_size > 1) {
//        harr[0] = harr[heap_size - 1];
//        MinHeapify(0);
//    }
//    heap_size--;
//
//    return root;
//}
//
//// A recursive method to heapify a subtree with root at given index
//// This method assumes that the subtrees are already heapify
//
//void MinHeap::MinHeapify(int i) {
//    int l = left(i);
//    int r = right(i);
//    int smallest = i;
//    if (l < heap_size && harr[l] < harr[i])
//        smallest = l;
//    if (r < heap_size && harr[r] < harr[smallest])
//        smallest = r;
//    if (smallest != i) {
//        swap(&harr[i], &harr[smallest]);
//        MinHeapify(smallest);
//    }
//}
//
//// A utility function to swap two elements
//void swap(int *x, int *y) {
//    int temp = *x;
//    *x = *y;
//    *y = temp;
//}
//
//// Function to return k'th smallest element in a given array
//int kthSmallest(vector<int> &arr, int n, int k) {
//    // Build a heap of n elements: O(n) time
//    MinHeap mh(arr, n);
//
//    // Do extract min (k-1) times
//    for (int i = 0; i < k - 1; i++)
//        mh.extractMin();
//
//    // Return root
//    return mh.getMin();
//}


// Using heap Sort

void bottomUpHeapify(vector<int> &heap, int heapSize, int idx) {
    int largestIndex = idx;
    int leftChildIndex = 2 * idx + 1;
    int rightChildIndex = 2 * idx + 2;

    if (heapSize < leftChildIndex and heap[leftChildIndex] > heap[idx]) {
        largestIndex = leftChildIndex;
    }

    if (heapSize < rightChildIndex and heap[rightChildIndex] > heap[idx]) {
        largestIndex = rightChildIndex;
    }

    if (idx != largestIndex) {
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

    return arr[k - 1];
}


int main() {
    vector<int> arr = {12, 3, 5, 7, 19};
    int k = 2;
    cout << "kth smallest element is " << kthSmallest(arr, k);
    return 0;
}