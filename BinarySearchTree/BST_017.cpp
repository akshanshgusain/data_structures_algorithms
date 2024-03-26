//
// Created by Akshansh Gusain on 24/03/24.
//
#include "BST_000.cpp"

void printList(TreeNode *node) {
    while (node != nullptr) {
        cout << node->val << " ";
        node = node->right;
    }
}

// Morris traversal
void flatten(TreeNode *root) {
    auto current = root;
    while(current != nullptr){
        if(current->left != nullptr){
            auto previous = current->left;
            while(previous->right != nullptr){
                previous = previous->right;
            }

            previous->right = current->right;
            current->right = current->left;
            current->left = nullptr;
        }
        current = current->right;
    }
}

int main(){
    TreeNode *root = nullptr;
    root = insertInBST(root, 5);
    insertInBST(root, 3);
    insertInBST(root, 7);
    insertInBST(root, 2);
    insertInBST(root, 4);
    insertInBST(root, 6);
    insertInBST(root, 8);

    flatten(root);
    printList(root);

    return 0;
}