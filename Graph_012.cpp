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

                    // it means the transformation hasn't really changed the word
                    if(currentWord == temp){
                        continue;
                    }

                    // if the current transformation temp matches the endWord, indicating that we've successfully
                    // transformed the beginWord into the desired endWord.
                    if(endWord == temp){
                        return depth+1;
                    }

                    // it means it's a valid intermediate word
                    // It's enqueued into the queue, and then removed from the set to avoid revisiting the same word
                    if(myset.find(temp) != myset.end()){
                        q.push(temp);
                        myset.erase(temp);
                    }
                }
            }
        }

    }

    return 0;
}

int main() {
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};

    cout<<ladderLength(beginWord, endWord, wordList); // 5
    return 0;
}
