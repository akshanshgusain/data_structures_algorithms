//
// Created by Akshansh Gusain on 18/01/22.
//

#include<stdc++.h>

using namespace std;

struct TreeNode {
    int data;
    struct TreeNode *left, *right;

    TreeNode() {
        data = 0;
        left = nullptr;
        right = nullptr;
    }

    explicit TreeNode(int key) {
        data = key;
        left = nullptr;
        right = nullptr;
    }

    TreeNode(int key, TreeNode *left, TreeNode *right) {
        data = key;
        this->left = left;
        this->right = right;
    }
};

//class TreeNode {
//public:
//    int data;
//    TreeNode *left, *right;
//
//    TreeNode() {
//        data = 0;
//        left = nullptr;
//        right = nullptr;
//    }
//
//    explicit TreeNode(int key) {
//        data = key;
//        left = nullptr;
//        right = nullptr;
//    }
//
//    TreeNode(int key, TreeNode *left, TreeNode *right) {
//        data = key;
//        this->left = left;
//        this->right = right;
//    }
//};

void printLevelOrder(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty()) {

        TreeNode *node = q.front();//print the front of the queue and remove it
        cout << node->data << " - ";
        q.pop();

        if (node->left != nullptr) {
            q.push(node->left);
        }
        if (node->right != nullptr) {
            q.push(node->right);
        }
    }
    cout<<endl;
}

int main() {
//    TreeNode *root = newNode(1);
    auto *root = new TreeNode(1);
    /* following is the tree after above statement
             1
       /           \
     nullptr     nullptr
    */

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    /* 2 and 3 become left and right children of 1
            1
      /           \
     2            3
    / \          / \
    NULL NULL NULL NULL
    */

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    /* 4 becomes left child of 2
         1
       /   \
      2     3
     / \    / \
    4   5 NULL NULL
    /   \
    NULL NULL
    */


    cout << " Level order traversal of Binary Tree is: \n";
    //1 - 2 - 3 - 4 - 5
    printLevelOrder(root);
    printLevelOrder(root);


    delete root;

    return 0;
}
