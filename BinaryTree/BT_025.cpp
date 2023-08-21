//
// Created by Akshansh Gusain on 01/02/22.
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

//The idea is based on the fact that inorder and preorder/postorder uniquely identify a binary tree.
//Tree S is a subtree of T if both inorder and preorder traversals of S are substrings of inorder and preorder
// traversals of T respectively.

//1) Find inorder and preorder traversals of T, store them in two auxiliary arrays inT[] and preT[].
//2) Find inorder and preorder traversals of S, store them in two auxiliary arrays inS[] and preS[].
//3) If inS[] is a subarray of inT[] and preS[] is a subarray preT[], then S is a subtree of T. Else not.

void computeLPSArray(vector<char> &pat, int M, vector<int> &lps) {
    // length of the previous longest prefix suffix
    int len = 0;

    lps[0] = 0; // lps[0] is always 0

    // the loop calculates lps[i] for i = 1 to M-1
    int i = 1;
    while (i < M) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        } else // (pat[i] != pat[len])
        {
            // This is tricky. Consider the example.
            // AAACAAAA and i = 7. The idea is similar
            // to search step.
            if (len != 0) {
                len = lps[len - 1];

                // Also, note that we do not increment
                // i here
            } else // if (len == 0)
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

bool KMP(vector<char> inT, vector<char> inS) {
    int n = inT.size();
    int m = inS.size();
    // create lps[] that will hold the longest prefix suffix
    // values for pattern
    vector<int> lps(m, 0);

    // Preprocess the pattern (calculate lps[] array)
    computeLPSArray(inS, m, lps);
    int i = 0; // index for txt[]
    int j = 0; // index for pat[]
    while (i < n) {
        if (inS[j] == inT[i]) {
            j++;
            i++;
        }

        if (j == m) {
            cout << "Found pattern at index %d " << i - j;
            return true;
            j = lps[j - 1];
        }

            // mismatch after j matches
        else if (i < n && inS[j] != inT[i]) {
            // Do not match lps[0..lps[j-1]] characters,
            // they will match anyway
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }
    return false;
}

void storeInOrder(Node *root, vector<char> &in) {
    if (root == nullptr) {
        in.push_back('$');
        return;
    }

    storeInOrder(root->left, in);
    in.push_back(root->data);
    storeInOrder(root->right, in);
}

void storePreOrder(Node *root, vector<char> &in) {
    if (root == nullptr) {
        in.push_back('$');
        return;
    }

    in.push_back(root->data);
    storeInOrder(root->left, in);
    storeInOrder(root->right, in);
}


bool isSubTree(Node *T, Node *S) {
    if (T == nullptr) {
        return false;
    }
    if (S == nullptr) {
        return true;
    }
    // Store InOrder Traversal
    vector<char> inT, inS;
    storeInOrder(T, inT);
    storeInOrder(S, inS);
    inT.push_back('\0');
    inS.push_back('\0');

    // check for sub-string matching
    if (!KMP(inT, inS)) {
        return false;
    }

    // Store PreOrder Traversal
    vector<char> preT, preS;
    storePreOrder(T, preT);
    storePreOrder(S, preS);
    preT.push_back('\0');
    preS.push_back('\0');

    return KMP(preT, preS);
}


int main() {
//    Node *T = new Node('a');
//    T->left = new Node('b');
//    T->right = new Node('d');
//    T->left->left = new Node('c');
//    T->right->right = new Node('e');
//
//    Node *S = new Node('a');
//    S->left = new Node('b');
//    S->left->left = new Node('c');
//    S->right = new Node('d');

    // TREE 1
    /* Construct the following tree
            26
            / \
        10 3
        / \ \
    4 6 3
    \
        30
    */
    Node *T = new Node(26);
    T->right = new Node(3);
    T->right->right = new Node(3);
    T->left = new Node(10);
    T->left->left = new Node(4);
    T->left->left->right = new Node(30);
    T->left->right = new Node(6);

    // TREE 2
    /* Construct the following tree
        10
        / \
    4 6
    \
        30
    */
    Node *S = new Node(10);
    S->right = new Node(6);
    S->left = new Node(4);
    S->left->right = new Node(30);

    if (isSubTree(T, S))
        cout << "Yes: S is a subtree of T";
    else
        cout << "No: S is NOT a subtree of T";
    return 0;

}