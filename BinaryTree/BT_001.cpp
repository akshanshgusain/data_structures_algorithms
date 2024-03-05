//
// Created by Akshansh Gusain on 28/01/24.
//
#include "BT_000.cpp"

// time complexity is O(N)
// space complexity is O(W), where W is the maximum width (maximum number of nodes at any level) of the binary tree
vector<vector<int>> levelOrder(TreeNode* &root){
    vector<vector<int>> result;

    if(root == nullptr){
        return result;
    }

    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()){
        int levelSize = q.size();
        vector<int> currentLevel;

        for(int i = 0; i < levelSize; i++){
            auto node = q.front();
            q.pop();

            currentLevel.push_back(node->val);

            if(node->left!=nullptr){
                q.push(node->left);
            }
            if(node->right!=nullptr){
                q.push(node->right);
            }
        }

        result.push_back(currentLevel);
    }

    return result;
}

int main(){
    auto root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    vector<vector<int>> result = levelOrder(root);

    cout << "Level Order Traversal:\n";
    for (const auto& level : result) {
        for (int value : level) {
            std::cout << value << " ";
        }
        cout << endl;
    }

    return 0;
}