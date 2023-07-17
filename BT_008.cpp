//
// Created by Akshansh Gusain on 21/01/22.
//

//https://www.geeksforgeeks.org/print-binary-tree-vertical-order-set-2/
// Opti:
// https://www.geeksforgeeks.org/print-binary-tree-vertical-order/


// Time: O(w*n) where w is width of Binary Tree and n is number of nodes in Binary Tree.
// In worst case, the value of w can be O(n) (consider a complete tree for example)
// and time complexity can become O(n^2).
#include<stdc++.h>

using namespace std;

struct Node {
    int data;
    struct Node *left, *right;

    Node() {
        data = 0;
        left = nullptr;
        right = nullptr;
    }

    Node(int key) {
        data = key;
        left = nullptr;
        right = nullptr;
    }

    Node(int key, Node *left, Node *right) {
        data = key;
        this->left = left;
        this->right = right;
    }
};

void findMinMaxDistance(Node *root, int *minD, int *maxD, int hd) {
    if(root == nullptr){
        return;
    }
    if(hd < *minD){
        *minD = hd;
    }else if(hd >*maxD){
        *maxD = hd;
    }

    if(root->left != nullptr){
        findMinMaxDistance(root->left, minD, maxD, hd-1);
    }
    if(root->right != nullptr){
        findMinMaxDistance(root->right, minD, maxD, hd+1);
    }
}

void printVerticalLine(Node *root, int ln, int hd){
    if(root == nullptr){
        return;
    }

    if(ln == hd){
        cout<<root->data <<" ";
    }

    if(root->left != nullptr){
        printVerticalLine(root->left, ln, hd - 1);
    }

    if(root->right != nullptr){
        printVerticalLine(root->right, ln, hd + 1);
    }
}

void bottomView(Node *root) {

    // find the min and max distance from the root
    // min --> Minimum horizontal distance from root
    // max --> Maximum horizontal distance from root
    // hd  --> Horizontal distance of current node from root
    int minD = 0, maxD = 0 ,hd = 0;
    findMinMaxDistance(root, &minD, &maxD, hd);

    // Iterate through all possible vertical lines starting from the leftmost line and print node line by line
    for(int ln = minD; ln <= maxD; ln++){
        printVerticalLine(root, ln, hd);
        cout<<endl;
    }
}



/// Optimisation

// Time: O(NlogN)
void findMinMaxDistanceOptimised(Node *root,int hd, map < int,vector<int> > &m) {
    if(root == nullptr){
        return;
    }

    m[hd].push_back(root->data);
    if(root->left != nullptr){
        findMinMaxDistanceOptimised(root->left,  hd-1, m);
    }


    if(root->right != nullptr){
        findMinMaxDistanceOptimised(root->right,  hd+1, m);
    }
}


void verticalOrderOptimised(Node *root) {
    // hd  --> Horizontal distance of current node from root
    int hd = 0;

    // Create a map and store vertical order in map using
    map < int,vector<int> > m;

    findMinMaxDistanceOptimised(root, hd, m);

    //Traverse the map and print nodes at every horizontal
    for(auto it : m){
        for(int i : it.second){
            cout<<i<<" ";
        }
        cout<<endl;
    }
}


int main() {
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->left->right = new Node(8);
    root->right->right->right = new Node(9);
//    Node *root = new Node(1);
//    root->left = new Node(2);
//    root->right = new Node(3);
//    root->left->right = new Node(4);
//    root->left->right->right = new Node(5);
//    root->left->right->right->right = new Node(6);

    cout << "Vertical order traversal is \n";
    verticalOrderOptimised(root);

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