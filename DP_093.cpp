//
// Created by Akshansh Gusain on 14/01/22.
//


//https://www.youtube.com/watch?v=yr77dVf1RQA&t=477s

#include<stdc++.h>

using namespace std;

bool dictionaryContains(string word, vector<string> dictionary) {
    int size = dictionary.size();
    for (int i = 0; i < size; i++)
        if (dictionary[i] == word) {
            return true;
        }

    return false;
}

int wordBreak(unordered_set<string> dict, string sentence) {
    int n = sentence.length();
    int dp[n+1];
    memset(dp, 0, sizeof dp);
    dp[n] = 1;


    // dp[i]
    for(int i = n-1; i >=0; i--){
        string word;
        for(int j = i; j <n; j++){
            word.push_back(sentence[j]);
            if(dict.find(word) != dict.end()){
                if(dp[j+1]){
                    dp[i] = 1;
                }
            }
        }
    }

    return dp[0];
}

int main() {
    unordered_set<string> dict = {"mobile", "samsung", "sam", "sung",
                                  "man", "mango", "icecream", "and",
                                  "go", "i", "like", "ice", "cream"};

    cout << wordBreak(dict, "isung");
    return 0;
}