//
// Created by Akshansh Gusain on 05/07/21.
//
#include<stdc++.h>
using namespace std;

// using STL function
void nextPermutationSTL(vector<int>& arr){
    next_permutation(arr.begin(), arr.end());
    cout<<arr[0]<<" ,"<<arr[1]<<" ,"<<arr[2];
}

//Without Using STL
//https://www.geeksforgeeks.org/find-the-next-lexicographically-greater-word-than-a-given-word/



void nextPermutationW(vector<int>& arr){
    int len = arr.size(), i = len-2;

    //A sequence sorted in descending order does not have next permutation
    //For a sequence which is not sorted in descending order for example “abedc”, we can follow below steps:

    // a) Traverse from right and find the first item that is not following the descending order.
    // For example in “abedc”, the character ‘b’ does not follow the descending order.
    while(i >= 0 and arr[i] >= arr[i+1]){
        --i;
    }

    // b) Swap the found character with closest greater (or smallest greater) element on right
    // side of it. In case of “abedc”, we have ‘c’ as the closest greater element.
    // After swapping ‘b’ and ‘c’, string becomes “acedb”.
    if(i >= 0){
       int index = binary_search(arr.begin()+i, arr.end(), arr[i]);
       swap(arr[i], arr[index]);
        reverse(arr.begin()+i, arr.end());
    }
    cout<<arr[0]<<" ,"<<arr[1]<<" ,"<<arr[2];
}

int main(){
    vector<int> arr = { 1, 2, 3 };
    //nextPermutationSTL(arr);
    nextPermutationW(arr);
    return 0;
}
