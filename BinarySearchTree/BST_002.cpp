//
// Created by Akshansh Gusain on 07/03/24.
//
#include "BST_000.cpp"

void inOrderTraversal(TreeNode *root, TreeNode *key, TreeNode *successor) {
    if (root == nullptr) {
        return;
    }
    inOrderTraversal(root->left, key, successor);
    // need to find the first value that is greater that key
    if (root->val > key->val and successor->val == -1) {
        successor->val = root->val;
        return;
    }
    inOrderTraversal(root->right, key, successor);
}

TreeNode *binarySearchS(TreeNode *root, TreeNode *key) {
    TreeNode *successor = nullptr;

    while (root != nullptr) {
        if ( root->val <= key->val) {
            root = root->right;
        } else {
            successor = root;
            root = root->left;
        }
    }

    return successor;
}

TreeNode *binarySearchP(TreeNode *root, TreeNode *key) {
    TreeNode *successor = nullptr;

    while (root != nullptr) {
        if (key->val <= root->val) {
            root = root->left;
        } else {
            successor = root;
            root = root->right;
        }
    }

    return successor;
}




TreeNode *findInOrderSuccessor(TreeNode *root, TreeNode *key) {
    auto *successor = new TreeNode(-1);
//    inOrderTraversal(root, key, successor); // time: O(n)
//    return successor;
    return binarySearchS(root, key); // time: O(H)
}

TreeNode *findInOrderPredecessor(TreeNode *root, TreeNode *key) {
    auto *successor = new TreeNode(-1);
//    inOrderTraversal2(root, key, successor); // time: O(n)
//    return successor;
    return binarySearchP(root, key); // time: O(H)
}

int main() {
    TreeNode *root = nullptr;
    root = insertInBST(root, 50);
    insertInBST(root, 30);
    insertInBST(root, 20);
    insertInBST(root, 40);
    insertInBST(root, 70);
    insertInBST(root, 60);
    insertInBST(root, 80);

    TreeNode *temp = root->right->left;

    auto *successor = findInOrderSuccessor(root, temp);
    if (successor != nullptr) {
        cout << "Inorder Successor of " << temp->val << " is " << successor->val <<endl;
    } else {
        cout << "Inorder Successor doesn't exit"<<endl;
    }

//      Inorder Successor of 60 is 70
//      Inorder Predecessor of 60 is 50

    auto *predecessor = findInOrderPredecessor(root, temp);

    if (predecessor != nullptr) {
        cout << "Inorder predecessor of " << temp->val << " is " << predecessor->val<<endl;
    } else {
        cout << "Inorder predecessor doesn't exit"<<endl;
    }

    return 0;
}