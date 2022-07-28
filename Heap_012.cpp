//
// Created by Akshansh Gusain on 28/07/22.
//


//https://www.geeksforgeeks.org/check-if-a-given-binary-tree-is-heap/
// Completeness: https://www.geeksforgeeks.org/check-whether-binary-tree-complete-not-set-2-recursive-solution/

#include<bits/stdc++.h>
using namespace std;

struct Node {
    int key;
    struct Node *left;
    struct Node *right;
};

struct Node *newNode(int k) {
    struct Node *node = new Node;
    node->key = k;
    node->right = node->left = NULL;
    return node;
}

unsigned int countNodes(struct Node *root) {
    if (root == NULL)
        return (0);
    return (1 + countNodes(root->left)
            + countNodes(root->right));
}

bool isCompleteUtil(struct Node *root,
                    unsigned int index,
                    unsigned int number_nodes) {
    // An empty tree is complete
    if (root == NULL)
        return (true);

    // If index assigned to
    // current node is more than
    // number of nodes in tree,
    // then tree is not complete
    if (index >= number_nodes)
        return (false);

    // Recur for left and right subtrees
    return (isCompleteUtil(root->left, 2 * index + 1,
                           number_nodes) &&
            isCompleteUtil(root->right, 2 * index + 2,
                           number_nodes));
}

bool isHeapUtil(struct Node *root) {
    //  Base case : single
    // If Node has No child then it’s a leaf node and returns true
    if (root->left == NULL && root->right == NULL){
        return (true);
    }

    //  If Node has one child (it must be left child because it is a complete tree) then we need to compare this
    //  node with its single child only.
    if (root->right == NULL) {
        //  check heap property at Node
        //  No recursive call ,
        // because no need to check last level
        return (root->key >= root->left->key);
    }
        // If the Node has both child then check heap property at Node at recur for both subtrees
    else {
        //  Check heap property at Node and
        //  Recursive check heap
        // property at left and right subtree
        if (root->key >= root->left->key &&
            root->key >= root->right->key){
            return ((isHeapUtil(root->left)) &&
                    (isHeapUtil(root->right)));
        }

        else{
            return (false);
        }

    }
}

bool isHeap(struct Node *root) {
    //Given a binary tree, we need to check it has heap property or not,
    // Binary tree need to fulfill the following two conditions for being a heap –

    //1. It should be a complete tree (i.e. all levels except last should be full).
    //2 .Every node’s value should be greater than or equal to its child node (considering max-heap).
    unsigned int node_count = countNodes(root);
    unsigned int index = 0;

    if (isCompleteUtil(root, index, node_count)
        && isHeapUtil(root)) {
        return true;
    }

    return false;
}

int main() {
    struct Node *root = NULL;
    root = newNode(10);
    root->left = newNode(9);
    root->right = newNode(8);
    root->left->left = newNode(7);
    root->left->right = newNode(6);
    root->right->left = newNode(5);
    root->right->right = newNode(4);
    root->left->left->left = newNode(3);
    root->left->left->right = newNode(2);
    root->left->right->left = newNode(1);

    // Function call
    if (isHeap(root))
        cout << "Given binary tree is a Heap\n";
    else
        cout << "Given binary tree is not a Heap\n";
    return 0;
}

