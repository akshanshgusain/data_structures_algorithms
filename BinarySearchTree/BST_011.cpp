//
// Created by Akshansh Gusain on 08/03/24.
//
#include "BST_000.cpp"

/*
1. Traverse given BST in inorder and store result in an array. This step takes O(n) time.
 Note that this array would be sorted as inorder traversal of BST always produces sorted sequence.
2. Build a balanced BST from the above created sorted array using the recursive approach discussed here.
 This step also takes O(n) time as we traverse every element exactly once and processing an element takes
 O(1) time.
*/

// Time complexity: O(n)
//Space complexity: O(log n)
TreeNode *helper(vector<int> &nums, int l, int r) {
    if (l > r) {
        return nullptr;
    }
    int mid = (l + r) / 2;
    auto root = new TreeNode(nums[mid]);

    root->left = helper(nums, l, mid - 1);
    root->right = helper(nums, mid + 1, r);
    return root;
}


TreeNode *buildTree(TreeNode *root) {
    vector<int> sortedArray;
    buildInOrderArray(root, sortedArray);
    return helper(sortedArray, 0, sortedArray.size() - 1);
}


int main() {
    TreeNode *root = nullptr;
    root = insertInBST(root, 20);
    insertInBST(root, 8);
    insertInBST(root, 22);
    insertInBST(root, 4);
    insertInBST(root, 12);
    insertInBST(root, 10);
    insertInBST(root, 14);
    return 0;
}