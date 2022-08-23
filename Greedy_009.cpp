//
// Created by Akshansh Gusain on 23/08/22.
//
#include<bits/stdc++.h>
using namespace std;

void findMinMax(vector<int> &candies, int k){
    sort(candies.begin(), candies.end());
    int mini = 0, maxi =  0;

    int startIndex = 0, endIndex = candies.size()-1;
    // calculating the mini cost.

    while( startIndex <= endIndex){
        mini += candies[startIndex];
        startIndex++;
        endIndex -= k;
    }

    // calculating the max cost
    startIndex = 0, endIndex = candies.size()-1;

    while( startIndex <= endIndex){
        maxi += candies[endIndex];
        startIndex += k;
        endIndex--;
    }
    cout<<mini<<" "<<maxi;
}

int main(){
    vector<int> candies = {3,2 ,1 ,4};
    int k = 2;
    findMinMax(candies, k);
    return 0;
}