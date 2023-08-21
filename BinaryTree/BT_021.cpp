//
// Created by Akshansh Gusain on 28/01/22.
//

#include<stdc++.h>
#include "BT.cpp"

using namespace std;


void printInOrder(TreeNode *root) {
    if (root == nullptr) {
        return;
    }

    if (root->left != nullptr) {
        printInOrder(root->left);
    }
    cout << char(root->data) << " ";

    if (root->right != nullptr) {
        printInOrder(root->right);
    }
}

TreeNode *buildTree(vector<char> &preOrder, int preStart, int preEnd,
                    vector<char> &inOrder, int inStart, int inEnd, unordered_map<int, int> &inMap) {
    if (preStart > preEnd || inStart > inEnd) {
        return nullptr;
    }

    TreeNode *root = new TreeNode(preOrder[preStart]);

    int inRoot = inMap[root->data];
    int numsLeft = inRoot - inStart;// # of elements after preOrder[preStart] will form the new preorder

    root->left = buildTree(preOrder, preStart + 1, preStart + numsLeft,
                           inOrder, inStart, inRoot - 1, inMap);
    root->right = buildTree(preOrder, preStart + numsLeft + 1, preEnd,
                            inOrder, inRoot + 1, inEnd, inMap);

    return root;

}

int main() {
    vector<char> in = {'D', 'B', 'E', 'A', 'F', 'C'};
    vector<char> pre = {'A', 'B', 'D', 'E', 'C', 'F'};
    unordered_map<int, int> inMap;

    for (int i = 0; i < in.size(); i++) {
        inMap[in[i]] = i;
    }

    TreeNode *root = buildTree(pre, 0, int(pre.size()) - 1,
                               in, 0, int(in.size()) - 1,
                               inMap);


    cout << "Inorder traversal of the constructed tree is \n";
    printInOrder(root); //D B E A F C
    return 0;
}