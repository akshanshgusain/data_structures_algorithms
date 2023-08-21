//
// Created by Akshansh Gusain on 01/07/21.
//
//Move all the negative elements to one side of the array

//Method 1: Using Dutch National FLag
#include<stdc++.h>
using namespace std;

void rearrange(int a[], int n){
    int lo =0;
    int mid = 0;
    while(mid <= n){
        if(a[mid]<0){
            swap(a[lo], a[mid]);
            lo++, mid++;
        }else{
            mid++;
        }
    }
}

void printArray(int arr[], int n){
    for(int i =0; i< n; i++){
        cout<<arr[i]<<" ,";
    }
}

// Method 2: Using partition process of Quick Sort O(n) time and O(1) Space
void rearrange2(int arr[], int n)
{
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] < 0) {
            if (i != j)
                swap(arr[i], arr[j]);
            j++;
        }
    }
}

//Method 3: Using 2 pointer Technique, O(n) time and O(1) Space
void rearrange3(int arr[], int n){
    int i = 0, j=n-1;

    while(i<=j){
        if(arr[i]< 0 and arr[j]<0){
            i++;
        }
        else if(arr[i] >  0 and arr[j]<0){
            swap(arr[i++], arr[j--]);
        }
        else if(arr[i] <  0 and arr[j]>0){
            j--;
        }else{
            i++, j--;
        }
    }
}

int main(){
    int arr[] = { -1, 2, -3, 4, 5, 6, -7, 8, 9 };
    int n = sizeof(arr) / sizeof(arr[0]);
    rearrange2(arr, n);
    printArray(arr, n);
    return 0;
}

