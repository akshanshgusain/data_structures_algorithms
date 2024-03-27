//
// Created by Akshansh Gusain on 26/02/21.
//
#include<stdc++.h>
using namespace std;

bool isWoodEnough(int a[], int n, int m, int mid){
    int sum = 0;
    for(int i=0; i<n;i++){
        if(a[i]>mid){
            sum+= a[i] - mid;
        }
    }
    if(sum>=m){
        return true;
    }
    return false;
}

int main(){
    int n,m;  // n= number of trees, m= length of wood required
    cin>>n>>m;
    int a[n];
    for(int i =0; i<n;i++ ){
        cin>> a[i];
    }
    int lb=0, ans =0, ub = *max_element(a,a+n);

    while(lb<=ub){
        int mid = (lb+ub)/2;
        if(isWoodEnough(a,n,m,mid)){
            ans = mid;
            lb = mid+1;
        }else{
            ub = mid -1;
        }
    }
    cout<< ans;
    return 0;
}
