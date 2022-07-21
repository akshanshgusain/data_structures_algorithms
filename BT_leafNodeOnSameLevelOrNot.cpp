//
// Created by Akshansh Gusain on 16/03/21.
//
#include<stdc++.h>

using namespace std;

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *newNode(int data) {
    struct Node *node = (struct Node *) malloc(sizeof(struct Node));
    node->data = data;
    node->left = nullptr;
    node->right = nullptr;
    return (node);
}

int ans = 1;

void solve(Node *root, int h, int &ma) {
    if (!root) {
        return;
    }
    if (ans == 0) {
        return;
    }
    if (!root->left && !root->right) {
        if (ma == -1) {
            ma = h;
        } else {
            if (h != ma) {
                ans = 0;
            }
        }
        return;
    }
    solve(root->left, h + 1, ma);
    solve(root->right, h + 1, ma);
}

bool check(Node *root) {
    int ma = -1;
    int h = 0;
    ans = 1;
    solve(root, h, ma);
    return ans;
}

int main() {
    struct Node *root = newNode(12);
    root->left = newNode(5);
    root->left->left = newNode(3);
    root->left->right = newNode(9);
    root->left->left->left = newNode(1);
    root->left->right->left = newNode(1);
    root->left->right->left->left = newNode(4);
    if (check(root))
        cout << "Leaves are at same level\n";
    else
        cout << "Leaves are not at same level\n";
    return 0;
}
