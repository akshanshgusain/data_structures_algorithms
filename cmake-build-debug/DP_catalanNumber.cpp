//
// Created by Akshansh Gusain on 31/05/21.
//
#include<stdc++.h>
using namespace std;

unsigned long int catalanNumber(int n){
    if(n <= 1){
        return 1;
    }
    //catalan(n) = catalan(i) * catalan(n-i-1)
    unsigned long int result =0;
    for(int i=0; i< n;i++){
        result += catalanNumber(i) * catalanNumber(n-i-1);
    }

    return result;
}

int main(){
    int n = 10;
    cout<<catalanNumber(n);
    return 0;
}
