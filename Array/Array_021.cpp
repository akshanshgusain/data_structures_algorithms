//
// Created by Akshansh Gusain on 09/07/21.
//

//Time: O(NlogN) and, O(1) Space
//Order will be maintained.

//We first sort the array in non-increasing order.Then we will count the number of positive
// and negative integers. Then we will swap the one negative and one positive.

#include<stdc++.h>

using namespace std;

// # of negative numbers are lesser or equal than pos #s
void fill_1(int a[], int neg, int pos) {
    if (neg % 2 == 1) {
        for (int i = 1; i < neg; i += 2) {
            swap(a[i], a[i + neg]);
        }
    } else {
        for (int i = 1; i <= neg; i += 2) {
            swap(a[i], a[i + neg - 1]);
        }
    }
}

void fill_2(int a[], int neg, int pos) {
    if (pos % 2 == 1) {
        for (int i = 1; i < pos; i += 2) {
            swap(a[i], a[i + pos]);
        }
    } else {
        for (int i = 1; i <= pos; i += 2) {
            swap(a[i], a[i + pos - 1]);
        }
    }
}

void solve(int arr[], int n) {
    int neg = 0, pos = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] < 0) {
            neg++;
        } else {
            pos++;
        }
    }

    if (neg <= pos) {
        fill_1(arr, neg, pos);
    } else {
        reverse(arr, arr + n);
        fill_2(arr, neg, pos);
    }

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    cout << endl;
}


//Time: O(N) and, O(1) Space
// Order will not be maintained.

//The idea is to process the array and shift all negative values to the end in O(n) time.
// After all negative values are shifted to the end, we can easily rearrange array in
// alternating positive & negative items. We basically swap next positive element at even
// position from next negative element in this step.

void rearrange(int arr[], int n) {
    int i = 0, j = n-1;

    // shift all negative values to the end
    while (i <= j) {
        if(arr[i]<0 and arr[j]>0){
            swap(arr[i],  arr[j]);
            i++; j--;
        }else if(arr[i] > 0 and arr[j] <0){
            i++; j--;
        }else if(arr[i] > 0){
            i++;
        }else if(arr[j] < 0){
            j--;
        }
    }

    // i has index of leftmost negative element
    //that means if(i==0) all the elements are negative and if(i==n) then all the elements are positive
    if (i == 0 || i == n)
        return;

    // start with first positive
    // element at index 0

    // Rearrange array in alternating
    // positive &
    // negative items
    int k = 0;
    while (k < n && i < n) {
        // swap next positive
        // element at even position
        // from next negative element.
        swap(arr[k], arr[i]);
        i = i + 1;
        k = k + 2;
    }
}

// Utility function to print an array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {2, 3, -4, -1, 6, -9};
    int n = sizeof(arr) / sizeof(arr[0]);
//    sort(arr, arr + n);
//    solve(arr, n);
    rearrange(arr, n);
    printArray(arr, n);
    return 0;
}
