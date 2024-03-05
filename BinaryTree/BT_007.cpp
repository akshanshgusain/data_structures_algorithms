//
// Created by Akshansh Gusain on 11/02/24.
//
#include "BT_000.cpp"

void postOrderTraversal(TreeNode* &root){
    if(root == nullptr){
        return;
    }

    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout<<root->val<< " ";
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

    postOrderTraversal(root); // 4 2 7 8 5 6 3 1
    return 0;
}