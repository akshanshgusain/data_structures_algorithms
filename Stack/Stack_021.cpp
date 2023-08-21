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

//void mergeIntervals(vector<Interval> &arr) {
//    int n = arr.size();
//    if (n <= 0) {
//        return;
//    }
//
//    sort(arr.begin(), arr.end(), compareIntervals);
//    stack<Interval> stack;
//
//    stack.push(arr[0]);
//
//    for (int i = 1; i < n; i++) {
//        // get interval from stack top
//        Interval top = stack.top();
//
//        // If current interval is not overlapping with stack's top,
//        //push it to the stack
//        if (top.end < arr[i].start) {
//            stack.push(arr[i]);
//        }
//
//            // Otherwise update the ending time of top if ending of current
//            // interval is more
//        else if (top.end < arr[i].end) {
//            top.end = arr[i].end;
//            stack.pop();
//            stack.push(top);
//        }
//    }
//
//    // Print the stack
//    cout << "\n The Merged Intervals are: ";
//    while (!stack.empty()) {
//        Interval t = stack.top();
//        cout << "[" << t.start << "," << t.end << "] ";
//        stack.pop();
//    }
//}

// Time: O(NLogN), Space: O(N)
void mergeIntervals(vector<Interval> &arr) {
    int n = arr.size();
    if (n <= 0) {
        return;
    }

    sort(arr.begin(), arr.end(), compareIntervals);

    cout << "\n The Sorted Intervals are: ";
    for (auto it : arr) {
        cout << "[" << it.start << "," << it.end << "] ";
    }

    vector<Interval> mergedIntervals; // Store merged intervals

    mergedIntervals.push_back(arr[0]);

    for (int i = 1; i < n; i++) {
        if (mergedIntervals.back().end >= arr[i].start) {
            // Merge previous and current Intervals
            mergedIntervals.back().end = max(mergedIntervals.back().end, arr[i].end);
        } else {
            mergedIntervals.push_back(arr[i]);
        }
    }

    // Print the merged intervals
    cout << "\n The Merged Intervals are: ";
    for (auto it : mergedIntervals) {
        cout << "[" << it.start << "," << it.end << "] ";
    }
}

void mergeIntervalsOptimised(vector<Interval> &arr) {
    int n = arr.size();
    if (n <= 0) {
        return;
    }

    sort(arr.begin(), arr.end(), compareIntervals);

    int index = 0; // Index for the output array

    for (int i = 1; i < n; i++) {
        if (arr[index].end >= arr[i].start) {
            // Merge previous and current Intervals
            arr[index].end = max(arr[index].end, arr[i].end);
        } else {
            index++;
            arr[index] = arr[i];
        }
    }

    // Resize the array to the correct size (index + 1)
    arr.resize(index + 1);

    // Print the merged intervals
    cout << "\n The Merged Intervals are: ";
    for (auto it : arr) {
        cout << "[" << it.start << "," << it.end << "] ";
    }
}


int main() {
    vector<Interval> arr = {
            Interval{1, 3},
            Interval{2, 4},
            Interval{6, 8},
            Interval{9, 10},
    };

    mergeIntervalsOptimised(arr);
    return 0;
}

