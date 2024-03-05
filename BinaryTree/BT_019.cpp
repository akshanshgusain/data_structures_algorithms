//
// Created by Akshansh Gusain on 26/02/24.
//
#include "BT_000.cpp"

bool isLeaf(TreeNode *root) {
    return (root->left == nullptr and root->right == nullptr);
}

bool isSumTree(TreeNode *root) {
    if (root == nullptr or isLeaf(root)) {
        return true;
    }

    if (isSumTree(root->left) and isSumTree(root->right)) {
        // calculate the sum of values of left and right subtrees
        int leftSubTreeSum;
        int rightSubTreeSum;

        if (root->left == nullptr) {
            leftSubTreeSum = 0;
        } else if (isLeaf(root->left)) {
            leftSubTreeSum = root->left->val;
        } else {
            leftSubTreeSum = 2 * (root->left->val);
        }

        if (root->right == nullptr) {
            rightSubTreeSum = 0;
        } else if (isLeaf(root->right)) {
            rightSubTreeSum = root->right->val;
        } else {
            rightSubTreeSum = 2 * (root->right->val);
        }

        return (root->val == leftSubTreeSum + rightSubTreeSum);
    }
}

int main() {
    auto *root = new TreeNode(26);
    root->left = new TreeNode(10);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(6);
    root->right->right = new TreeNode(3);

    if (isSumTree(root))
        cout << "The given tree is a SumTree ";
    else
        cout << "The given tree is not a SumTree ";
    return 0;
}