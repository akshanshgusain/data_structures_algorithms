//
// Created by Akshansh Gusain on 12/04/21.
//https://leetcode.com/problems/word-ladder/

#include<stdc++.h>
using namespace std;

int ladderLength(string beginWord, string endWord, vector<string>& wordList){
    unordered_set<string> myset;
    bool isPresent = false; //Check if endWord is present in the dictionary

    //Insert all words into the set
    for(auto word : wordList){
        //While inserting check whether the end word is present in the dict or not
        if(endWord.compare(word) == 0){
            isPresent = true;
        }
        myset.insert(word);
    }
    //If end word is not present in the dict then return 0
    if(!isPresent){
        return 0;
    }

    queue<string> q;
    q.push(beginWord);
    int depth = 0;

    while(!q.empty()){
        depth += 1;
        int lsize = q.size(); //Number of elements at a level

        while(lsize--){
            string curr = q.front();
            q.pop();

            //Check all possible words at same depth
            for(int i = 0; i< curr.length(); i++ ){
                string temp = curr;
                //try all possible chars
                for(char c='a' ; c < 'z' ;c++){
                    temp[i] = c;
                    if(curr == temp){
                        continue; //skip the same word
                    }
                    if(temp == endWord){
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
int main(){
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};

    cout<<ladderLength(beginWord, endWord, wordList);
    return 0;
}