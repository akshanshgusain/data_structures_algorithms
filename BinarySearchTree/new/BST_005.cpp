//
// Created by Akshansh Gusain on 07/03/24.
//
#include "BST_000.cpp"

void storeInorder(TreeNode *root, vector<int> &ans) {
    if (root == nullptr) {
        return;
    }

    storeInorder(root->left, ans);
    ans.push_back(root->val);
    storeInorder(root->right, ans);
}

bool checkBST(TreeNode *root) {
    vector<int> inorderTraversal;
    storeInorder(root, inorderTraversal);

    for (auto it: inorderTraversal) {
        cout << it << " ";
    }
    cout << endl;

    for (int i = 1; i < inorderTraversal.size(); i++) {
        if (inorderTraversal[i - 1] >= inorderTraversal[i]) {
            return false;
        }
    }
    return true;
}

bool checkBST2(TreeNode *root, long long l, long long r) {
    if (root == nullptr) {
        return true;
    }
    if (root->val < r and root->val > l) {
        return checkBST2(root->left, l, root->val) and
               checkBST2(root->right, root->val, r);
    }
    return false;
}


int main() {
    TreeNode *root = nullptr;
    root = insertInBST(root, 50);
    insertInBST(root, 30);
    insertInBST(root, 20);
    insertInBST(root, 40);
    insertInBST(root, 70);
    insertInBST(root, 60);
    insertInBST(root, 80);

    cout << checkBST(root) << endl;

    auto root2 = new TreeNode(1);
    root2->left = new TreeNode(10);
    root2->right = new TreeNode(3);
    root2->left->left = new TreeNode(5);
    root2->left->right = new TreeNode(4);

    cout << checkBST(root2) << endl;
    return 0;
}