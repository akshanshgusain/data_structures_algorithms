//
// Created by Akshansh Gusain on 03/04/21.
//
#include<stdc++.h>

using namespace std;

struct Interval {
    int start, end;
};

bool compareInterval(Interval i1, Interval i2) {
    return (i1.start < i2.start);
}

void mergeIntervals(Interval arr[], int n) {

    if (n <= 0) {
        return;
    }

    stack<Interval> s;

    sort(arr, arr + n, compareInterval);

    s.push(arr[0]);

    for (int i = 0; i < n; i++) {
        // get interval from stack top
        Interval top = s.top();

        // if current interval is not overlapping with stack top,
        // push it to the stack
        if (top.end < arr[i].start) {
            s.push(arr[i]);
        }
            // Otherwise update the ending time of top if ending of current
            // interval is more

        else if (top.end < arr[i].end) {
            top.end = arr[i].end;
            s.pop();
            s.push(top);
        }
    }

    // Print contents of stack
    cout << "\n The Merged Intervals are: ";
    while (!s.empty()) {
        Interval t = s.top();
        cout << "[" << t.start << "," << t.end << "] ";
        s.pop();
    }

}

int main() {

    Interval arr[] = {{6, 8},
                      {1, 9},
                      {2, 4},
                      {4, 7}};
    int n = sizeof(arr) / sizeof(arr[0]);
    mergeIntervals(arr, n);
    return 0;

}

