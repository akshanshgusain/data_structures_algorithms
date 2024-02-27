//
// Created by Akshansh Gusain on 27/02/24.
//
#include "BT_000.cpp"

TreeNode *buildTreeHelper
        (vector<int> &preorder, vector<int> &inorder,
         int preStart, int preEnd, int inStart, int inEnd,
         map<int, int> &map) {

    if (preStart > preEnd || inStart > inEnd) {
        return nullptr;
    }

    auto root = new TreeNode(preorder[preStart]);
    int elem = map[root->val]; // get index of root in inorder
    int nElem = elem - inStart;

    root -> left = buildTreeHelper(preorder, inorder, preStart + 1, preStart + nElem,
                                 inStart, elem - 1, map);

    root -> right = buildTreeHelper(preorder, inorder,preStart + nElem + 1, preEnd,
                                  elem + 1, inEnd, map);
    return root;
}

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    int preStart = 0, preEnd = preorder.size() - 1;
    int inStart = 0, inEnd = inorder.size() - 1;

    map<int, int> map; // <element, index>
    for (int i = inStart; i <= inEnd; i++) {
        map[inorder[i]] = i;
    }

    return buildTreeHelper(preorder, inorder, preStart, preEnd, inStart, inEnd, map);
}

int main() {
    vector<int> preorder{10, 20, 40, 50, 30, 60};
    vector<int> inorder{40, 20, 50, 10, 60, 30};
    auto root = buildTree(preorder, inorder);
    delete root;
    return 0;
}