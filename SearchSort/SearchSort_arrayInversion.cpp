//
// Created by Akshansh Gusain on 02/03/21.
//
//Traverse through the array and for every index find the number of smaller elements on its
// right side of the array. This can be done using a nested loop. Sum up the counts for all
// index in the array and print the sum.

/*------------------------------ Simple Method START --------------------------------
#include<stdc++.h>
using namespace std;

int getInvCount(int arr[], int n)
{
    int inv_count = 0;
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (arr[i] > arr[j])
                inv_count++;

    return inv_count;
}

int main(){
    int arr[] = { 1, 20, 6, 4, 5 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << " Number of inversions are "
         << getInvCount(arr, n);
    return 0;
}

------------------------------ Simple Method END --------------------------------*/


//Using a merge sort
#include<stdc++.h>
using namespace std;

int mergeSort2(int a[], int temp[], int left, int mid, int right){
    int i,j, k, inv =0;
    i = left;
    j = mid;
    k=left;
    while((i<=mid-1) and (j<=right)){
        if(a[i] <= a[j]){
            temp[k++] = a[i++];
        }else{
            temp[k++] = a[j++];
            inv += (mid-i);
        }
    }
    while(i<=mid-1){
        temp[k++] = a[i++];
    }
    while(j<=right){
        temp[k++] = a[j++];
    }
    for(int m= left; m<=right ; m++){
        a[m] = temp[m];
    }
    return inv;
}

int mergeSort(int a[], int temp[], int left, int right){
    int inv =0;
    if(left<right){
        int mid = (left+right)/2;

        inv += mergeSort(a, temp, left, mid);
        inv += mergeSort(a,temp, mid+1, right);
        inv += mergeSort2(a, temp,left,mid+1,right);

    }
    return inv;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i=0; i< n; i++){
            cin>>a[i];
        }
        int temp[n];
        cout<<mergeSort(a, temp, 0, n-1);
    }
    return 0;
}