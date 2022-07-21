//
// Created by Akshansh Gusain on 05/06/21.
//Right most set bit
// mask = all zeros except right most set bit
// find in O(1)


#include<stdc++.h>
using namespace std;


//rsb = x & x", simple
int main(){
    int n = 12;

    int rsb = log2(n & -n) + 1;
    cout<<rsb;
    return 0;
}
