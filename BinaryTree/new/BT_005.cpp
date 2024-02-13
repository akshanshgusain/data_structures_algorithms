//
// Created by Akshansh Gusain on 11/02/24.
//

#include "BT_000.cpp"

void inOrderTraversal(TreeNode* &root){
    if(root == nullptr){
        return;
    }

    inOrderTraversal(root->left);
    cout<<root->val<<" ";
    inOrderTraversal(root->right);
}

// In-Order traversal
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

    inOrderTraversal(root); // 4 2 1 7 5 8 3 6
    return 0;
}