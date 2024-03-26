//
// Created by Akshansh Gusain on 19/03/24.
//
#include "BST_000.cpp"

// constant space: O(1)
// inorder morris traversal - reversed
void kthLargestElementOptimised(TreeNode* root, int k){
    auto currentNode = root;
    int counter = 0;
    int kthLargest = 0;

    while(currentNode != nullptr){
        // case 1: currentNode has no right tree
        if(currentNode->right == nullptr){
            // process current node
            counter++;
            if(counter == k){
                kthLargest = currentNode->val;
                break;
            }
            currentNode = currentNode->left;
        }else{
            // currentNode has a right subtree
            // go to the left most TreeNode of the right subtree
            auto nextNode  = currentNode->right;
            while(nextNode->left != nullptr and nextNode->left != currentNode){
                nextNode = nextNode->left;
            }

            // case 2: right most child is pointing to nullptr
            if(nextNode->left == nullptr){
                nextNode->left = currentNode;
                currentNode = currentNode->right;
            }else{
                // case 3: right most child is pointing to currentNode
                // process current node
                counter++;
                if(counter == k){
                    kthLargest = currentNode->val;
                    break;
                }
                nextNode->left = nullptr;
                currentNode = currentNode->left;
            }

        }
    }
    cout << k << "th Largest number: " << kthLargest << endl;
}

void kthLargestElement(TreeNode *root, int &counter, int k) {
    if (root == nullptr or counter >= k) {
        return;
    }
    kthLargestElement(root->right, counter, k);
    counter++;
    if (counter == k) {
        cout << k << "th Largest number: " << root->val << endl;
        return;
    }
    kthLargestElement(root->left, counter, k);
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

//    kthLargestElement(root, counter, 4);
    kthLargestElementOptimised(root, 3);

    return 0;
}