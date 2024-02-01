//
// Created by Akshansh Gusain on 30/01/24.
//

#include "BT_000.cpp"

int heightOfBinaryTree(TreeNode *&head) {
    if (head == nullptr) {
        return 0;
    }

    int leftHeight = heightOfBinaryTree(head->left);
    int rightHeight = heightOfBinaryTree(head->right);

    return 1 + max(leftHeight , rightHeight);
}

// Time: O(N^2)
void diameterOfBinaryTree(TreeNode* &root, int &diameter){
    if(root == nullptr){
        return;
    }

    int leftHeight = heightOfBinaryTree(root->left);
    int rightHeight = heightOfBinaryTree(root->right);
    diameter = max(diameter, leftHeight + rightHeight);

    diameterOfBinaryTree(root->left, diameter);
    diameterOfBinaryTree(root->right, diameter);
}

// Optimised version, using the find height code
// Time: O(N)
int diameterOfBinaryTreeO(TreeNode *&head, int &diameter) {
    if (head == nullptr) {
        return 0;
    }

    int leftHeight = diameterOfBinaryTreeO(head->left, diameter);
    int rightHeight = diameterOfBinaryTreeO(head->right, diameter);
    diameter = max(diameter, leftHeight + rightHeight);

    return 1 + max(leftHeight , rightHeight);
}


int main(){
    auto* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(8);

    // Get the diameter of the binary tree
    int treeDiameter = INT_MIN;
    diameterOfBinaryTreeO(root, treeDiameter);

    // Print the result
    cout << "Diameter of the Binary Tree: " << treeDiameter << endl;
    return 0;
}