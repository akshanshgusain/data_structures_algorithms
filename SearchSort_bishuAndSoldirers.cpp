//
// Created by Akshansh Gusain on 24/02/21.
//https://www.hackerearth.com/practice/algorithms/searching/binary-search/practice-problems/algorithm/bishu-and-soldiers/
#include<stdc++.h>
using namespace std;

int main(){
    int n,q;
    cin>>n; // number of soldiers
    int a[n];

    for(int i=0; i<n; i++){
        cin>>a[i]; //powers of each soldier
    }

    cin>>q; //number of rounds
    sort(a,a+n);

    while(q--){
        int temp;
        cin>>temp;  //Bishu's Power in each round
        int ind = upper_bound(a, a+n, temp) - a;
        int sum;
        for(int j=0; j < ind ; j++){
            sum+=a[j];
        }
        cout<<ind<<" "<<sum<<endl;
    }
    return 0;
}
