//
// Created by Akshansh Gusain on 04/08/21.
//

#include<stdc++.h>

using namespace std;

void generate_subs_with_reps(string s) {
    vector<string> v;
    v.emplace_back("");
    for (char i : s) {
        int size_ = v.size();
        for (int j = 0; j < size_; j++) {
            string tmp = v[j] + i;
            cout << tmp << " ";
            v.push_back(tmp);
        }
    }
    cout<<endl;
}

void generate_subs_without_reps(string s) {
    vector<string> v;
    unordered_set<string> se;
    v.push_back("");
    for (int i = 0; i < s.size(); i++) {
        int size_ = v.size();
        for (int j = 0; j < size_; j++) {
            string tmp = v[j] + s[i];
            if (se.find(tmp) == se.end()) {
                cout << tmp << " ";
                se.insert(tmp);
                v.push_back(tmp);
            }
        }
    }
}

int main() {
    // output is set to null before passing in as a
    // parameter
    string input = "abb";
    generate_subs_with_reps(input);
    generate_subs_without_reps(input);
    return 0;
}