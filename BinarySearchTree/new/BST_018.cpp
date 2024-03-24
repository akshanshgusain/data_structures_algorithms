//
// Created by Akshansh Gusain on 24/03/24.
//

#include "BST_000.cpp"

void countNodesInRange(TreeNode *root, int start, int end, int &count){
    if(root == nullptr){
        return;
    }

    countNodesInRange(root->left, start, end, count);
    if(root->val >= start and root->val <= end){
        count = count + 1;
    }
    countNodesInRange(root->right, start, end, count);
}

int main(){
    TreeNode *root = nullptr;
    root = insertInBST(root, 10);
    insertInBST(root, 5);
    insertInBST(root, 50);
    insertInBST(root, 1);
    insertInBST(root, 40);
    insertInBST(root, 100);

    int count = 0;
    int start = 40;
    int end = 100;

    countNodesInRange(root, start, end, count);
    cout<<count;
    return 0;
}