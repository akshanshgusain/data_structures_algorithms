//
// Created by Akshansh Gusain on 05/01/22.
//
//https://www.geeksforgeeks.org/largest-independent-set-problem-dp-26/


//A subset of all tree nodes is an independent set if there is no edge between any two nodes of the subset.
//LISS(X) = MAX { (1 + sum of LISS for all grandchildren of X),
//                     (sum of LISS for all children of X) }

#include<stdc++.h>

using namespace std;

//The idea is simple, there are two possibilities for every node X, either X is a member of the set or not
// a member. If X is a member, then the value of LISS(X) is 1 plus LISS of all grandchildren. If X is not a
// member, then the value is sum of LISS of all children.

//class Node {
//public:
//    int data;
//    Node *left, *right;
//
//    Node(int data) {
//        this->data = data;
//        left = nullptr;
//        right = nullptr;
//    }
//};
//
//
//int LISS(Node *root) {
//    if (root == nullptr) {
//        return 0;
//    }
//
//    // Calculate size excluding the current node
//    int size_of_tree = LISS(root->left) + LISS(root->right);
//
//    // Calculate size including the current node
//    int size_incl = 1;
//    if (root->left)
//        size_incl += LISS(root->left->left) +
//                     LISS(root->left->right);
//    if (root->right)
//        size_incl += LISS(root->right->left) +
//                     LISS(root->right->right);
//
//
//    return max(size_incl, size_of_tree);
//
//}
//
//int main() {
//    Node *root = new Node(20);
//    root->left = new Node(8);
//    root->left->left = new Node(4);
//    root->left->right = new Node(12);
//    root->left->right->left = new Node(10);
//    root->left->right->right = new Node(14);
//    root->right = new Node(22);
//    root->right->right = new Node(25);
//
//    cout << LISS(root);
//    return 0;
//}


// Optimised: O(n), O(n)
class Node {
public:
    int data;
    int liss;
    Node *left, *right;

    explicit Node(int data) {
        this->data = data;
        this->liss = 0;
        left = nullptr;
        right = nullptr;
    }
};


int LISS(Node *root) {
    if (root == nullptr) {
        return 0;
    }

    // DP Check: If Sub Problem has already been solved then simply return
    if(root->liss){
        return root->liss;
    }

    if (root->left == nullptr && root->right == nullptr){
        return (root->liss = 1);
    }
    // Calculate size excluding the current node
    int size_of_tree = LISS(root->left) + LISS(root->right);

    // Calculate size including the current node
    int size_incl = 1;
    if (root->left)
        size_incl += LISS(root->left->left) +
                     LISS(root->left->right);
    if (root->right)
        size_incl += LISS(root->right->left) +
                     LISS(root->right->right);


    return max(size_incl, size_of_tree);

}

int main() {
    Node *root = new Node(20);
    root->left = new Node(8);
    root->left->left = new Node(4);
    root->left->right = new Node(12);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(14);
    root->right = new Node(22);
    root->right->right = new Node(25);

    cout << LISS(root);
    return 0;
}
