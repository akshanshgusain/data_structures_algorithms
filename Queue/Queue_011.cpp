//
// Created by Akshansh Gusain on 22/07/22.
//

//We traverse both trees simultaneously level by level. We store each level both trees in vectors (or array).
// To check if two vectors are anagram or not, we sort both and then compare.

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


bool areAnagrams(Node *root1, Node *root2){
    if(root1 == nullptr and root2 == nullptr){
        return true;
    }
    if(root1 == nullptr or root2 == nullptr){
        return false;
    }

    queue<Node*> q1,q2;
    q1.push(root1);
    q2.push(root2);

    while(true){
        int n1 = q1.size(), n2 = q2.size(); // no of nodes at current level
        if(n1 != n2){
            return false;
        }
        // If level order traversal is over
        if(n1 == 0){
            break;
        }

        //Dequeue all Nodes of current level and Enqueue all nodes of next level
        vector<int> curr_level1, curr_level2;
        while(n1>0){

            Node *node1 = q1.front();
            q1.pop();

            if(node1->left != nullptr){
                q1.push(node1->left);
            }
            if(node1->right != nullptr){
                q1.push(node1->right);
            }

            n1--;

            Node *node2 = q2.front();
            q2.pop();

            if(node2->left != nullptr){
                q2.push(node2->left);
            }
            if(node2->right != nullptr){
                q2.push(node2->right);
            }

            curr_level1.push_back(node1->data);
            curr_level2.push_back(node2->data);
        }

        sort(curr_level1.begin(), curr_level1.end());
        sort(curr_level2.begin(), curr_level2.end());
        if (curr_level1 != curr_level2)
            return false;
    }
    return true;
}


int main(){
    Node *root1 = new Node(1);
    root1->left = new Node(3);
    root1->right = new Node(2);
    root1->right->left = new Node(5);
    root1->right->right = new Node(4);

    Node* root2 = new Node(1);
    root2->left = new Node(2);
    root2->right = new Node(3);
    root2->left->left = new Node(4);
    root2->left->right = new Node(5);

    areAnagrams(root1, root2)? cout << "Yes" : cout << "No";

    return 0;
}