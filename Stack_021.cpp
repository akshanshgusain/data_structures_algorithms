//
// Created by Akshansh Gusain on 16/03/22.
//

// https://www.geeksforgeeks.org/merging-intervals/

// Time: O(NLogN), Space: O(N)(N for stack)


#include<stdc++.h>

using namespace std;

struct Interval {
    int start, end;
};

bool compareIntervals(Interval i1, Interval i2) {
    return (i1.start < i2.start);
}

void mergeIntervals(vector<Interval> &arr) {
    int n = arr.size();
    if (n <= 0) {
        return;
    }

    sort(arr.begin(), arr.end(), compareIntervals);
    stack<Interval> stack;

    stack.push(arr[0]);

    for (int i = 1; i < n; i++) {
        // get interval from stack top
        Interval top = stack.top();

        // If current interval is not overlapping with stack's top,
        //push it to the stack
        if (top.end < arr[i].start) {
            stack.push(arr[i]);
        }

            // Otherwise update the ending time of top if ending of current
            // interval is more
        else if (top.end < arr[i].end) {
            top.end = arr[i].end;
            stack.pop();
            stack.push(top);
        }
    }

    // Print the stack
    cout << "\n The Merged Intervals are: ";
    while (!stack.empty()) {
        Interval t = stack.top();
        cout << "[" << t.start << "," << t.end << "] ";
        stack.pop();
    }
}

// Time: O(NLogN), Space: O(1)
// Instead of using the stack we can de in-place merge

void mergeIntervalsOptimised(vector<Interval> &arr) {
    int n = arr.size();
    if (n <= 0) {
        return;
    }

    sort(arr.begin(), arr.end(), compareIntervals);

    int index = 0; // Stores index of last element
    // in output array (modified arr[])

    for (int i = 1; i < n; i++) {
        // If this is not first Interval and overlaps
        // with the previous one

        if (arr[index].end >= arr[i].start) {
            // Merge previous and current Intervals
            arr[index].end = max(arr[index].end, arr[i].end);
        } else {
            index++;
            arr[index] = arr[i];
        }
    }

    // Print the stack
    cout << "\n The Merged Intervals are: ";
    for (auto it: arr) {
        cout << "[" << it.start << "," << it.end << "] ";

    }
}


int main() {
    vector<Interval> arr = {
            Interval{6, 8},
            Interval{1, 9},
            Interval{2, 4},
            Interval{4, 7},
    };

    mergeIntervals(arr);
    return 0;
}

