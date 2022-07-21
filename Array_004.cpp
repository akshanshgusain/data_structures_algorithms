//
// Created by Akshansh Gusain on 01/07/21.
//

// Method 1: Simple counting : time : O(n), Space : O(3)
#include<stdc++.h>
using namespace std;

void sort012(int arr[], int n) {
        int lo = 0;
        int mid = 0;
        int hi = n-1;

        while(mid <= hi){
            switch(arr[mid]){
                case 0:
                    swap(arr[lo], arr[mid]);
                    lo++; mid++;
                    break;
                case 1:
                    mid++;
                    break;
                default:
                    swap(arr[mid], arr[hi]);
                    hi--;
                    break;
            }
        }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " , ";
    }
}

int main() {
    int arr[] = {0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    sort012(arr, n);

    cout << "array after segregation ";

    printArray(arr, n);

    return 0;

}



