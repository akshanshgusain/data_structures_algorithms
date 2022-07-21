//
// Created by Akshansh Gusain on 17/02/22.
//
#include<stdc++.h>

using namespace std;

struct Node {
    int data;
    struct Node *left, *right;

    Node() {
        data = 0;
        left = nullptr;
        right = nullptr;
    }

    Node(int key) {
        data = key;
        left = nullptr;
        right = nullptr;
    }

    Node(int key, Node *left, Node *right) {
        data = key;
        this->left = left;
        this->right = right;
    }
};

Node *insertInBST(Node *head, int key) {
    if (head == nullptr) {
        return new Node(key);
    }

    if (key < head->data) {
        head->left = insertInBST(head->left, key);
    } else if (key > head->data) {
        head->right = insertInBST(head->right, key);
    }

    return head;
}

void inOrder(Node *head) {
    if (head == nullptr) {
        return;
    }
    inOrder(head->left);
    cout << head->data << " ";
    inOrder(head->right);
}

// Left-Most value will be the minimum
Node *minValue(Node *root) {
    Node *current = root;
    while(current != nullptr and current->left != nullptr){
        current = current->left;
    }
    return current;
}

Node *deleteNode(Node *root, int key) {
    if (root == nullptr) {
        return root;
    }

    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        /// Case 1: No Children - Leaf Node:
        if (root->left == nullptr and root->right == nullptr) {
            //free(root);
            return nullptr;
        }

            /// Case 2  Node with One child
        else if (root->left == nullptr) {
            Node *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == nullptr) {
            Node *temp = root->left;
            free(root);
            return temp;
        }

        /// Case 3: Node with Two children
        // get the inOrder Successor (Smallest value in the right subtree)
        // or ge the inOrder Predecessor (Largest Value in the Left subtree)
        Node *temp = minValue(root->right); // or Node *temp = maxValue(root->left)

        // Copy the inorder successor's content to this node
        root->data = temp->data;

        // Delete the inorder Successor
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

int main() {
    /* Let us create following BST
            50
         /      \
        30      70
     /    \    /   \
    20    40  60    80 */

    Node *root = nullptr;
    root = insertInBST(root, 50);
    insertInBST(root, 30);
    insertInBST(root, 20);
    insertInBST(root, 40);
    insertInBST(root, 70);
    insertInBST(root, 60);
    insertInBST(root, 80);

    cout << "Inorder traversal of the given tree \n";
    inOrder(root);
    cout<<endl<<endl;

    cout << "Case 1:Leaf Node: Delete 20" << endl;
    root = deleteNode(root, 20);
    cout << "Inorder traversal of the modified tree \n";
    inOrder(root);
    cout<<endl<<endl;

    cout << "Case 2:Node with one child:  Delete 30" << endl;
    root = deleteNode(root, 30);
    cout << "Inorder traversal of the modified tree \n";
    inOrder(root);
    cout<<endl<<endl;

    cout << "Case 3:Node with two children: Delete 50" << endl;
    root = deleteNode(root, 50);
    cout << "Inorder traversal of the modified tree \n";
    inOrder(root);
    cout<<endl<<endl;

    return 0;
}

/*

Inorder traversal of the given tree
20 30 40 50 60 70 80
Case 1:Leaf Node: Delete 20
Inorder traversal of the modified tree
20 30 40 50 60 70 80
Case 2:Node with one child:  Delete 30
Inorder traversal of the modified tree
20 40 50 60 70 80
Case 3:Node with two children: Delete 50
Inorder traversal of the modified tree
20 40 60 60 70 80

 */