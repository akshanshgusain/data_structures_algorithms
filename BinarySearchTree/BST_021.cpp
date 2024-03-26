//
// Created by Akshansh Gusain on 24/03/24.
//

#include "BST_000.cpp"

struct NodeValue {
    int maxNode;
    int minNode;
    int maxSize;

    NodeValue(int maxValue, int minValue, int maxSize) {
        this->maxNode = maxValue;
        this->minNode = minValue;
        this->maxSize = maxSize;
    }
};

NodeValue largestBST(TreeNode *root) {
    if(root == nullptr){
        return {INT_MAX, INT_MIN, 0};
    }


    // get values from the left and the right subtrees
    auto left = largestBST(root->left);
    auto right = largestBST(root->right);

    // if the current node is greater than the largest node on the left and
    // is smaller than the smallest node on the right, it's a BST
    if(left.maxNode < root->val and right.minNode > root->val){
        return {min(root->val, left.minNode),
                max(root->val, right.maxNode),
                left.maxSize+right.maxSize+1
        };
    }

    return {INT_MIN, INT_MAX, max(left.maxSize, right.maxSize)};

}

int main() {
    auto *root = new TreeNode(20);
    root->left = new TreeNode(15);
    root->left->left = new TreeNode(14);
    root->left->left->right = new TreeNode(17);
    root->left->right = new TreeNode(18);
    root->left->right->left = new TreeNode(16);
    root->left->right->right = new TreeNode(19);


    root->right = new TreeNode(40);
    root->right->left = new TreeNode(30);
    root->right->right = new TreeNode(60);
    root->right->right->left = new TreeNode(50);

    auto ans = largestBST(root);
    cout<<ans.maxSize<<endl; //2


    return 0;
}