//
// Created by Akshansh Gusain on 31/12/21.
//

#include<stdc++.h>
using namespace std;


int carAssembly(int a[][4], int t[][4],int *e, int *x ){
    int T1[4], T2[4], i;

    T1[0] = e[0] + a[0][0];
    T2[0] = e[1] + a[1][0];

    for(i = 1; i< 4; i++){
        T1[i] = min(T1[i-1]+a[0][i], T2[i-1]+a[0][i]+t[1][i]);
        T2[i] = min(T2[i-1] + a[1][i], T1[i-1] + a[1][i] + t[0][i]);
    }

    return min(T1[3] + x[0] , T2[3] + x[1]);
}


int main(){
    int a[][4] = {{4,5,3,2}, {2,10,1,4}}; //time of every station
    int t[][4] = {{0,7,4,5}, {0,9,2,8}}; //time of transition
    int e[] = {10,12}; // stating time
    int X[] = {18,7}; //ending time
    cout<<carAssembly(a,t,e,X);
    return 0;
}