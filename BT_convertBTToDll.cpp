//
// Created by Akshansh Gusain on 12/03/21.
//
/*The left and right pointers in nodes are to be used as previous and next pointers respectively in converted DLL.
 * The order of nodes in DLL must be same as Inorder of the given Binary Tree.*/
//LNR

#include<stdc++.h>

using namespace std;

class node {
public:
    int data;
    node *left;
    node *right;
};

node *newNode(int data) {
    node *new_node = new node();
    new_node->data = data;
    new_node->left = new_node->right = nullptr;
    return (new_node);
}

void inorder(node *root) {
    if (root != NULL) {
        inorder(root->left);
        cout << "\t" << root->data;
        inorder(root->right);
    }
}

void printList(node *node) {
    while (node != nullptr) {
        cout << node->data << " ";
        node = node->right;
    }
}

void fixPrevPtr(node *root){
    static node *pre = nullptr;
    if(!root){
        fixPrevPtr(root->left);
        root->left = pre;
        pre = root;
        fixPrevPtr(root->right);
    }
}
node *fixNextPtr(node *root)
{
    node *prev = NULL;

    // Find the right most node
    // in BT or last node in DLL
    while (root && root->right != NULL)
        root = root->right;

    // Start from the rightmost node,
    // traverse back using left pointers.
    // While traversing, change right pointer of nodes.
    while (root && root->left != NULL)
    {
        prev = root;
        root = root->left;
        root->right = prev;
    }

    // The leftmost node is head
    // of linked list, return it
    return (root);
}

node *BTToDLL(node *root){
    fixPrevPtr(root);
    return fixNextPtr(root);
}

int main() {
    node *root = newNode(10);
    root->left = newNode(12);
    root->right = newNode(15);
    root->left->left = newNode(25);
    root->left->right = newNode(30);
    root->right->left = newNode(36);

    cout << "\n\t\tInorder Tree Traversal\n\n";
    inorder(root);

    node *head = BTToDLL(root);

    cout << "\n\n\t\tDLL Traversal\n\n";
    printList(head);
    return 0;
}
