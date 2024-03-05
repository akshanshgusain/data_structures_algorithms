//
// Created by Akshansh Gusain on 05/03/24.
//
#include "BT_000.cpp"

vector<vector<int>> paths;

void hasPathSum(TreeNode *root, int targetSum, vector<int> currentPath) {
    if (root == nullptr){
        return;
    }
    if (root->right == nullptr && root->left == nullptr) {
        if (targetSum == root->val) {
            currentPath.push_back(root->val);
            paths.push_back(currentPath);
        }
        return;
    }
    currentPath.push_back(root->val);

    hasPathSum(root->right, targetSum - root->val, currentPath);
    hasPathSum(root->left, targetSum - root->val, currentPath);
}


vector<vector<int>> pathSum(TreeNode *root, int targetSum) {
    hasPathSum(root, targetSum, {});
    return paths;
}

int main() {
    /* 10
    /     \
    28     13
        /     \
        14     15
        / \     / \
    21     22 23   24  */
    auto root = new TreeNode(10);

    root->left = new TreeNode(28);
    root->right = new TreeNode(13);

    root->right->left = new TreeNode(14);
    root->right->right = new TreeNode(15);

    root->right->left->left = new TreeNode(21);
    root->right->left->right = new TreeNode(22);
    root->right->right->left = new TreeNode(23);
    root->right->right->right = new TreeNode(24);

    int targetSum = 38;

    vector<vector<int>> pathss = pathSum(root, targetSum);

    for (const auto& it: paths) {
        for (auto i: it) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}