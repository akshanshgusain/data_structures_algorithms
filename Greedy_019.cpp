//
// Created by Akshansh Gusain on 26/08/22.
//
#include<bits/stdc++.h>

using namespace std;

int pageFaults(vector<int> &pages, int capacity) {

    deque<int> q(capacity);
    deque<int>::iterator itr;
    int faults = 0;
    q.clear();

    for (int & page : pages) {

        // Insert it into queue if not present already which
        // represents page fault
        itr = find(q.begin(), q.end(), page);

        if (!(itr != q.end())) {
            faults++;

            // check if the q can hold any more element(s)
            if (q.size() == capacity) {
                q.pop_front();

            }
            q.push_back(page);


        }
            // If already present in the queue
        else {
            q.erase(itr);
            q.push_back(page);
        }
    }

    return faults;
}

int main() {
    vector<int> pages = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2};
    int capacity = 4;
    cout << pageFaults(pages, capacity);
    return 0;
}