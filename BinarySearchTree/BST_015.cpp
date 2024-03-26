//
// Created by Akshansh Gusain on 19/03/24.
//›
#include "BST_000.cpp"

int findMedian(TreeNode *root) {
    vector<int> inorder;
    buildInOrderArray(root, inorder);
    int median = 0;

    int inOrderSize = inorder.size();

    if (inOrderSize % 2 == 0) {
        median = (inorder[(inOrderSize - 1) / 2] + inorder[(inOrderSize - 1) / 2 + 1]) / 2;
    } else {
        median = inorder[(inOrderSize - 1) / 2];
    }

    return median;
}

int countNodes(TreeNode *root) {
    int count = 0;
    if (root == nullptr) {
        return count;
    }
    auto *curr = root;
    while (curr != nullptr) {
        if (curr->left == nullptr) {
            count++;
            curr = curr->right;
        } else {
            auto *prev = curr->left;
            while (prev->right and prev->right != curr) {
                prev = prev->right;
            }
            if (prev->right == nullptr) {
                prev->right = curr;
                curr = curr->left;
            } else {
                prev->right = nullptr;
                count++;
                curr = curr->right;
            }
        }
    }
    return count;
}

// O(1) space,
int findMedianOptimised(TreeNode *root) {
    if (root == nullptr) {
        return 0;
    }
    int count = countNodes(root);
    int currCount = 0;
    TreeNode *curr = root, *prev, *extra;

    while (curr != nullptr) {
        if (curr->left == nullptr) {
            // process node

            // count curr node
            currCount++;
            // check if curr node is the median
            // Odd case and even cases
            if (count % 2 != 0 && currCount == (count + 1) / 2) {
                return curr->val;
            } else if (count % 2 == 0 && currCount == (count / 2) + 1) {
                return (extra->val + curr->val) / 2;
            }
            // Update extra for even no. of nodes
            extra = curr;

            curr = curr->right;
        } else {
            prev = curr->left;
            while (prev->right != nullptr && prev->right != curr) {
                prev = prev->right;
            }
            if (prev->right == nullptr) {
                prev->right = curr;
                curr = curr->left;
            } else {
                prev->right = nullptr;

                // process the node
                extra = prev;
                currCount++;
                if (count % 2 != 0 && currCount == (count + 1) / 2) {
                    return curr->val;
                } else if (count % 2 == 0 && currCount == (count / 2) + 1) {
                    return (extra->val + curr->val) / 2;
                }

                extra = curr;
                curr = curr->right;
            }
        }
    }
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


//    cout << findMedian(root);
    cout << findMedianOptimised(root);

    return 0;
}