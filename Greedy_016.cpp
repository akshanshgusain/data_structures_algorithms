//
// Created by Akshansh Gusain on 25/08/22.
//
#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> a = {5, 3, 2, 4, 1};
    sort(a.begin(), a.end());

    int sum = 0;
    for(int i =0; i< a.size(); i++){
        sum += a[i] *i;
    }
    cout<<sum;
    return 0;
}