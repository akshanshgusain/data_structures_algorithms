//
// Created by Akshansh Gusain on 14/02/24.
//
#include "BT_000.cpp"

bool isLeaf(TreeNode *root) {
    return (root->left == nullptr) and (root->right == nullptr);
}

void addLeftBoundary(TreeNode *root, vector<int> &result) {
    auto current = root->left;
    while (current != nullptr) {
        if (!isLeaf(current)) {
            result.push_back(current->val);
        }
        if (current->left != nullptr) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
}

void addLeafNodes(TreeNode *root, vector<int> &result) {
    if (isLeaf(root)) {
        result.push_back(root->val);
    }
    // recursively call the left and the right subtrees
    if (root->left != nullptr) {
        addLeafNodes(root->left, result);
    }
    if (root->right != nullptr) {
        addLeafNodes(root->right, result);
    }
}

void addRightBoundary(TreeNode *root, vector<int> &result) {
    auto current = root->right;
    vector<int> tmp; // because we need to reverse
    while (current) {
        if (!isLeaf(current)) {
            tmp.push_back(current->val);
        }
        if (current->right != nullptr) {
            current = current->right;
        } else {
            current = current->left;
        }
    }
    for (int i = tmp.size() - 1; i >= 0; --i) {
        result.push_back(tmp[i]);
    }
}


vector<int> printBoundary(TreeNode *root) {
    vector<int> result;
    if (root == nullptr) {
        return result;
    }

    if (!isLeaf(root)) {
        result.push_back(root->val);
    }

    addLeftBoundary(root, result);
    addLeafNodes(root, result);
    addRightBoundary(root, result);

    return result;
}

int main() {
    auto *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->left->right = new TreeNode(4);
    root->left->left->right->left = new TreeNode(5);
    root->left->left->right->right = new TreeNode(6);
    root->right = new TreeNode(7);
    root->right->right = new TreeNode(8);
    root->right->right->left = new TreeNode(9);
    root->right->right->left->left = new TreeNode(10);
    root->right->right->left->right = new TreeNode(11);

    vector<int> boundaryTraversal;
    boundaryTraversal = printBoundary(root);

    cout << "The Boundary Traversal is : ";
    for (int i : boundaryTraversal) {
        cout << i << " ";
    }

    // 1 2 3 4 5 6 10 11 9 8 7

    return 0;
}