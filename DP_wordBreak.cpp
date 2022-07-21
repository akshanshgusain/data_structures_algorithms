//
// Created by Akshansh Gusain on 02/06/21.
//
#include<stdc++.h>
using namespace std;
unordered_map<string, int> dp;

int solve(const string& s, vector<string> &b){
    int sz = s.length();
    if(sz == 0){
        return 1;
    }

    if(dp[s] != 0){
        return dp[s];
    }

    for(int i=1; i <= sz; i++){
        int f = 0;
        string ss = s.substr(0, i);
        for(int j=0; j<b.size(); j++){
            if(ss.compare(b[j]) == 0){
                f = 1;
                break;
            }
        }
        if(f == 1 and solve(s.substr(i, sz-i), b) == 1){
            return dp[s] = 1;
        }
    }
    return dp[s] = -1;
}

int main(){
    string s = "ilike";
    string s1 = "ilikesamsung";
    vector<string> b = { "i", "like", "sam", "sung", "samsung", "mobile",
                         "ice","cream", "icecream", "man", "go", "mango" };
    cout<<solve(s1,b);
    return 0;
}
