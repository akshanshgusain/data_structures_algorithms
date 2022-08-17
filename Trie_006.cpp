//
// Created by Akshansh Gusain on 17/08/22.
//
//

#include<bits/stdc++.h>

using namespace std;

class Trie {

private:
    unordered_map<char, Trie *> next = {};
    vector<string> suggestions;
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
            // Add the current word as suggestion
            node->suggestions.emplace_back(word);
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

    void phoneDirectory(vector<string> &words, const string &query) {
        Trie *node = this;
        for (const auto &it: words) {
            node->insert(it);
        }


        vector<char> ans;
        for (int i = 0; query[i]; i++) {
            cout<<"Suggestions based on "<<"\""<<query.substr(0+1, i)<<"\""<<" are"<<endl;
            // if the complete prefix is not present in the trie
            if(!node->next.count(query[i])){
                // make word count zero and break;
                ans = {};
                break;
            }
            ans.push_back(query[i]);
            node = node->next[query[i]];
            for(const auto &it: ans){
                cout<<it;
            }
        }

        for(const auto &it: ans){
            cout<<it;
        }
    }

};

int32_t main() {
    Trie *trie = new Trie();
    vector<string> words = {"gforgeeks", "geeksquiz"};
    trie->phoneDirectory(words, "gekk");
    return 0;
}