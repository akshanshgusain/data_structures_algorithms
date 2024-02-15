//
// Created by Akshansh Gusain on 15/02/24.
//
#include "BT_000.cpp"


void swapSubTrees(TreeNode* &root){
    if(root == nullptr){
        return;
    }
    auto temp = root->left;
    root->left = root->right;
    root->right = temp;

    swapSubTrees(root->left);
    swapSubTrees(root->right);
}


TreeNode* invertTree(TreeNode* root) {
    swapSubTrees(root);
    return root;
}

int main(){
    auto root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);

    //           5
    //        /    \
    //      3        6
    //   /   \
    //  2      4

    printf("Inorder of original tree: ");
    printInorder(root); // 2 3 4 5 6

    auto invertedTreeRoot = invertTree(root);

    printf("\nInorder of mirror tree: ");
    printInorder(invertedTreeRoot); // 6 5 4 3 2

    return 0;
}