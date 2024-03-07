//
// Created by Akshansh Gusain on 07/03/24.
//
#include "BST_000.cpp"


// Thread binary tree

vector<int> getInOrder(TreeNode *root) {
    vector<int> inorder;
    auto *curr = root;
    while (curr != nullptr) {
        if (curr->left == nullptr) {
            inorder.push_back(curr->val);
            curr = curr->right;
        } else {
            auto *prev = curr->left;
            while (prev->right and prev->right != curr) {
                prev = prev->right;
            }
            if (prev->right == nullptr) {
                prev->right = curr;
                curr = curr->left;
            } else {
                prev->right = nullptr;
                inorder.push_back(curr->val);
                curr = curr->right;
            }
        }
    }

    return inorder;
}

vector<int> getPreOrder(TreeNode *root) {
    vector<int> inorder;
    auto *curr = root;
    while (curr != nullptr) {
        if (curr->left == nullptr) {
            inorder.push_back(curr->val);
            curr = curr->right;
        } else {
            auto *prev = curr->left;
            while (prev->right and prev->right != curr) {
                prev = prev->right;
            }
            if (prev->right == nullptr) {
                prev->right = curr;
                inorder.push_back(curr->val);
                curr = curr->left;
            } else {
                prev->right = nullptr;
                curr = curr->right;
            }
        }
    }

    return inorder;
}


int main() {
    TreeNode *root = nullptr;
    root = insertInBST(root, 5);
    insertInBST(root, 3);
    insertInBST(root, 7);
    insertInBST(root, 2);
    insertInBST(root, 4);
    insertInBST(root, 6);
    insertInBST(root, 8);

    vector<int> ino = getInOrder(root);
    for (auto it: ino) {
        cout << it << " ";
    }
    vector<int> preo = getPreOrder(root);
    cout << endl;
    for (auto it: preo) {
        cout << it << " ";
    }

    return 0;
}