//
// Created by Akshansh Gusain on 15/02/24.
//
#include "BT_000.cpp"

void diagonalTraversalHelper(TreeNode *root, int diagonalDistance, map<int, vector<int>> &map){
    if(root == nullptr){
        return;
    }

    map[diagonalDistance].push_back(root->val);
    diagonalTraversalHelper(root->left, diagonalDistance+1, map);
    diagonalTraversalHelper(root->right, diagonalDistance, map);
}

vector<vector<int>> diagonalTraversal(TreeNode *&root){
    // <DiagonalDistance, vector<Node at tha diagonalDistance>>
    map<int, vector<int>> map;
    int diagonalDistance = 0;
    vector<vector<int>> result;

    diagonalTraversalHelper(root, diagonalDistance, map);

    for(auto it : map){
        vector<int> temp;
        for(auto node: it.second){
            temp.push_back(node);
        }
        result.push_back(temp);
    }
    return result;
}

int main(){
    auto root = new TreeNode(8);
    root->left = new TreeNode(3);
    root->right = new TreeNode(10);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(6);
    root->right->right = new TreeNode(14);
    root->right->right->left = new TreeNode(13);
    root->left->right->left = new TreeNode(4);
    root->left->right->right = new TreeNode(7);


    vector<vector<int>> traversal = diagonalTraversal(root);
    //Diagonal Traversal of binary tree :
    //8 10 14
    //3 6 7 13
    //1 4
    for(auto it: traversal){
        for(auto itt: it){
            cout<<itt<<" ";
        }
        cout<<endl;
    }
    return 0;
}