//
// Created by Akshansh Gusain on 25/08/22.
//
#include<bits/stdc++.h>

using namespace std;

class Meeting {
public:
    int start;
    int end;
    int index;

    Meeting(int start, int anEnd, int index) : start(start), end(anEnd), index(index) {}
};

bool comparator(Meeting &a, Meeting &b) {
    return a.end < b.end;
}

void findMaxMeetings(vector<int> &start, vector<int> &end) {
    vector<Meeting> input;
    vector<Meeting> ans;
    int i;
    for (i = 0; i < start.size(); i++) {
        input.emplace_back(Meeting(start[i], end[i], i));
    }

    sort(input.begin(), input.end(), comparator);

    ans.emplace_back(input[0]);
    int lastEndTime = input[0].end;
    for (i = 1; i < input.size(); i++) {
        if(input[i].start >= lastEndTime){
            ans.emplace_back(input[i]);
            lastEndTime = input[i].end;
        }
    }
    for(auto it: ans){
        cout<<it.index+1<<" ";
    }
    cout<<endl;
    for(auto it: ans){
        cout<<it.start << " "<<it.end<<endl;
    }

}

int main() {
    vector<int> start = {1, 3, 0, 5, 8, 5};
    vector<int> end = {2, 4, 6, 7, 9, 9};
    findMaxMeetings(start, end);
    return 0;
}