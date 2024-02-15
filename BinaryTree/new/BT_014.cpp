//
// Created by Akshansh Gusain on 15/02/24.
//
#include "BT_000.cpp"

void rightSideViewHelper(TreeNode *root, int level, vector<int> &result) {
    if (root == nullptr) {
        return;
    }
    if (level == result.size()) {
        result.push_back(root->val);
    }
    rightSideViewHelper(root->right, level + 1, result);
    rightSideViewHelper(root->left, level + 1, result);
}


vector<int> rightSideView(TreeNode *root) {
    vector<int> result;
    rightSideViewHelper(root, 0, result);
    return result;
}

void leftSideViewHelper(TreeNode *root, int level, vector<int> &result) {
    if (root == nullptr) {
        return;
    }
    if (level == result.size()) {
        result.push_back(root->val);
    }
    leftSideViewHelper(root->left, level + 1, result);
    leftSideViewHelper(root->right, level + 1, result);
}


vector<int> leftSideView(TreeNode *root) {
    vector<int> result;
    leftSideViewHelper(root, 0, result);
    return result;
}

int main() {
    //                 1
    //             /      \
    //            2        3
    //         /   \         \
    //      4       5        7
    //            /
    //          6

    auto root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(7);
    root->left->right->left = new TreeNode(6);

    vector<int> leftView = leftSideView(root);
    vector<int> rightView = rightSideView(root);

    cout << "Left Side View: " << endl;
    for (auto it: leftView) {
        cout << it << " ";
    }
    cout << endl;

    cout << "Right Side View: " << endl;
    for (auto it: rightView) {
        cout << it << " ";
    }
    cout << endl;

    return 0;
}