//
// Created by Akshansh Gusain on 16/07/21.
//
#include<stdc++.h>

using namespace std;

// Time: O(log(min(N1,N2))) , Space: O(1)

double findMedian(vector<int> &nums1, vector<int> &nums2) {
    if (nums2.size() < nums1.size()) {
        return findMedian(nums2, nums1);
    }

    int n1 = nums1.size();
    int n2 = nums2.size();
    int low = 0, high = n1;

    while(low <= high){
        int cut1 = (low+high)/2;
        int cut2 = (n1+n2+1)/2 - cut1;

        int left1 = cut1 == 0 ? INT_MIN : nums1[cut1 -1];
        int left2 = cut2 == 0 ? INT_MIN : nums2[cut2 -1];

        int right1 = cut1 == n1 ? INT_MAX : nums1[cut1];
        int right2 = cut2 == n2 ? INT_MAX : nums2[cut2];

        if(left1 <= right2 and left2 <= right1){
            if((n1 + n2) % 2 == 0){
                return (max(left1, left2) + min(right1, right2)) / 2.0;
            }else{
                return max(left1, left2);
            }
        }else if(left1 > right2){
            high = cut1 - 1;
        }else{
            low = cut1 + 1;
        }
    }
    return 0.0;
}

int main() {
    vector<int> arr1 = {-5, 3, 6, 12, 15};
    vector<int> arr2 = {-12, -10, -6, -3, 4, 10}; // 3

    cout<<findMedian(arr1, arr2);

    return 0;
}
