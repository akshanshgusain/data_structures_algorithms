//
// Created by Akshansh Gusain on 22/01/22.
//

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

void zigZagTraversal2(Node* root)
{
    deque<Node*> q;
    vector<int> v;
    q.push_back(root);
    v.push_back(root->data);
    Node* temp;

    // set initial level as 1, because root is
    // already been taken care of.
    int l = 1;

    while (!q.empty()) {
        int n = q.size();

        for (int i = 0; i < n; i++) {

            // popping mechanism
            if (l % 2 == 0) {
                temp = q.back();
                q.pop_back();
            }
            else {
                temp = q.front();
                q.pop_front();
            }

            // pushing mechanism
            if (l % 2 != 0) {

                if (temp->right) {
                    q.push_back(temp->right);
                    v.push_back(temp->right->data);
                }
                if (temp->left) {
                    q.push_back(temp->left);
                    v.push_back(temp->left->data);
                }
            }
            else if (l % 2 == 0) {

                if (temp->left) {
                    q.push_front(temp->left);
                    v.push_back(temp->left->data);
                }
                if (temp->right) {
                    q.push_front(temp->right);
                    v.push_back(temp->right->data);
                }
            }
        }
        l++; // level plus one
    }

    for(auto it: v){
        cout<<it<<" ";
    }
}



int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(7);
    root->left->right = new Node(6);
    root->right->left = new Node(5);
    root->right->right = new Node(4);

    zigZagTraversal2(root); // 1 3 2 7 6 5 4

    return 0;
}