//
// Created by Akshansh Gusain on 22/02/22.
//

#include<stdc++.h>

using namespace std;

struct Node {
    int data;
    struct Node *left, *right, *next;

    Node() {
        data = 0;
        left = nullptr;
        right = nullptr;
        next = nullptr;
    }

    explicit Node(int key) {
        data = key;
        left = nullptr;
        right = nullptr;
        next = nullptr;
    }

    __attribute__((unused)) Node(int key, Node *left, Node *right) {
        data = key;
        this->left = left;
        this->right = right;
        next = nullptr;
    }
};

/* Helper Functions */
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

vector<int> getInOrder(Node *root) {
    vector<int> inorder;
    Node *curr = root;
    while (curr != nullptr) {
        if (curr->left == nullptr) {
            inorder.push_back(curr->data);
            curr = curr->right;
        } else {
            Node *prev = curr->left;
            while (prev->right and prev->right != curr) {
                prev = prev->right;
            }
            if (prev->right == nullptr) {
                prev->right = curr;
                curr = curr->left;
            } else {
                prev->right = nullptr;
                inorder.push_back(curr->data);
                curr = curr->right;
            }
        }
    }

    return inorder;
}

vector<int> getPreOrder(Node *root) {
    vector<int> inorder;
    Node *curr = root;
    while (curr != nullptr) {
        if (curr->left == nullptr) {
            inorder.push_back(curr->data);
            curr = curr->right;
        } else {
            Node *prev = curr->left;
            while (prev->right and prev->right != curr) {
                prev = prev->right;
            }
            if (prev->right == nullptr) {
                prev->right = curr;
                inorder.push_back(curr->data);
                curr = curr->left;
            } else {
                prev->right = nullptr;
                curr = curr->right;
            }
        }
    }

    return inorder;
}

/* Helper Functions */

void storeNodes(Node *root, unordered_set<int> &allNodes, unordered_set<int> &allLeafNodes) {
    if (root == nullptr) {
        return;
    }

    allNodes.insert(root->data);

    if (root->left == nullptr and root->right == nullptr) {
        allLeafNodes.insert(root->data);
        return;
    }

    storeNodes(root->left, allNodes, allLeafNodes);
    storeNodes(root->right, allNodes, allLeafNodes);
}

bool isDeadEnd(Node *root) {
    if (root == nullptr) {
        return root;
    }

    unordered_set<int> allNodes, allLeafNodes;
    allNodes.insert(0);
    storeNodes(root, allNodes, allLeafNodes);

    for (auto it: allLeafNodes) {
        if (allNodes.find(it - 1) != allNodes.end() and allNodes.find(it + 1) != allNodes.end()) {
            return true;
        }
    }
    return false;
}


int main() {
    Node *root = nullptr;
    root = insertInBST(root, 8);
    insertInBST(root, 5);
    insertInBST(root, 2);
    insertInBST(root, 3);
    insertInBST(root, 7);
    insertInBST(root, 11);
    insertInBST(root, 4);

    if (isDeadEnd(root) == true)
        cout << "Yes " << endl;
    else
        cout << "No " << endl;
    return 0;
}
