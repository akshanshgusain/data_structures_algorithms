//
// Created by Akshansh Gusain on 09/05/21.
//
#include<stdc++.h>

using namespace std;
#define NULL 0
#define MAX_CHAR 26

//Trie Data structure

struct Trie {
    char data;
    int wordEnd;
    Trie *children[MAX_CHAR];
};

Trie nodePool[100000]; // Pool of 100k Trie Nodes
Trie *root; // Root of the tree
int poolCount;//Always points to the next free trie node

//Initialize Trie
void init() {
    poolCount = 0;
    root = &nodePool[poolCount++];
    root->data = '%';
    for (auto &i : root->children) {
        i = nullptr;
    }
}

Trie *getNewNode(char ch) {
    Trie *newNode = &nodePool[poolCount++];
    newNode->data = ch;
    for (auto &i : newNode->children) {
        i = nullptr;
    }
    newNode->wordEnd = 0;
    return newNode;
}

void insertWord(char *s) {
    Trie *curr = root;
    int index;
    for (int i = 0; s[i] != '\0'; i++) {
        index = s[i] - 'a'; // relative position of character s[i]
        if (curr->children[index] == nullptr) {
            curr->children[index] = getNewNode(s[i]);
        }
        curr->children[index]->wordEnd += 1;
    }
}

bool search(char *s) {
    Trie *curr = root;
    int index;
    for (int i = 0; s[i] != '\0'; i++) {
        index = s[i] - 'a'; // relative position of character s[i]
        if (curr->children[index] == nullptr or curr->children[index]->wordEnd == 0) {
            return false;
        }
        curr->children[index]->wordEnd += 1;
        curr = curr->children[index];
    }
    return true;
}

bool deleteWord(char *s) {
    if (search(s)) {
        Trie *curr = root;
        int index;
        for (int i = 0; s[i] != '\0'; i++) {
            index = s[i] - 'a';
            curr->children[index]->wordEnd -= 1;
            curr = curr->children[index];
        }
    }
}

int countPrefix(string s) {
    Trie *curr = root;
    int index;
    for (int i = 0; s[i] != '\0'; ++i) {
        index = s[i] - 'a';
        if (curr->children[index] == nullptr || curr->children[index]->wordEnd == 0)
            return 0;   //No string with given prefix is present
        curr = curr->children[index];
    }
    return curr->wordEnd;
}

bool wordBreak(string str) {
    int size = str.size();
    if (size == 0) {
        return true;
    }

    //try all prefix lengths from  1 to 0
    for (int i = 0; str[i] != '\0'; i++) {
        if (search(&str.substr(0, i)[0]) and wordBreak(str.substr(i, size - 1))) {
            return true;
        }
    }
    return false;
}

int main() {

    init();
    string dictionary[] = {"mobile","samsung","sam",
                           "sung","ma\n","mango",
                           "icecream","and","go","i",
                           "like","ice","cream"};
    int n = sizeof(dictionary)/sizeof(dictionary[0]);

    // Construct trie
    for (int i = 0; i < n; i++)
        insertWord(&dictionary[i][0]);

    wordBreak("ilikesamsung")? cout <<"Yes\n": cout << "No\n";
    wordBreak("iiiiiiii")? cout <<"Yes\n": cout << "No\n";
    wordBreak("")? cout <<"Yes\n": cout << "No\n";
    wordBreak("ilikelikeimangoiii")? cout <<"Yes\n": cout << "No\n";
    wordBreak("samsungandmango")? cout <<"Yes\n": cout << "No\n";
    wordBreak("samsungandmangok")? cout <<"Yes\n": cout << "No\n";

    return 0;
}
