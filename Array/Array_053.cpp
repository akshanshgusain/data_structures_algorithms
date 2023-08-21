//
// Created by Akshansh Gusain on 20/01/22.
//
#include<stdc++.h>

using namespace std;

// Time: O(NlogN), Space: O(1)

int binarySearch(vector<int> arr, int X, int low)
{
    int N = arr.size();
    int high = N - 1;
    int ans = N;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] >= X) {
            ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return ans;
}

int main() {
    vector<int> nums = {1, 2, 2, 1};
    //vector<int> nums = {3,2,1,5,4};
    int k = 1;
    //int k = 2;
    int n = nums.size();
    int count = 0;

    sort(nums.begin(), nums.end());

    for (int i = 0; i < n; ++i) {

        int X = binarySearch(nums, nums[i] + k, i + 1);

        if (X != n) { // nums[i] + k  = N ==> NOT FOUND
            int Y = binarySearch(nums, nums[i] + k + 1, i + 1);
            count += Y - X;
        }
    }

    cout<< count;
    return 0;
}


// Time: O(N), Space: O(N)
//         unordered_map<int, int> map;
//         for(int i =0;i < nums.size(); i++){
//             map[nums[i]] = map[nums[i]] + 1;
//         }


//         int pairCount = 0;

//         for(auto it: nums){
//          if( it - k > 0){
//             if(map.find(it-k) != map.end()){
//                  pairCount += map[it-k];
//             }
//          }
//         }

//         return pairCount;