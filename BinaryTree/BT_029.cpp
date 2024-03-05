//
// Created by Akshansh Gusain on 04/03/24.
//
#include "BT_000.cpp"

bool isMatch(TreeNode* root, TreeNode* subRoot){
    if(root != nullptr and subRoot != nullptr){
        bool isLeftMatch = isMatch(root->left, subRoot->left);
        bool isRightMatch = isMatch(root->right, subRoot->right);
        if(isLeftMatch and isRightMatch and root->val == subRoot->val){
            return true;
        }else{
            return false;
        }
    }else if(root == nullptr and subRoot == nullptr){
        return true;
    }else{
        return false;
    }
}


void inOrder(TreeNode* root, TreeNode* subRoot, bool &ans){
    if(root == nullptr){
        return;
    }

    inOrder(root->left, subRoot, ans);
    if(isMatch(root, subRoot)){
        ans = true;
    }
    inOrder(root->right, subRoot, ans);
}

bool isSubtree(TreeNode* root, TreeNode* subRoot){
    bool ans = false;
    inOrder(root, subRoot, ans);
    return ans;
}

int main() {
    auto root = new TreeNode(3);
    root->right = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(11);
    root->left->right = new TreeNode(10);

    auto subRoot = new TreeNode(2);
    subRoot->left = new TreeNode(11);
    subRoot->right = new TreeNode(10);

    cout << isSubtree(root, subRoot)<< endl;

    return 0;
}