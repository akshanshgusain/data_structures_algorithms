//
// Created by Akshansh Gusain on 30/08/23.
//

#include<bits/stdc++.h>
using namespace std;

int ladderLength(string &beginWord, string &endWord, vector<string> &wordList){
    bool isPresent = false;
    unordered_set<string> mySet;

    for(auto it: wordList){
        if (it == endWord){
            isPresent = true;
        }
        mySet.insert(it);
    }

    if(!isPresent){
        return 0;
    }

    queue<string> queue;
    queue.push(beginWord);
    int depth = 0;
    while(!queue.empty()){
        depth ++;
        // number of elements at that level
        int currentLevelSize = queue.size();

        while(currentLevelSize--){
            string top = queue.front();
            queue.pop();

             // check all the possible at the same depth
            for(int k = 0; k < top.size(); k++){
                string temp = top;

                // try all possible chars
                for(char c = 'a'; c <= 'z'; c++){
                    temp[k] = c;

                    // it means the transformation hasn't really changed the word
                    if(temp == top){
                        continue;
                    }

                    // if the current transformation temp matches the endWord, indicating that we've successfully
                    // transformed the beginWord into the desired endWord.

                    if(temp == endWord){
                        return depth + 1;
                    }

                    // it means it's a valid intermediate word
                    // It's enqueued into the queue, and then removed from the set to avoid revisiting the same word
                    if(mySet.find(temp) != mySet.end()){
                        queue.push(temp);
                        mySet.erase(temp);
                    }
                }
            }
        }
    }

    return 0;
}

int main(){
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};

    cout<<ladderLength(beginWord, endWord, wordList); // 5
    return 0;
}