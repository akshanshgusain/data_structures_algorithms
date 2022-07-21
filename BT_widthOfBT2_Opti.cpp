//
// Created by Akshansh Gusain on 10/03/21.
//
#include<stdc++.h>

using namespace std;

struct node {
    int data;
    struct node *left, *right;
};

struct node *newNode(int data) {
    auto *node
            = (struct node *) malloc(sizeof(struct node));
    node->data = data;
    node->left = nullptr;
    node->right = nullptr;

    return (node);
}

int height(node* root, int& ans)
{
    if (root == NULL)
        return 0;

    int left_height = height(root->left, ans);

    int right_height = height(root->right, ans);

    // update the answer, because diameter of a
    // tree is nothing but maximum value of
    // (left_height + right_height + 1) for each node
    ans = max(ans, 1 + left_height + right_height);

    return 1 + max(left_height, right_height);
}

int diameter(struct node* tree){
    if (tree == NULL)
        return 0;
    int ans = INT_MIN; // This will store the final answer
    height(tree, ans);
    return ans;
}


int main() {
    /* Constructed binary tree is
            1
            / \
        2     3
        / \
    4     5
    */
    struct node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    // Function Call
    cout << "Diameter of the given binary tree is " <<
         diameter(root);

    return 0;
}
