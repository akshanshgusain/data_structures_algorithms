//
// Created by Akshansh Gusain on 18/03/21.
//
/*Method 2 ( O(n) time complexity )
The idea used here is inspired from method 3 of this post. The trick is to set a range {min .. max}
 for every node. Initialize the range as {INT_MIN .. INT_MAX}. The first node will definitely be in
 range, so create root node. To construct the left subtree, set the range as {INT_MIN …root->data}.
 If a values is in the range {INT_MIN .. root->data}, the values is part part of left subtree.
 To construct the right subtree, set the range as {root->data..max .. INT_MAX}.  */

#include<stdc++.h>

using namespace std;

class node {
public:
    int data;
    node *left;
    node *right;
};

// A utility function to create a node
node *newNode(int data) {
    node *temp = new node();

    temp->data = data;
    temp->left = temp->right = NULL;

    return temp;
}

void printInorder(node *node) {
    if (node == NULL)
        return;
    printInorder(node->left);
    cout << node->data << " ";
    printInorder(node->right);
}

node *constructTreeUtil(int pre[], int *preIndex, int key, int min, int max, int size) {
    if (*preIndex >= size) {
        return nullptr;
    }
    node* root = nullptr;
    // If current element of pre[] is in range, then
    // only it is part of current subtree
    if (key > min && key < max)
    {
        // Allocate memory for root of this
        // subtree and increment *preIndex
        root = newNode(key);
        *preIndex = *preIndex + 1;

        if (*preIndex < size)
        {
            // Construct the subtree under root
            // All nodes which are in range
            // {min .. key} will go in left
            // subtree, and first such node
            // will be root of left subtree.
            root->left = constructTreeUtil(pre, preIndex,
                                           pre[*preIndex],
                                           min, key, size);
        }
        if (*preIndex < size)
        {
            // All nodes which are in range
            // {key..max} will go in right
            // subtree, and first such node
            // will be root of right subtree.
            root->right = constructTreeUtil(pre, preIndex,
                                            pre[*preIndex],
                                            key, max, size);
        }
    }

    return root;
}

node *constructTree(int pre[], int size) {
    int preIndex = 0;
    return constructTreeUtil(pre, &preIndex, pre[0],INT_MIN, INT_MAX, size);
}

int main() {

    int pre[] = {10, 5, 1, 7, 40, 50};
    int size = sizeof(pre) / sizeof(pre[0]);

    node *root = constructTree(pre, size);

    cout << "Inorder traversal of the constructed tree: \n";
    printInorder(root);
    return 0;
}

