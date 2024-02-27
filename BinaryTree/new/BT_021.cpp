//
// Created by Akshansh Gusain on 26/02/24.
//
#include "BT_000.cpp"

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

int main() {
    auto root = new TreeNode(1);
    root -> left = new TreeNode(2);
    root -> left -> left = new TreeNode(3);
    root -> left -> right = new TreeNode(4);
    root -> right = new TreeNode(5);
    root -> right -> right = new TreeNode(6);
    root -> right -> right -> left = new TreeNode(7);

    flatten(root);

    // Print the converted list
    printList(root); // 1 2 3 4 5 6 7
    return 0;
}