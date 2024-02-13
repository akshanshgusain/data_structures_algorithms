//
// Created by Akshansh Gusain on 11/02/24.
//
#include "BT_000.cpp"

vector<vector<int>> verticalOrderTraversal(TreeNode *&root) {
    map<int, map<int, multiset<int >>> nodes;
    queue<pair<TreeNode *, pair<int, int >>> queue;

    queue.push({root,{0,0}}); //initial vertical and level

    while (!queue.empty()) {
        auto p = queue.front();
        queue.pop();
        TreeNode *temp = p.first;

        //x -> vertical , y->level
        int x = p.second.first, y = p.second.second;
        nodes[x][y].insert(temp->val); //inserting to multiset

        if (temp->left) {
            queue.push({temp->left,{x - 1,y + 1}});
        }
        if (temp->right) {
            queue.push({temp->right,{x + 1,y + 1}});
        }
    }
    vector<vector<int >> ans;
    for (auto p: nodes) {
        vector<int> col;
        for (auto q: p.second) {
            col.insert(col.end(), q.second.begin(), q.second.end());
        }
        ans.push_back(col);
    }
    return ans;
}

int main() {
    auto *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    root->right->left->right = new TreeNode(8);
    root->right->right->right = new TreeNode(9);

    cout << "Vertical order traversal is \n";
    vector<vector<int>> vTraversal;
    vTraversal = verticalOrderTraversal(root);

    for (auto vertical: vTraversal) {
        for (auto nodeVal: vertical) {
            cout << nodeVal << " ";
        }
        cout << endl;
    }

    /*
     Vertical order traversal is
        4
        2
        1 5 6
        3 8
        7
        9
     */
    return 0;
}