//
// Created by Akshansh Gusain on 02/02/21.
//
#include<stdc++.h>
using namespace std;

int binarySearch(int arr[], int l, int h, int key){
  if(l > h){
      return -1;
  }
  int mid = (l+h)/2;
  if(arr[mid] == key){
      return mid;
  }
  //If arr[1 ... mid] is sorted
  if(arr[l] <= arr[mid]){
      /* As this subarray is sorted, we can quickly
        check if key lies in half or other half */
      if (key >= arr[l] && key <= arr[mid])
          return binarySearch(arr, l, mid - 1, key);
      /*If key not lies in first half subarray,
         Divide other half  into two subarrays,
         such that we can quickly check if key lies
         in other half */
      return binarySearch(arr, mid + 1, h, key);
  }
    /* If arr[l..mid] first subarray is not sorted, then arr[mid... h]
      must be sorted subarray */
    if (key >= arr[mid] && key <= arr[h])
        return binarySearch(arr, mid + 1, h, key);

    return binarySearch(arr, l, mid - 1, key);
}


int main(){

    // Let us search 3 in below array
    int arr1[] = { 5, 6, 7, 8, 9, 10, 1, 2, 3 };
    int n = sizeof(arr1) / sizeof(arr1[0]);
    int key = 3;

    int i = binarySearch(arr1, 0, n - 1, key);

    if (i != -1)
        cout << "Index: " << i << endl;
    else
        cout << "Key not found";

    return 0;
}

