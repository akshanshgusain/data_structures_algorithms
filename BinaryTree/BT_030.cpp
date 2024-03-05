//
// Created by Akshansh Gusain on 04/03/24.
//
#include "BT_000.cpp"

unordered_map<string, vector<TreeNode *>> hashmap;
vector<TreeNode *> ans;

string findDuplicates(TreeNode *root) {
    if (root == nullptr) {
        return "";
    }

    string subtree = to_string(root->val) + ",";
    subtree += findDuplicates(root->left) + ",";
    subtree += findDuplicates(root->right);

    if(hashmap[subtree].size() == 1){
        ans.push_back(root);
    }

    hashmap[subtree].push_back(root);
    return subtree;
}

int main() {
    auto root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(4);
    root->right = new TreeNode(3);
    root->right->right = new TreeNode(4);
    root->right->left = new TreeNode(2);
    root->right->left->left = new TreeNode(4);

    findDuplicates(root);
    for(auto it : ans){
        cout<<it->val<<" ";
    }
    return 0;
}