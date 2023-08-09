//
// Created by Akshansh Gusain on 28/07/22.
//

// https://leetcode.com/problems/reorganize-string/

#include<bits/stdc++.h>

using namespace std;

string reorganizeString(const string &s) {

    // Ordered-Sorted Map
    map<int, int> cnts;
    for (char c: s) {
        cnts[c]++;
    }
    priority_queue<pair<int, int>> pq;

    for (auto p: cnts) {
        pq.push({p.second, p.first});
    }

    string res;
    pair<int, int> top1, top2;

    while (!pq.empty()) {
        top1 = pq.top();
        pq.pop();
        res += top1.second;

        if (!pq.empty()) {
            res += pq.top().second;
            top2 = pq.top();
            pq.pop();
            if (top2.first > 1) {
                pq.push({top2.first - 1, top2.second});
            }
        }

        if (top1.first > 1) {
            pq.push({top1.first - 1, top1.second});
        }

    }

    for (int i = 1; i < res.size(); i++)
        if (res[i] == res[i - 1]) return "";
    return res;
}


int main() {
    vector<string> input = {"aab", "aaab"};

    for (const auto &it: input) {
        cout << reorganizeString(it) << endl;
    }

    return 0;
}