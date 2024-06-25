//
// Created by Akshansh Gusain on 30/12/21.
//
#include<stdc++.h>

using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int data) {
        this->data = data;
        left = right = nullptr;
    }
};

int solve(Node *root, int &res) {
    int l = solve(root->left, res);
    int r = solve(root->right, res);

    int temp = max(r, l) + 1;
    int ans = max(temp, r + l + 1);
    res = max(res, ans);

    return temp;
}

int main() {


    //solve(root, res);
    return 0;
}
