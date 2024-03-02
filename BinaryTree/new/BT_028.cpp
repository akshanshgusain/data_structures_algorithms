//
// Created by Akshansh Gusain on 02/03/24.
//
#include "BT_000.cpp"

bool checkLeafNodes(TreeNode *root) {
    if (root == nullptr) {
        return true;
    }

    queue<TreeNode *> queue;
    queue.push(root);
    bool flag = false;
    while (!queue.empty()) {
        int levelSize = queue.size();

        for (int i = 0; i < levelSize; i++) {
            auto front = queue.front();
            queue.pop();

            if (front->left != nullptr) {
                queue.push(front->left);
            }
            if (front->right != nullptr) {
                queue.push(front->right);
            }

            if (front->left == nullptr and front->right == nullptr) {
                flag = true;
            }
        }
        if (flag and !queue.empty()) {
            flag = false;
            break;
        }
    }
    return flag;
}

int main() {
    auto root = new TreeNode(12);
    root->left = new TreeNode(5);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(9);
    root->left->left->left = new TreeNode(1);
    root->left->right->left = new TreeNode(1);
    root->left->right->left->right = new TreeNode(1);

    if (checkLeafNodes(root)){
        cout << "Leaves are at same level\n";
    }else{
        cout << "Leaves are not at same level\n";
    }

    return 0;
}