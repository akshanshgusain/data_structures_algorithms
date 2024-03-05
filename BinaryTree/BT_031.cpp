//
// Created by Akshansh Gusain on 04/03/24.
//
#include "BT_000.cpp"

bool areMirror(TreeNode *a, TreeNode *b) {
    if(a == nullptr and b == nullptr){
        return true;
    }

    if(a == nullptr or b == nullptr){
        return false;
    }

    return (a->val == b->val) and
            areMirror(a->left, b->right) and
            areMirror(a->right, b->left);
}

int main() {
    auto a = new TreeNode(1);
    auto b = new TreeNode(1);
    a->left = new TreeNode(2);
    a->right = new TreeNode(3);
    a->left->left = new TreeNode(4);
    a->left->right = new TreeNode(5);

    b->left = new TreeNode(3);
    b->right = new TreeNode(2);
    b->right->left = new TreeNode(5);
    b->right->right = new TreeNode(4);

    areMirror(a, b) ? cout << "Yes" : cout << "No";
    return 0;
}