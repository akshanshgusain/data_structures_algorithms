//
// Created by Akshansh Gusain on 17/08/22.
//

//Optimised : https://leetcode.com/problems/word-break/discuss/672860/Easy-C%2B%2B-Trie-for-Lookup-Solution
#include<bits/stdc++.h>

using namespace std;

class Trie {

private:
    unordered_map<char, Trie *> next = {};
    bool isword = false;

public:
    Trie() = default;

    void insert(const string &word) {
        Trie *node = this;
        for (char ch: word) {
            if (!node->next.count(ch)) {
                node->next[ch] = new Trie();
            }
            node = node->next[ch];
        }
        node->isword = true;
    }

    bool search(const string &word) {
        Trie *node = this;
        for (char ch: word) {
            if (!node->next.count(ch)) {
                return false;
            }
            node = node->next[ch];
        }
        return node->isword;
    }

    bool startsWith(const string &prefix) {
        Trie *node = this;
        for (char ch: prefix) {
            if (!node->next.count(ch)) {
                return false;
            }
            node = node->next[ch];
        }
        return true;
    }

    bool wordBreak(const string &word) {
        int n = word.size();
        if (n == 0) {
            return true;
        }

        // Try all prefixes from length 1 to n
        for (int i = 1; i<= n; i++) {
            if (this->search(word.substr(0, i)) and wordBreak(word.substr(i, n-i))) {
                return true;
            }
        }
        return false;
    }

};

int32_t main() {
    Trie *trie = new Trie();

    // String Dictionary
    vector<string> dictionary = {"mobile", "samsung", "sam",
                                 "sung", "man", "mango",
                                 "icecream", "and", "go", "i",
                                 "like", "ice", "cream"};
    for (const auto &it: dictionary) {
        trie->insert(it);
    }

    trie->wordBreak("ilikesamsung") ? cout << "Yes\n" : cout << "No\n";
    trie->wordBreak("iiiiiiii") ? cout << "Yes\n" : cout << "No\n";
    trie->wordBreak("") ? cout << "Yes\n" : cout << "No\n";
    trie->wordBreak("ilikelikeimangoiii") ? cout << "Yes\n" : cout << "No\n";
    trie->wordBreak("samsungandmango") ? cout << "Yes\n" : cout << "No\n";
    trie->wordBreak("samsungandmangok") ? cout << "Yes\n" : cout << "No\n";

    return 0;
}