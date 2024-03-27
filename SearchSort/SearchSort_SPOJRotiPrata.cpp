//
// Created by Akshansh Gusain on 01/03/21.
//

#include<stdc++.h>
using namespace std;

int solve(int *a, int n, int par, int mid){
    int time =0;
    int prata = 0;
    for(int i=0; i<n ;i++){
        time = a[i];
        int j=2;
        while(time <= mid){
            prata++;
            time = time + (a[i]*j);
            j++;
        }
        if(prata>=par){
            return 1;
        }
    }
    return 0;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int par;
        cin>> par;
        int n;
        cin>>n;
        int a[n];
        for(int o=0;o<n;o++){
            cin>>a[o];
        }

        int lb =0;
        int ub= 1e8;
        int ans =0;

        while(lb<=ub){
            int mid = (ub+lb)/2;
            if(solve(a,n,par,mid)){
                ans = mid;
                ub=mid-1;
            }else{
                lb = mid+1;
            };
        }
        cout<<ans<<endl;
    }
    return 0;
}
