//
// Created by Akshansh Gusain on 17/02/22.
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

struct Info {
    int sz; // Size of subtree
    int max; // Min value in subtree
    int min; // Max value in subtree
    int ans; // Size of largest BST which
    // is subtree of current node
    bool isBST; // If subtree is BST
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

Info largestBST(Node *root) {
    // Base cases : When tree is empty or it has
    // one child.
    if (root == nullptr) {
        return {0, INT_MIN, INT_MAX, 0, true};
    }
    if (root->left == nullptr and root->right == nullptr) {
        return {1, root->data, root->data, 1, true};
    }

    Info left = largestBST(root->left);
    Info right = largestBST(root->right);

    Info result;
    result.sz = (1 + left.sz + right.sz);

    // If whole tree rooted under current root is
    // BST.
    if (left.isBST && right.isBST && left.max < root->data &&
        right.min > root->data)
    {
        result.min = min(left.min, min(right.min, root->data));
        result.max = max(right.max, max(left.max, root->data));

        // Update answer for tree rooted under
        // current 'root'
        result.ans = result.sz;
        result.isBST = true;

        return result;
    }

    // If whole tree is not BST, return maximum
    // of left and right subtrees
    result.ans = max(left.ans, right.ans);
    result.isBST = false;

    return result;

}

/* A tree is a BST is at every node x:
 * 1. The largest value in the left Subtree of x is smaller than the value of x.
 * 2. The smallest value in the right Subtree of x is larger than the value of x*/

int main() {
//    Node *root = nullptr;
//    root = insertInBST(root, 60);
//    insertInBST(root, 65);
//    insertInBST(root, 70);
//    insertInBST(root, 50);
    Node *root = new Node(60);
    root->left = new Node(65);
    root->right = new Node(70);
    root->left->left = new Node(50);
    cout << largestBST(root).ans;

    return 0;
}
