//
// Created by Akshansh Gusain on 24/03/24.
//
#include "BST_000.cpp"

// Time: O(N^2)
// Sol 1:

// Time: O(N)
// Sol 2: Find Next Greater Element


int main(){
    TreeNode *root = nullptr;
    root = insertInBST(root, 10);
    insertInBST(root, 5);
    insertInBST(root, 50);
    insertInBST(root, 1);
    insertInBST(root, 40);
    insertInBST(root, 100);

    vector<int> preorder2 = {5, 3, 4, 1, 6, 10};
    if (canRepresentBST(preorder2))
        cout << "\npreorder2 can represent BST";
    else
        cout << "\npreorder2 can not represent BST";
    return 0;
}