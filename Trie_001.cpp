//
// Created by Akshansh Gusain on 28/07/22.
//
#include<bits/stdc++.h>

using namespace std;


class TrieNode {
public:
    // Initialize your data structure here.
    bool is_word;
    TrieNode *children[26]{};

    TrieNode() {
        is_word = false;

        for (auto &i: children)
            i = nullptr;
    }
};

class Trie {
private:
    TrieNode *root;

public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        int word_len = word.length();
        int k;
        TrieNode *cur = root;

        for (int i = 0; i < word_len; i++) {
            k = word[i] - 'a';

            if (cur->children[k] == nullptr) {
                cur->children[k] = new TrieNode();
            }

            cur = cur->children[k];
        }

        cur->is_word = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        int word_len = word.length();
        int k;
        TrieNode *cur = root;

        for (int i = 0; i < word_len; i++) {
            k = word[i] - 'a';
            cur = cur->children[k];

            if (cur == nullptr)
                return false;
        }

        return cur->is_word;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        int word_len = prefix.length();
        int k;
        TrieNode *cur = root;

        for (int i = 0; i < word_len; i++) {
            k = prefix[i] - 'a';
            cur = cur->children[k];

            if (cur == nullptr)
                return false;
        }

        return true;
    }


};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");

int32_t main() {
    Trie trie;
    trie.insert("gusain");
    cout << trie.search("gusain");
    cout << trie.startsWith("gu");
    return 0;
}