//
// Created by Akshansh Gusain on 12/03/21.
//Construct Binary Tree from String with bracket representation
#include<stdc++.h>

using namespace std;

struct Node {
    int data;
    Node *left, *right;
};

Node *newNode(int data) {
    Node *node = (Node *) malloc(sizeof(Node));
    node->data = data;
    node->left = node->right = NULL;
    return (node);
}

int findIndex(string str, int si, int ei) {
    if (si > ei) {
        return -1;
    }

    // Inbuilt stack
    stack<char> s;

    for (int i = si; i <= ei; i++) {

        // if open parenthesis, push it
        if (str[i] == '(')
            s.push(str[i]);

            // if close parenthesis
        else if (str[i] == ')') {
            if (s.top() == '(') {
                s.pop();

                // if stack is empty, this is
                // the required index
                if (s.empty())
                    return i;
            }
        }
    }
    // if not found return -1
    return -1;
}

Node *treeFromString(string str, int si, int ei) {
    //if starting index is greater than ending index
    if (si > ei)
        return nullptr;

    Node *root = newNode(str[si] - '0');
    int index = -1;

    //if the next char is '(' find the index of its complement ')'
    if (si + 1 <= ei && str[si + 1] == '(') {
        index = findIndex(str, si + 1, ei);
    }

    if (index != -1) {
        root->left = treeFromString(str, si + 2, index - 1);
        root->right = treeFromString(str, index + 2, ei - 1);
    }
    return root;
}

void preOrder(Node *node) {
    if (node == NULL)
        return;
    printf("%d ", node->data);
    preOrder(node->left);
    preOrder(node->right);
}


int main() {
    string str = "4(2(3)(1))(6(5))";
    Node *root = treeFromString(str, 0, str.length() - 1);
    preOrder(root);
    return 0;
}

