//
// Created by Akshansh Gusain on 30/01/21.
//
#include<stdc++.h>
using namespace std;

int minOps(string& a, string& b){
    int m = a.length();
    int n = b.length();

    if(m!=n){
        return -1;
    }
    int count[256];
    memset(count, 0,sizeof(count));
    for(int i=0; i<n ; i++){  //count chars in B
        count[b[i]]++;
    }

    for(int i=0; i<n ; i++){
        count[a[i]]--;
    }

    for(int i=0; i<256 ; i++){
        if(count[i]){
            return -1;
        }
    }

    //Now calculate number of operation required
    int res = 0;
    for(int i = n-1 , j = n-1 ; i >=0;){

        while(i>=0 && a[i] != b[j]){
            i--;
            res++;
        }
        if(i >= 0){
            i--;
            j++;
        }
    }
    return res; 
}

int main(){
    string A = "EACBD";
    string B = "EABCD";
    cout << "Minimum number of operations "
            "required is " << minOps(A, B);
    return 0;
}
