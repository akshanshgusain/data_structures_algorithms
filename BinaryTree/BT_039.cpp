//
// Created by Akshansh Gusain on 05/03/24.
//

#include "BT_000.cpp"

bool isIsomorphic(TreeNode *root1, TreeNode *root2) {
    if (root1 == nullptr && root2 == nullptr) {
        return true;
    }
    if (root1 == nullptr || root2 == nullptr) {
        return false;
    }
    if (root1->val != root2->val) {
        return false;
    }

    // There are two possible cases for root1 and root2 to be isomorphic
    // Case 1: The subtrees rooted at these nodes have NOT been "Flipped".
    // Both of these subtrees have to be isomorphic, hence the &&
    // Case 2: The subtrees rooted at these nodes have been "Flipped"
    return
            (isIsomorphic(root1->left, root2->left) && isIsomorphic(root1->right, root2->right)) ||
            (isIsomorphic(root1->left, root2->right) && isIsomorphic(root1->right, root2->left));
}


int main() {
    // Let us create trees shown in above diagram
    auto n1 = new TreeNode(1);
    n1->left = new TreeNode(2);
    n1->right = new TreeNode(3);
    n1->left->left = new TreeNode(4);
    n1->left->right = new TreeNode(5);
    n1->right->left = new TreeNode(6);
    n1->left->right->left = new TreeNode(7);
    n1->left->right->right = new TreeNode(8);

    auto n2 = new TreeNode(1);
    n2->left = new TreeNode(3);
    n2->right = new TreeNode(2);
    n2->right->left = new TreeNode(4);
    n2->right->right = new TreeNode(5);
    n2->left->right = new TreeNode(6);
    n2->right->right->left = new TreeNode(8);
    n2->right->right->right = new TreeNode(7);

    if (isIsomorphic(n1, n2)) {
        cout << "Yes";
    } else {
        cout << "No";
    }


    return 0;
}