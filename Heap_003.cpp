//
// Created by Akshansh Gusain on 25/07/22.
//

#include<stdc++.h>

using namespace std;

vector<int> maxSlidingWindow(vector<int> &arr, int k) {

    priority_queue<pair<int, int>> heap;
    vector<int> result;

    for (int i = 0; i < arr.size(); i++) {
        while(!heap.empty() and heap.top().second <= (i-k)){
            heap.pop();
        }

        //Insert elements
        heap.push(make_pair(arr[i], i));

        if(i >= k-1){
            result.push_back(heap.top().first);
        }
    }
    return result;
}

int main() {
    vector<int> a = {12, 1, 78, 90, 57, 89, 56};
    int k = 3;
    vector<int> ans = maxSlidingWindow(a, k);
    for (auto t: ans) {
        cout << t << " ";
    }

    return 0;
}