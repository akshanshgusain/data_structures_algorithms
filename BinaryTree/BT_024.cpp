//
// Created by Akshansh Gusain on 29/02/24.
//
#include "BT_000.cpp"


// 1. find the LCA
// 2. find distance of nodes from the LCA
TreeNode *findLCA(TreeNode *root, int n1, int n2) {
    if (root == nullptr or root->val == n1 or root->val == n2) {
        return root;
    }

    auto left = findLCA(root->left, n1, n2);
    auto right = findLCA(root->right, n1, n2);

    if (left == nullptr) {
        return right;
    } else if (right == nullptr) {
        return left;
    } else {
        return root;
    };
}

int findLevel(TreeNode *lca, int node, int level) {
    if(lca == nullptr){
        return -1;
    }
    if(node == lca->val){
        return level;
    }

    int left = findLevel(lca->left, node, level + 1);
    if(left != -1){
       return left;
    }

    return findLevel(lca->right, node, level + 1);
}

int findDistance(TreeNode *root, int n1, int n2) {
    auto LCA = findLCA(root, n1, n2);
    int d1 = findLevel(LCA, n1, 0);
    int d2 = findLevel(LCA, n2, 0);

    return d1 + d2;

}

int main() {
    auto root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    root->right->left->right = new TreeNode(8);

    cout << "Dist(4, 5) = " << findDistance(root, 4, 5);
    cout << "\nDist(4, 6) = " << findDistance(root, 4, 6);
    cout << "\nDist(3, 4) = " << findDistance(root, 3, 4);
    cout << "\nDist(2, 4) = " << findDistance(root, 2, 4);
    cout << "\nDist(8, 5) = " << findDistance(root, 8, 5);
    return 0;
}

//Dist(4, 5) = 2
//Dist(4, 6) = 4
//Dist(3, 4) = 3
//Dist(2, 4) = 1
//Dist(8, 5) = 5