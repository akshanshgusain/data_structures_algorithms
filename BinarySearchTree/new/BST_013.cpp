//
// Created by Akshansh Gusain on 19/03/24.
//
#include "BST_000.cpp"

// constant space: O(1)
// inorder morris traversal
void kthLargestElementOptimised(TreeNode* root, int k){

    auto currentNode = root;
    int counter = 0;

    while(currentNode != nullptr){
        // case 1: currentNode has no left tree
        if(currentNode->left == nullptr){
            // process current node
            counter++;
            if(counter == k){
                cout << k << "th Largest number: " << root->val << endl;
            }
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
                // process current node
                counter++;
                if(counter == k){
                    cout << k << "th Largest number: " << root->val << endl;
                }
                nextNode->right = nullptr;
                currentNode = currentNode->right;
            }

        }
    }
}

void kthLargestElement(TreeNode *root, int &counter, int k) {
    if (root == nullptr or counter >= k) {
        return;
    }

    kthLargestElement(root->left, counter, k);
    counter++;
    if (counter == k) {
        cout << k << "th Largest number: " << root->val << endl;
        return;
    }
    kthLargestElement(root->right, counter, k);
}

int main() {
    TreeNode *root = nullptr;
    root = insertInBST(root, 50);
    insertInBST(root, 30);
    insertInBST(root, 20);
    insertInBST(root, 40);
    insertInBST(root, 70);
    insertInBST(root, 60);
    insertInBST(root, 80);
    int counter = 0;

    kthLargestElement(root, counter, 4);
    kthLargestElementOptimised(root, 4);

    return 0;
}