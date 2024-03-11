//
// Created by Akshansh Gusain on 28/01/24.
//
#include "BT_000.cpp"

vector<vector<int>> reverseLevelOrder(TreeNode *&root) {
    vector<vector<int>> result;

    if(root == nullptr){
        return result;
    }
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int levelSize = q.size();
        stack<int> currentLevel;  // Use a stack for reverse order

        for (int i = 0; i < levelSize; ++i) {
            TreeNode* node = q.front();
            q.pop();

            currentLevel.push(node->val);

            if (node->left) {
                q.push(node->left);
            }
            if (node->right) {
                q.push(node->right);
            }
        }

        // Pop elements from the stack to get reverse order
        vector<int> reverseOrder;
        while (!currentLevel.empty()) {
            reverseOrder.push_back(currentLevel.top());
            currentLevel.pop();
        }

        result.push_back(reverseOrder);


    }


    return result;
}

int main() {
    auto *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    // Get the reverse level-order traversal
    std::vector<std::vector<int>> result = reverseLevelOrder(root);

    // Print the result
    std::cout << "Reverse Level Order Traversal:\n";
    for (const auto &level: result) {
        for (int value: level) {
            std::cout << value << " ";
        }
        std::cout << "\n";
    }

    return 0;
}