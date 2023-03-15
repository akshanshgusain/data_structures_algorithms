//
// Created by Akshansh Gusain on 01/07/21.
//
// method 1: nLogN - heap/Merge sort and return k-1th element
// method 2: n + kLogN - create a min heap and do k pop operations
//method 3:  - Use an STL ordered Map

//method 4: Quick Select : Average case complexity: n, worst case : n2
// Quickselect is a selection algorithm to find the k-th smallest element in an unordered list.

#include<stdc++.h>

using namespace std;


void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


int partition(int arr[], int l, int r) {
    int x = arr[r], i = l;
    for (int j = l; j <= r - 1; j++) {
        if (arr[j] <= x) {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }
    swap(&arr[i], &arr[r]);
    return i;
}

int kthSmallest(int arr[], int l, int r, int k) {
    if (k > 0 and k <= r - l + 1) {
        int pos = partition(arr, l, r);

        if (pos - 1 == k - 1) {
            return arr[pos];
        }
        if (pos - 1 > k - 1) {
            return kthSmallest(arr, l, pos - 1, k);
        } else {
            return kthSmallest(arr, pos + 1, r, k - pos + l - 1);
        }
    }
    return -1;
}


int main() {
    int arr[] = {12, 3, 5, 7, 4, 19, 26};
    int n = sizeof(arr) / sizeof(arr[0]), k = 3;
    cout << "Kth smallest element is: " << kthSmallest(arr, 0, n - 1, k);
    return 0;
}
