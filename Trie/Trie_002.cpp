//
// Created by Akshansh Gusain on 28/07/22.
//
#include<bits/stdc++.h>

using namespace std;

class Trie {

private:
    unordered_map<char, Trie *> next = {};
    bool isword = false;

public:
    Trie() = default;

    void insert(const string& word) {
        Trie *node = this;
        for (char ch: word) {
            if (!node->next.count(ch)) {
                node->next[ch] = new Trie();
            }
            node = node->next[ch];
        }
        node->isword = true;
    }

    bool search(const string& word) {
        Trie *node = this;
        for (char ch: word) {
            if (!node->next.count(ch)) {
                return false;
            }
            node = node->next[ch];
        }
        return node->isword;
    }

    bool startsWith(const string& prefix) {
        Trie *node = this;
        for (char ch: prefix) {
            if (!node->next.count(ch)) {
                return false;
            }
            node = node->next[ch];
        }
        return true;
    }


};

int32_t main() {
//    Trie trie;
//    trie.insert("gusain");
//    cout << trie.search("gusain");
//    cout << trie.startsWith("gu");
    Trie *trie = new Trie();
    trie->insert("gusain");
    cout << trie->search("gusain");
    cout << trie->startsWith("gu");
    return 0;
}