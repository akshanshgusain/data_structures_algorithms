//
// Created by Akshansh Gusain on 17/08/22.
//
#include<bits/stdc++.h>

using namespace std;

class Trie {

private:
    unordered_map<char, Trie *> next = {};
    bool isword = false;
    int freq;

public:


    Trie() = default;

    void insert(const string &word) {
        Trie *node = this;
        for (char ch: word) {
            if (!node->next.count(ch)) {
                node->next[ch] = new Trie();
            }

            node->freq += 1;
            node = node->next[ch];

        }
        node->isword = true;
    }


    int startsWith(const string &prefix) {
        Trie *node = this;
        for (int i =0;  i < prefix.length(); i++) {
            node = node->next[prefix[i]];
            if(node->freq == 1){
                return i;
            }
        }
        return prefix.length();
    }


    void printUniquePrefix(vector<string> &words) {
       Trie *node = this;
        for (const auto &it: words) {
            node->insert(it);
        }
        vector<string> ans;
        for(auto & word : words){
            int j = node->startsWith(word);
            cout<<word<<"----"<<word.substr(0,j+1)<<endl;
        }

    }
};


int32_t main() {
    vector<string> words = {"zebra", "dog", "duck", "dove"};
    Trie *trie = new Trie();
    trie->printUniquePrefix(words);

    return 0;
}