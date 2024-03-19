//
// Created by Akshansh Gusain on 19/03/24.
//
#include "BST_000.cpp"

int main() {
    TreeNode *root = nullptr;
    root = insertInBST(root, 50);
    insertInBST(root, 30);
    insertInBST(root, 20);
    insertInBST(root, 40);
    insertInBST(root, 70);
    insertInBST(root, 60);
    insertInBST(root, 80);
    insertInBST(root, 8);

    vector<int> inorder;
    buildInOrderArray(root, inorder);
    int median = 0;

    int inOrderSize = inorder.size();

    if (inOrderSize % 2 == 0) {
        median = (inorder[(inOrderSize - 1) / 2] + inorder[(inOrderSize - 1) / 2 + 1]) / 2;
    }else{
        median = inorder[(inOrderSize-1)/2];
    }

    cout<< median;

    return 0;
}