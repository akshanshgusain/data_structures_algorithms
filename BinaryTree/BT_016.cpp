//
// Created by Akshansh Gusain on 15/02/24.
//
#include "BT_000.cpp"

vector<int> topView(TreeNode *root) {
    vector<int> result;
    if (root == nullptr) {
        return result;
    }
    // pari<TreeNode, Horizontal-Distance>
    queue<pair<TreeNode *, int>> nodeQueue;
    // <Horizontal-Distance, TreeNode->val>
    map<int, int> map;
    nodeQueue.emplace(root, 0);
    while (!nodeQueue.empty()) {
        auto currentNode = nodeQueue.front().first;
        int currentHD = nodeQueue.front().second;
        nodeQueue.pop();

        if(map.find(currentHD) == map.end()){
            map[currentHD] = currentNode->val;
        }

        if (currentNode->left != nullptr) {
            nodeQueue.emplace(currentNode->left, currentHD - 1);
        }
        if (currentNode->right != nullptr) {
            nodeQueue.emplace(currentNode->right, currentHD + 1);
        }
    }

    for(auto it: map){
        result.push_back(it.second);
    }
    return result;
}

int main() {
    //                 1
    //             /      \
    //            2        3
    //         /   \      /   \
    //      4       5    6     7
    //            /   \
    //          8      9

    auto root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right->left = new TreeNode(8);
    root->left->right->right = new TreeNode(9);
    root->right->right = new TreeNode(7);
    root->right->left = new TreeNode(6);

    vector<int> traversal = topView(root);

    for (auto it: traversal) {
        cout << it << " ";
    }
    return 0;
}