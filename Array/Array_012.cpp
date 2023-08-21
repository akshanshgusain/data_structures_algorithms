//
// Created by Akshansh Gusain on 03/07/21.
//find duplicate in an array of N+1 Integers


//The basic idea is to use a HashMap to solve the problem. But there is a catch,
// the numbers in the array are from 0 to n-1, and the input array has length n.
// So, the input array can be used as a HashMap. While Traversing the array, if
// an element ‘a’ is encountered then increase the value of a%n‘th element by n.
// The frequency can be retrieved by dividing the a % n’th element by n


#include<stdc++.h>
using namespace std;

int main(){
    vector<int> nums = { 0, 4, 3, 2, 7, 8, 2, 3, 1 };
    int n = nums.size();

    for(int i=0; i<n; i++){
        nums[nums[i]%n] = nums[nums[i]%n] + n;
    }
    cout<<"repeating elements are: "<<endl;

    for(int i =0; i < n ; i++){
        if(nums[i] >= n*2){
            cout<<i<<" "<<endl;
        }
    }
    return 0;
}
