//
// Created by Akshansh Gusain on 28/01/22.
//

#include<stdc++.h>

using namespace std;

struct Node {
    char data;
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


void printInOrder(Node *root) {
    if (root == nullptr) {
        return;
    }

    if (root->left != nullptr) {
        printInOrder(root->left);
    }
    cout << root->data << " ";

    if (root->right != nullptr) {
        printInOrder(root->right);
    }
}

void inorder(int arr[], vector<int> &v, int n, int index) {

    if (index >= n) {
        return;
    }
    inorder(arr, v, n, 2 * index + 1);
    v.push_back(arr[index]);
    inorder(arr, v, n, 2 * index + 2);
}

int minSwaps(vector<int> &v) {
    vector<pair<int, int>> t(v.size());
    int ans = 0;

    for (int i = 0; i < v.size(); i++){
        t[i].first = v[i];
        t[i].second = i;
    }

    sort(t.begin(), t.end());

    for (int i = 0; i < t.size(); i++) {
        // second element is equal to i
        if (i == t[i].second)
            continue;
        else {
            // swapping of elements
            swap(t[i].first, t[t[i].second].first);
            swap(t[i].second, t[t[i].second].second);
        }

        // Second is not equal to i
        if (i != t[i].second)
            --i;
        ans++;
    }
    return ans;
}

int main() {
    // Complete BT
    int a[] = {5, 6, 7, 8, 9, 10, 11};
    int n = sizeof(a) / sizeof(a[0]);
    vector<int> v;

    // Find the IN-Order if given complete BT.
    inorder(a, v, n, 0);
    for (auto it: v) {
        cout << it << " ";
    }
    cout << minSwaps(v) << endl;
    return 0;
}