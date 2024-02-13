//
// Created by Akshansh Gusain on 11/02/24.
//
#include "BT_000.cpp"

void preOrderTraversal(TreeNode* &root){
    if(root == nullptr){
        return;
    }
    cout<<root->val<< " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

// preOrder traversal
int main(){
    /* Construct the following tree
          1
        /   \
       /     \
      2       3
     /      /   \
    /      /     \
   4      5       6
         / \
        /   \
       7     8
*/

    auto *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(6);
    root->right->left->left = new TreeNode(7);
    root->right->left->right = new TreeNode(8);

    preOrderTraversal(root); // 1 2 4 3 5 7 8 6
    return 0;
}