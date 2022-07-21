//
// Created by Akshansh Gusain on 06/08/21.
//
#include<stdc++.h>

using namespace std;

// Using Recursion

// Time: O(N*N!)
// youtube.com/watch?v=sPAT_DbvDj0
// Repetition Allowed (n! Permutations)

void permute(string s, string ans) {
    if (s.length() == 0) {
        cout << ans << " ";
        return;
    }

    for (int i = 0; i < s.length(); i++) {
        char ch = s[i];
        string leftSubString = s.substr(0, i);
        string rightSubString = s.substr(i + 1);
        string restOfTheString = leftSubString + rightSubString;
        permute(restOfTheString, ans + ch);
    }
}

// Repetition NOT Allowed (nPr Permutations: (n!)/(n-r)! )

void permute2(
        int currentSpot,
        int totalSpots,
        unordered_map<char, int> fMap,
        string answerSoFar
) {

    if(currentSpot > totalSpots){
        cout<<answerSoFar<<" ";
        return;
    }
    for(auto it: fMap){
        if(it.second > 0){
            fMap.find(it.first)->second--;
            permute2(currentSpot+1, totalSpots, fMap, answerSoFar + it.first);
            fMap.find(it.first)->second++;
        }
    }

}

void generatePermutations(string s) {
    unordered_map<char, int> fMap;
    for (auto it: s) {
        if (fMap.find(it) == fMap.end()) {
            fMap.insert({it, 1});
        } else {
            fMap.find(it)->second++;
        }
    }

    permute2(1, s.length(), fMap, "");
}

int main() {
    string input = "aba";
    string ans = "";

    permute(input, ans);
    cout<<endl;
    generatePermutations(input);
    return 0;
}