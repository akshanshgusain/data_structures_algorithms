//
// Created by Akshansh Gusain on 31/05/21.
//
#include<stdc++.h>
using namespace std;
/*
 * nPk = n!/(n-k)!
 *[ (n-0) * (n-1) * (n-2) * (n-3)* ... (n-k-1) * (n-k)! ] / (n-k)!
 * == (n-0) * (n-1) * (n-2) * (n-3)* ... (n-k-1) */

int permutation(int n, int k){
    int p =1;
    for(int i=0; i< k; i++){
        p *= (n-i);
    }
    return p;
}
int main(){
    int n=10, k=2;
    cout<<"Value of P("<<n<<" , "<< k <<") is: "<<permutation(n,k);
    return 0;
}

