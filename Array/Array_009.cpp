//
// Created by Akshansh Gusain on 01/07/21.
//
// We can find max-sum with Kadane's algorithm and maintain indices to print the sub-array.

#include<stdc++.h>
using namespace std;

int findMax(vector<int> arr){
    int maxTH = 0;
    int maxi = INT_MIN;
    int  start = 0, end = 0, s = 0;

    for(int i =1; i< arr.size()-1; i++){
        maxTH += arr[i];
        if(maxi < maxTH){
            maxi = maxTH;
            //start = s;
            end = i;
        }
        if(maxTH < 0) {
            maxTH = 0;
            //s = i+1;
            start = i+1;
        }
    }

    cout<<"Starting at: "<<start<<", ending at: "<<end<<endl;
    return maxi;
}

int main(){
    vector<int> arr ={-2, -3, 4, -1, -2, 1, 5, -3};
    cout<<findMax(arr)<<endl<<"MAX SUM: ";
    return 0;
}

