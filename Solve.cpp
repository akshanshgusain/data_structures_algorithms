#include<bits/stdc++.h>

using namespace std;

#define d pair<int, pair<int, int>>

struct Node {
    int element;
    int i;
    int j;

    Node(int el, int i, int j) {
        element = el;
        this->i = i;
        this->j = j;
    }

};

struct NodeComparator {
    bool operator()(const Node &a, const Node &b) const {
        return a.element > b.element;  // Compare elements in descending order
    }
};

vector<int> smallestRange2(vector<vector<int>> &nums) {
    priority_queue<Node, vector<Node>, NodeComparator> minHeap;

    int maxElement = INT_MIN;
    int n = nums.size();

    for (int i = 0; i < n; i++) {
//        minHeap.push({nums[i][0], {i, 0}});
        minHeap.emplace(nums[i][0], i, 0);
        maxElement = max(maxElement, nums[i][0]);
    }

    int first, second;
    int rangeDifference = INT_MAX;

    while (!minHeap.empty()) {
        Node p = minHeap.top();
        minHeap.pop();

        if (rangeDifference > maxElement - p.element) {
            first = p.element;
            second = maxElement;
            rangeDifference = second - first;
        }
        // move the pointer of the list with min value ahead 1 step
        // check range
        if (nums[p.i].size() - 1 > p.j) {
            int nextIdx = p.j + 1;
            minHeap.emplace(nums[p.i][nextIdx], p.i, nextIdx);
            maxElement = max(maxElement, nums[p.i][nextIdx]);
        } else {
            break;
        }

    }
    return {first, second};
}


vector<int> smallestRange(vector<vector<int>> &nums) {
    priority_queue<d, vector<d>, greater<>> minHeap;
    int maxElement = INT_MIN;
    int n = nums.size();

    for (int i = 0; i < n; i++) {
        minHeap.push({nums[i][0], {i, 0}});
        maxElement = max(maxElement, nums[i][0]);
    }

    int first, second;
    int rangeDifference = INT_MAX;

    while (!minHeap.empty()) {
        d p = minHeap.top();
        minHeap.pop();

        if (rangeDifference > maxElement - p.first) {
            first = p.first;
            second = maxElement;
            rangeDifference = second - first;
        }
        // move the pointer of the list with min value ahead 1 step
        // check range
        if (nums[p.second.first].size() - 1 > p.second.second) {
            int nextIdx = p.second.second + 1;
            minHeap.push({nums[p.second.first][nextIdx], {p.second.first, nextIdx}});
            maxElement = max(maxElement, nums[p.second.first][nextIdx]);
        } else {
            break;
        }

    }
    return {first, second};
}

int main() {

    vector<vector<int>> arr = {
            {4, 7,  9,  12, 15},
            {0, 8,  10, 14, 20},
            {6, 12, 16, 30, 50}
    };

    vector<int> sol = smallestRange2(arr);
    for (auto a: sol) {
        cout << a << " ";
    }
    return 0;
}