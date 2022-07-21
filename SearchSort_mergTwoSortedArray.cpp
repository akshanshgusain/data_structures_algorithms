//
// Created by Akshansh Gusain on 22/02/21.
//
//merge 2 sorted array with out taking extra space

#include<stdc++.h>
using namespace std;

//Merge ar1[] and ar2[] with O(1) extra space
void merge(int arr[], int arr2[], int m, int n){
    //iterate through all elements of arr2[] starting from the least element
    for(int i=n-1; i>=0;i--){
        /*Find the smallest element greater than arr2[i]. */
        int j, last = arr[m-1];
        for(j=m-2; j>=0 && arr[j]>arr2[i]; j--){
            arr[j+1] = arr[j];
        }
        //if there was a greater element
        if(j != m-2 || last> arr2[i]){
            arr[j+1] = arr2[i];
            arr2[i] = last;
        }
    }
}

int main(){
    int ar1[] = { 1, 5, 9, 10, 15, 20 };
    int ar2[] = { 2, 3, 8, 13 };
    int m = sizeof(ar1) / sizeof(ar1[0]);
    int n = sizeof(ar2) / sizeof(ar2[0]);
    merge(ar1, ar2, m, n);

    cout << "After Merging nFirst Array: ";
    for (int i = 0; i < m; i++)
        cout << ar1[i] << " ";
    cout << "nSecond Array: ";
    for (int i = 0; i < n; i++)
        cout << ar2[i] << " ";

    return 0;
}
