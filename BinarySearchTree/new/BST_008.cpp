//
// Created by Akshansh Gusain on 08/03/24.
//
#include "BST_000.cpp"

// Time complexity: O(n)
//Space complexity: O(log n)
TreeNode* helper(vector<int> &nums, int l, int r) {
    if(l > r){
        return nullptr;
    }
    int mid = (l + r) / 2;
    auto root = new TreeNode(nums[mid]);

    root->left = helper(nums, l, mid - 1);
    root->right = helper(nums, mid + 1, r);
    return root;
}

TreeNode* sortedArrayToBST(vector<int>& nums) {
    return helper(nums, 0, nums.size()-1);
}

int main(){
    vector<int> nums = {-10,-3,0,5,9};
    auto root = sortedArrayToBST(nums);
    printBST(root);
    return 0;
}