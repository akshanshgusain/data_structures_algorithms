//
// Created by Akshansh Gusain on 11/03/21.
// Print the Binary tree vertically - HashMap and recursion
/*
 *         1
        /    \
       2      3
      / \   /   \
     4   5  6   7
               /  \
              8   9


The output of print this tree vertically will be:
4
2
1 5 6
3 8
7
9
*/

#include<stdc++.h>
using namespace std;

struct Node
{
    int key;
    Node *left, *right;
};

struct Node* newNode(int key)
{
    struct Node* node = new Node;
    node->key = key;
    node->left = node->right = NULL;
    return node;
}

void getVerticalOrder(Node* root, int hd,  map<int,vector<int>> &map){
    if(root == nullptr){
        return;
    }

    map[hd].push_back(root->key);
    getVerticalOrder(root->left, hd-1, map);
    getVerticalOrder(root->right, hd+1, map);
}

void printVerticalOrder(Node* root){
    map<int, vector<int>> map; // vertical Distance, vector<Nodes>
    int hd = 0 ;
    getVerticalOrder(root, hd, map);

    //traverse the map and print nodes at every horizontal distance
    //map<int,vector<int>> :: iterator it;
    for (auto it=map.begin(); it!=map.end(); it++)
    {
        for (int i=0; i<it->second.size(); ++i)
            cout << it->second[i] << " ";
        cout << endl;
    }

}
int main(){

    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->left->right = newNode(8);
    root->right->right->right = newNode(9);
    cout << "Vertical order traversal is n";

    printVerticalOrder(root);
    return 0;
}
