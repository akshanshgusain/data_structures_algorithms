//
// Created by Akshansh Gusain on 08/02/21.
//
#include<stdc++.h>
using namespace std;

int compare(const void *a, const void *b){
    return (*(int *)a - *(int *)b);
}
void find4Numbers(int A[], int n, int X){
    int l,r;

    qsort(A,n,sizeof(A[0]), compare);
    //now fix the first 2 elements one by one and find the other
    //two elements
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j< n-2; j++){
             //Initialize two variables as indexes of the first ans last
             //elements in the remaining elements
             l = j+1;
             r = n-1; 
        }
    }
}

int main(){

    return 0;
}