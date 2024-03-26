//
// Created by Akshansh Gusain on 06/03/24.
//
#include "BST_000.cpp"


TreeNode* inOrder(TreeNode* root, int val){
    if(root == nullptr){
        return nullptr;
    }
    if(val < root->val){
        return inOrder(root->left, val);
    }else if(val > root->val){
        return inOrder(root->right, val);
    }else{
        return root;
    }
}


TreeNode* searchBST(TreeNode* root, int val) {
    return inOrder(root, val);
}

int main(){
    TreeNode* root = nullptr;
    root = insertInBST(root, 50);
    insertInBST(root, 30);
    insertInBST(root, 20);
    insertInBST(root, 40);
    insertInBST(root, 70);
    insertInBST(root, 60);
    insertInBST(root, 80);

    auto foundRoot = searchBST(root, 30);
    printBST(foundRoot);
    return 0;
}