//
// Created by Akshansh Gusain on 24/03/24.
//
#include "BST_000.cpp"

/// Problem statement:
// Given a Binary search Tree that contains positive integer values greater than 0.
// The task is to check whether the BST contains a dead end or not. Here Dead End
// means, we are not able to insert any element after that node.

bool isLeaf(TreeNode *root){
    return (root->left == nullptr and root->right == nullptr);
}
void storeNodes(
        TreeNode *root,
        unordered_set<int> &allNodes,
        unordered_set<int> &allLeafNodes
) {
    if (root == nullptr) {
        return;
    }

    allNodes.insert(root->val);

    if (isLeaf(root)) {
        allLeafNodes.insert(root->val);
        return;
    }

    storeNodes(root->left, allNodes, allLeafNodes);
    storeNodes(root->right, allNodes, allLeafNodes);
}

//If we take a closer look at the problem, we can notice that we basically need to
// check if there is a leaf node with value x such that x+1 and x-1 exist in BST
// with the exception of x = 1. For x = 1, we can’t insert 0 as the problem statement
// says BST contains positive integers only.

// time: O(N), space: O(N)
bool isDeadEnd(TreeNode *root) {
    if (root == nullptr) {
        return root;
    }

    unordered_set<int> allNodes, allLeafNodes;
    allNodes.insert(0);
    storeNodes(root, allNodes, allLeafNodes);

    for (auto it: allLeafNodes) {
        if (allNodes.find(it - 1) != allNodes.end() and allNodes.find(it + 1) != allNodes.end()) {
            return true;
        }
    }
    return false;
}

int main() {
    TreeNode *root = nullptr;
    root = insertInBST(root, 8);
    insertInBST(root, 5);
    insertInBST(root, 2);
    insertInBST(root, 3);
    insertInBST(root, 7);
    insertInBST(root, 11);
    insertInBST(root, 4);

    if (isDeadEnd(root)) {
        cout << "Yes " << endl;
    } else {
        cout << "No " << endl;
    }

    return 0;
}