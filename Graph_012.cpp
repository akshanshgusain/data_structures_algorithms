//
// Created by Akshansh Gusain on 26/08/21.
//
#include<stdc++.h>
using namespace std;

int ladderLength(string beginWord, string endWord, vector<string> &wordList){
    unordered_set<string> myset;
    bool isPresent = false; // check if the end word is present in the dictionary


    //Insert all words in a set
    for(auto word: wordList){
        if(endWord == word){
            isPresent = true;
        }
        myset.insert(word);
    }

    if(!isPresent){
        return 0;
    }

    queue<string> q;
    q.push(beginWord);
    int depth = 0;

    while(!q.empty()){
        depth += 1;
        int lsize = q.size(); // number of elements at that level

        while(lsize--){
            string currentWord = q.front();
            q.pop();
            // check all the possible at the same depth

            for(int i = 0; i < currentWord.length(); i++){
                string temp = currentWord;

                // try all possible chars
                for(char c = 'a'; c <= 'z' ; c++){
                    temp[i] = c;
                    if(currentWord == temp){
                        continue;
                    }
                    if(endWord == temp){
                        return depth+1;
                    }
                    if(myset.find(temp) != myset.end()){
                        q.push(temp);
                        myset.erase(temp);
                    }
                }
            }
        }

    }
}

int main() {
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};

    cout<<ladderLength(beginWord, endWord, wordList);
    return 0;
}
