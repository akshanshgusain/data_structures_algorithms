//
// Created by Akshansh Gusain on 26/03/24.
//
#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/search-in-rotated-sorted-array/

//  1. findPivot function identifies the pivot element's index using a modified binary search approach. It iteratively
// divides the array into sub arrays, identifying the pivot where the sorted order changes.

//  2. search function utilizes the pivot index obtained from findPivot to conduct binary search in two sorted sub arrays.
// It efficiently searches for the target element in each subarray separately, ensuring logarithmic time complexity overall.
int findPivot(vector<int>& nums){
    int start = 0;
    int end = nums.size() - 1;
    int mid = 0;

    while(start <= end){
        int mid = start + (end-start)/2;

        if(mid == 0 || mid == nums.size()-1){
            return mid;
        }

        if(nums[mid] > nums[mid+1]){
            return mid;
        }
        else if(nums[mid] > nums[end]){
            // Highest Number is present in right subarray
            start = mid;
        }
        else if(nums[mid] < nums[end]){
            // Highest number is present in left subarray
            end = mid;
        }
    }
    return -1;
}


int main(){
    vector<int> nums = {4,5,6,7,0,1,2};
    int target = 0;

    return 0;
}