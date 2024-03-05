//
// Created by Akshansh Gusain on 11/02/24.
//
#include "BT_000.cpp"

vector<vector<int>> zigZagTraversal(TreeNode *&root) {
    vector<vector<int >> result;
    if (root == nullptr) {
        return result;
    }

    queue<TreeNode *> nodesQueue;
    nodesQueue.push(root);
    bool leftToRight = true;

    while (!nodesQueue.empty()) {
        int size = nodesQueue.size();
        vector<int> row(size);

        for (int i = 0; i < size; i++) {
            TreeNode *node = nodesQueue.front();
            nodesQueue.pop();

            // find position to fill node's value
            // either insert from the front(i) or the back (size-1-i)
            int index = (leftToRight) ? i : (size - 1 - i);

            row[index] = node->val;

            if (node->left) {
                nodesQueue.push(node->left);
            }
            if (node->right) {
                nodesQueue.push(node->right);
            }
        }
        // after this level
        leftToRight = !leftToRight;
        result.push_back(row);
    }
    return result;
}

int main() {
    auto *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(7);
    root->left->right = new TreeNode(6);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(4);

    vector<vector<int>> traversal = zigZagTraversal(root); // 1 3 2 7 6 5 4
    for (auto it: traversal) {
        for (auto i: it) {
            cout << i << " ";
        }
    }
    return 0;
}