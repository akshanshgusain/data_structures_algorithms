//
// Created by Akshansh Gusain on 13/02/24.
//
#include "BT_000.cpp"

vector<int> inorderMorisTraversal(TreeNode *&root) {
    vector<int> inorder;
    auto currentNode = root;

    while(currentNode != nullptr){
        // case 1: currentNode has no left tree
        if(currentNode->left == nullptr){
            inorder.push_back(currentNode->val);
            currentNode = currentNode->right;
        }else{
            // currentNode has a left subtree
            // go to the right most TreeNode of the left subtree
            auto nextNode  = currentNode->left;
            while(nextNode->right != nullptr and nextNode->right != currentNode){
                nextNode = nextNode->right;
            }

            // case 2: right most child is pointing to nullptr
            if(nextNode->right == nullptr){
                nextNode->right = currentNode;
                currentNode = currentNode->left;
            }else{
                // case 3: right most child is pointing to currentNode
                inorder.push_back(currentNode->val);
                nextNode->right = nullptr;
                currentNode = currentNode->right;
            }

        }
    }
    return inorder;
}

int main() {
    auto *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right->right = new TreeNode(6);

    vector<int> inorder;
    inorder = inorderMorisTraversal(root);

    cout << "The Inorder Traversal is: ";
    for (int i : inorder) {
        cout << i << " ";
    }
    // 4 2 5 6 1 3
    return 0;
}