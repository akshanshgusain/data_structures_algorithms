//
// Created by Akshansh Gusain on 19/08/22.
//
#include<bits/stdc++.h>

using namespace std;

static bool comparator(pair<int, int> &a, pair<int, int> &b) {
    return a.second < b.second;
}

int maxMeetings(vector<int> &startTimes, vector<int> &endTimes) {
    int n = startTimes.size();
    vector<pair<int, int>> input;
    for (int i = 0; i < n; i++) {
        input.emplace_back(startTimes[i], endTimes[i]);
    }

    //    Sorting according to ending times
    sort(input.begin(), input.end(), comparator);

    // Always pick the first activity
    cout << input[0].first << " - " << input[0].second << endl;
    int end = input[0].second;
    int cnt = 1;

    for (int i = 1; i < input.size(); i++) {
        if (end <= input[i].first) {
            cout << input[i].first << " - " << input[i].second << endl;
            end = input[i].second;
            cnt ++;
        }
    }
    return cnt;
}

int main() {
    vector<int> startTimes = {1, 3, 0, 5, 8, 5};
    vector<int> endTimes = {2, 4, 6, 7, 9, 9};
    cout << maxMeetings(startTimes, endTimes);
    return 0;
}