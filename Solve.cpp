#include<bits/stdc++.h>

#define int long long int
#define F first
#define S second
#define pb push_back
#define all(p) p.begin(), p.end()

using namespace std;
const int inf = 1e15;
const int M = 1e9 + 7;

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

Node *findMin(Node *root) {
    Node *temp = root;
    while (temp != nullptr and temp->left != nullptr) {
        temp = temp->left;
    }
    return temp;
}

Node *deleteNode(Node *root, int key) {
    if (root == nullptr) {
        return nullptr;
    }

    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        // 1. Leaf node
        if (root->left == nullptr and root->right == nullptr) {
            free(root);
            return nullptr;
        }

            // 2. Single Child
        else if (root->left == nullptr) {
            Node *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == nullptr) {
            Node *temp = root->left;
            free(root);
            return temp;
        }
            // 3. 2 Children

            Node *minNode = findMin(root->right);
            root->data = minNode->data;
            root->right = deleteNode(root->right, minNode->data);


    }
    return root;
}


void inOrder(Node *root) {
    if (root == nullptr) {
        return;
    }
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

Node *insertInBST(Node *root, int key) {
    if (root == nullptr) {
        return new Node(key);
    }

    if (root->data < key) {
        root->right = insertInBST(root->right, key);
    }
    else if (root->data > key) {
        root->left = insertInBST(root->left, key);
    }
    return root;

}

int32_t main() {


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
    cout << endl << endl;

    cout << "Case 1:Leaf Node: Delete 20" << endl;
    root = deleteNode(root, 20);
    cout << "Inorder traversal of the modified tree \n";
    inOrder(root);
    cout << endl << endl;

    cout << "Case 2:Node with one child:  Delete 30" << endl;
    root = deleteNode(root, 30);
    cout << "Inorder traversal of the modified tree \n";
    inOrder(root);
    cout << endl << endl;

    cout << "Case 3:Node with two children: Delete 50" << endl;
    root = deleteNode(root, 50);
    cout << "Inorder traversal of the modified tree \n";
    inOrder(root);
    cout << endl << endl;
    return 0;
}