//
// Created by Akshansh Gusain on 02/03/24.
//

#include "BT_000.cpp"

void getInorder(TreeNode* root, vector<int>& result) {
    if (root) {
        getInorder(root->left, result);
        result.push_back(root->val);
        getInorder(root->right, result);
    }
}

int findMinSwaps(TreeNode *root){
    vector<int> inorder;
    getInorder(root, inorder);

    int swaps = 0;
    vector<int> temp = inorder;
    int n = inorder.size();

    map<int, int> h;

    sort(temp.begin(), temp.end());
    for (int i = 0; i < n; i++) {
        h[inorder[i]] = i;
    }
    for (int i = 0; i < n; i++) {
        if (inorder[i] != temp[i]) {
            swaps++;
            int init = inorder[i];
            swap(inorder[i], inorder[h[temp[i]]]);
            h[init] = h[temp[i]];
            h[temp[i]] = i;
        }
    }
    return swaps;
}


int main(){
    auto root = new TreeNode(5);
    root->left = new TreeNode(6);
    root->left->left = new TreeNode(8);
    root->left->right = new TreeNode(9);
    root->right = new TreeNode(7);
    root->right->left = new TreeNode(10);
    root->right->right = new TreeNode(11);
    cout<< "Min swaps: "<<findMinSwaps(root);
    return 0;
}