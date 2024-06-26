//
// Created by Akshansh Gusain on 02/04/24.
//

// https://leetcode.com/problems/reorganize-string/

#include<bits/stdc++.h>

using namespace std;

string reorganizeString(const string &s) {

    // Ordered-Sorted Map
    map<int, int> counts;
    for (char c: s) {
        counts[c]++;
    }
    priority_queue<pair<int, int>> pq;

    for (auto p: counts) {
        // < count , char >
        pq.emplace(p.second, p.first);
    }

    string res;
    pair<int, int> top1, top2;

    while (!pq.empty()) {
        top1 = pq.top();
        pq.pop();
        res += top1.second;

        if (!pq.empty()) {
            top2 = pq.top();
            pq.pop();
            res += top2.second;

            if (top2.first > 1) {
                pq.emplace(top2.first - 1, top2.second);
            }
        }

        if (top1.first > 1) {
            pq.emplace(top1.first - 1, top1.second);
        }

    }

    for (int i = 1; i < res.size(); i++){
        if (res[i] == res[i - 1]){
            return "";
        }
    }
    return res;
}


int main() {
    vector<string> input = {"aab", "aaab"};

    for (const auto &it: input) {
        cout << reorganizeString(it) << endl;
    }

    return 0;
}