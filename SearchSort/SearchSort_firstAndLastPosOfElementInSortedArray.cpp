//
// Created by Akshansh Gusain on 02/02/21.
//
#include<stdc++.h>
using namespace std;

/* If x is present in arr[] then returns the index of FIRST occurrence
 * of x in arr[0...n-1], otherwise return -1*/
int first(int arr[], int low, int high, int x, int n){
        if(high>=low){
            int mid = low + (high-low) / 2;
            if( (mid==0 || x > arr[mid-1]) && arr[mid] == x){
                return mid;
            }
            else if(x > arr[mid]){
                return first(arr, (mid+1), high, x, n);
            }else{
                return first(arr, low, (mid-1), x, n);
            }
        }
        return -1;
}
int last(int arr[], int low, int high, int x, int n){
    if(high>=low){
        int mid = low+ (high-low)/2;
        if((mid == n-1 || x< arr[mid +1]) && arr[mid] == x){
            return mid;
        }
        else if(x < arr[mid]){
            return last(arr, low, (mid+1), x, n);
        }
        else{
            return last(arr, (mid + 1), high, x,n);
        };
    }
    return -1;
}

int main(){
    int arr[] = {1,2,2,2,2,3,4,7,8,8};
    int n = sizeof(arr)/sizeof(int);
    int x=2;
    cout<<"First Occurrence of element: "<< first(arr, 0, n-1, x, n)<<endl;
    cout<<"First Occurrence of element: "<< last(arr, 0, n-1, x, n);
    return 0;
}
