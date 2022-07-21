//
// Created by Akshansh Gusain on 30/03/21.
// Leetcode

#include<stdc++.h>
using namespace std;

//so that no element is used again
unordered_set<int> visited;

//
bool partition(vector<int>& nums, int pos,int k, int K, int sum, int T) {
    //only check for k-1 as last will be automatically = sum
    if (k == K-1)
        return true;

    if (sum == T) {
        // if we got the ans of one subset then we need to reset sum and recur for the other
        return partition(nums, 0, k+1,K, 0, T);
    }

    for (int i = pos; i < nums.size(); ++i) {
        if (!visited.count(i) && nums[i] <= T - sum) {
            visited.insert(i);

            //include the curr element and check in array if we can get to T
            if (partition(nums, i+1, k, K, sum + nums[i], T))
                //if we got the ans no need to backtrack and its index will stay in visited
                return true;

            //if ans is not found for a element remove it from visited(backtrack)
            visited.erase(i);
        }
    }
    return false;
}

bool isKPartitionPossible(vector<int>& nums, int k){
    int sum = 0;
    int N = nums.size();

    for (auto n : nums)
        sum += n;

    if (sum%k)
        return false;

    return (partition(nums, 0, 0, k, 0, sum/k));

}

int main() {
    vector<int> vec = {2, 1, 4, 5, 3, 3};
    int K = 3;

    if (isKPartitionPossible(vec, K))
        cout << "Partitions into equal sum is possible.\n";
    else
        cout << "Partitions into equal sum is not possible.\n";

    return 0;
}