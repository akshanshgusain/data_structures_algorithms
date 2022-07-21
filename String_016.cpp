//
// Created by Akshansh Gusain on 10/08/21.
//

#include<stdc++.h>

using namespace std;

// DP: Time: O(N^2)
//https://www.youtube.com/watch?v=yr77dVf1RQA

bool solveWordBreak(string sentence, vector<string> &dictionary) {
    if (sentence.length() == 0)
        return true;

    int n  = sentence.length();
    int dp[n+1];
    memset(dp, 0, sizeof(dp));
    dp[n] = 1;

    unordered_set<string> dict;
    for(auto it: dictionary){
        dict.insert(it);
    }

    // dp[i]
    for(int i = n -1 ; i >= 0; i-- ){
        string word;
        for(int j = i; j < n; j++){
            word.push_back(sentence[j]);
            if(dict.find(word) != dict.end()){
                //we have found a word from i to j in the dictionary
                // But, we also need to check if the word from j+1 to n exist in the dictionary
                // To store the values of j+1 to n we need a DP.
                if(dp[j+1]){
                    dp[i] = 1;
                }
            }
        }
    }

    return dp[0];
}

int main() {
    vector<string> dictionary
            = {"mobile", "samsung", "sam", "sung", "man",
               "mango", "icecream", "and", "go", "i",
               "like", "ice", "cream"};

    string sentence = "ilikesam";
    cout << solveWordBreak(sentence, dictionary);

    return 0;
}