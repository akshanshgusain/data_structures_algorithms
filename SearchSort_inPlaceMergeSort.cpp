//
// Created by Akshansh Gusain on 02/03/21.
//
#include<stdc++.h>
using namespace std;

void mergeFunction(int arr[], int start, int mid, int end){
    int start2 = mid+1;

    if(arr[mid] <= arr[start2]){
        return;
    }

    // Two pointers to maintain start
    // of both arrays to merge
    while (start <= mid && start2 <= end) {

        // If element 1 is in right place
        if (arr[start] <= arr[start2]) {
            start++;
        }
        else {
            int value = arr[start2];
            int index = start2;

            // Shift all the elements between element 1
            // element 2, right by 1.
            while (index != start) {
                arr[index] = arr[index - 1];
                index--;
            }
            arr[start] = value;

            // Update all the pointers
            start++;
            mid++;
            start2++;
        }
    }
}

void mergeSort(int arr[], int l, int r){
    if(l < r){
        int mid = (r-l)/2;

        mergeSort(arr, l, mid);
        mergeSort(arr, mid+1, r);

        mergeFunction(arr, l,mid,r);
    }
}

void printArray(int A[], int size){
    int i;
    for(i=0; i<size ; i++){
        cout<<A[i]<<endl;
    }
}
int main(){
    int arr[] = {12,11,13,5,6,7};
    int n = sizeof(arr)/sizeof(int);
    mergeSort(arr, 0, n-1);
    printArray(arr,n);
    return 0;
}
