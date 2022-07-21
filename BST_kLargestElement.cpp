//
// Created by Akshansh Gusain on 19/03/21.
//
#include<stdc++.h>

using namespace std;

struct Node {
    int key;
    Node *left, *right;
};

// A utility function to create a new BST node
Node *newNode(int item) {
    Node *temp = new Node;
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}


Node *insert(Node *node, int key) {
    /* If the tree is empty, return a new node */
    if (node == NULL) return newNode(key);

    /* Otherwise, recur down the tree */
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);

    /* return the (unchanged) node pointer */
    return node;
}

// A function to find k'th largest element in a given tree.
void kthLargestUtil(Node *root, int k, int &c) {
    // Base cases, the second condition is important to
    // avoid unnecessary recursive calls
    if (root == nullptr || c >= k)
        return;

    // Follow reverse inorder traversal so that the
    // largest element is visited first
    kthLargestUtil(root->right, k, c);

    // Increment count of visited nodes
    c++;

    // If c becomes k now, then this is the k'th largest
    if (c == k) {
        cout << "K'th largest element is "
             << root->key << endl;
        return;
    }

    // Recur for left subtree
    kthLargestUtil(root->left, k, c);
}

void kthLargest(Node *root, int k) {
    int c = 0;
    kthLargestUtil(root, k, c);
}

int main() {
    /* Let us create following BST
                 50
              /     \
             30      70
            /  \    /  \
          20   40  60   80 */
    Node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    int c = 0;
    for (int k = 1; k <= 7; k++)
        kthLargest(root, k);
    return 0;
}
