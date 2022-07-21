//
// Created by Akshansh Gusain on 11/03/21.
//
#include<stdc++.h>

using namespace std;

class node {
public:
    int data;
    node *left;
    node *right;
};

node *newNode(int data) {
    node *Node = new node();
    Node->data = data;
    Node->left = NULL;
    Node->right = NULL;
    return (Node);
}

//int height(node *node) {
//    /* base case tree is empty */
//    if (node == NULL)
//        return 0;
//
//    /* If tree is not empty then
//    height = 1 + max of left
//        height and right heights */
//    return 1 + max(height(node->left),
//                   height(node->right));
//}
//
//bool isBalanced(node *root) {
//    int lh, rh;
//    if (!root)
//        return 1;
//    lh = height(root->left);
//    rh = height(root->right);
//
//    if(abs(lh-rh) <= 1 && isBalanced(root->left) && isBalanced(root->right)){
//        return 1;
//    }
//    return 0;
//}
//
//int main() {
//    node *root = newNode(1);
//    root->left = newNode(2);
//    root->right = newNode(3);
//    root->left->left = newNode(4);
//    root->left->right = newNode(5);
//    root->left->left->left = newNode(8);
//
//    if (isBalanced(root))
//        cout << "Tree is balanced";
//    else
//        cout << "Tree is not balanced";
//    return 0;
//}
/*Above implementation can be optimized by calculating the height in the same recursion rather than calling
 * a height() function separately. */

bool isBalanced(node *root, int *height) {

    /* lh --> Height of left subtree
    rh --> Height of right subtree */
    int lh = 0, rh = 0;

    /* l will be true if left subtree is balanced
    and r will be true if right subtree is balanced */
    int l = 0, r = 0;

    if (root == NULL) {
        *height = 0;
        return 1;
    }

    /* Get the heights of left and right subtrees in lh and rh
    And store the returned values in l and r */
    l = isBalanced(root->left, &lh);
    r = isBalanced(root->right, &rh);

    /* Height of current node is max of heights of left and
    right subtrees plus 1*/
    *height = (lh > rh ? lh : rh) + 1;

    /* If difference between heights of left and right
    subtrees is more than 2 then this node is not balanced
    so return 0 */
    if (abs(lh - rh) >= 2)
        return 0;

        /* If this node is balanced and left and right subtrees
        are balanced then return true */
    else
        return l && r;
}

int main() {
    int height = 0;

    /* Constructed binary tree is
            1
            / \
            2 3
            / \ /
            4 5 6
            /
            7
    */
    node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->left->left->left = newNode(7);

    if (isBalanced(root, &height))
        cout << "Tree is balanced";
    else
        cout << "Tree is not balanced";

    return 0;
}