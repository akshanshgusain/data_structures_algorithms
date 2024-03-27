//
// Created by Akshansh Gusain on 20/02/21.
//
#include<stdc++.h>
using namespace std;

int findMaxSum(int arr[], int n){
        int incl = arr[0];
        int excl = 0;
        int excl_new;
        int i;

        for(i=1; i<n;i++){
            //current max excluding i
            excl_new = (incl > excl)? incl: excl;

            //current max including i
            incl = excl + arr[i];
            excl = excl_new;
        }

        return ((incl>excl)? incl:excl);
}

int main(){
    int arr[] = {5,5,10,100,10,5};
    int n = sizeof(arr)/sizeof(int);
    cout<<findMaxSum(arr,n);
    return 0;
}