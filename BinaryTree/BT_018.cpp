//
// Created by Akshansh Gusain on 25/01/22.
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


//Explanation: first pair of parenthesis contains
//left subtree and second one contains the right
//subtree. Preorder of above tree is "1 2 3".
//
//Input : "4(2(3)(1))(6(5))"
//Output : 4 2 3 1 6 5
//Explanation :
//           4
//         /   \
//        2     6
//       / \   /
//      3   1 5

int findIndex(string str, int startIndex, int endIndex) {
    if (startIndex > endIndex) {
        return -1;
    }

    stack<char> stack;

    for (int i = startIndex; i <= endIndex; i++) {

        // if open parenthesis, push it
        if (str[i] == '(') {
            stack.push(str[i]);
        }
            // if close parenthesis
        else if (str[i] == ')') {
            if (stack.top() == '(') {
                stack.pop();
                // if stack is empty, this is
                // the required index
                if (stack.empty()) {
                    return i;
                }
            }
        }
    }
    return -1;
}

Node* treeFromString(string input, int startIndex, int endIndex) {
    if (startIndex > endIndex) {
        return nullptr;
    }

    Node *root = new Node(input[startIndex] - '0');


    // if next char is '(' find the index of
    // its complement ')'
    int index = -1;
    if (startIndex + 1 <= endIndex && input[startIndex + 1] == '('){
        index = findIndex(input, startIndex + 1, endIndex);
    }


    // If the index is found
    if (index != -1) {
        root->left = treeFromString(input, startIndex + 2, index - 1);
        root->right = treeFromString(input, index + 2, endIndex - 1);
    }

    return root;
}

void preOrder(Node *root) {
    if (root == nullptr) {
        return;
    }
    cout << root->data << " ";
    if (root->left != nullptr) {
        preOrder(root->left);
    }

    if (root->right != nullptr) {
        preOrder(root->right);
    }
}

int main() {
    string str = "4(2(3)(1))(6(5))";
    int startIndex = 0, endIndex = str.length() - 1;
    Node *root = treeFromString(str, startIndex, endIndex);
    preOrder(root); //4 2 3 1 6 5
    return 0;
}
