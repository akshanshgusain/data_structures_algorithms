//
// Created by Akshansh Gusain on 18/05/21.
//

#include<stdc++.h>
using namespace std;

int findTargetSum(vector<int> nums, int targetSum) {
    int count = 0, sum = 0;

    int n = nums.size();

    for (int num : nums) {
        sum = sum + num;
        if (num == 0)
            count = count + 1;
    }
    if (targetSum > sum)
        return 0;
    if ((targetSum + sum) % 2 != 0)
        return 0;
    int s = (targetSum + sum) / 2;

    int dp[n + 1][s + 1];
    for (int i = 0; i < n + 1; i++)
        dp[i][0] = 1;
    for (int j = 1; j < s + 1; j++)
        dp[0][j] = 0;
    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < s + 1; j++) {
            if (nums[i - 1] == 0)
                dp[i][j] = dp[i - 1][j];
            else if (j < nums[i - 1])
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i - 1]];
        }
    }

    return pow(2, count) * dp[n][s];
}

int main() {
    //int arr[] = {1, 5, 3, 7, 4};
    vector<int> arr = {1, 1, 1, 1, 1};
    int targetSum = 3;

    cout << findTargetSum(arr, targetSum);
    return 0;
}