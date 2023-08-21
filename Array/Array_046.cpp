//
// Created by Akshansh Gusain on 02/08/21.
//
#include<stdc++.h>

using namespace std;

// https://leetcode.com/problems/largest-rectangle-in-histogram/
// https://www.youtube.com/watch?v=vcv3REtIvEo
// Time: O(N), Space : O(N)

// If the largest rect contains at least 1 bar in full then if we find areas of all largest rectangles for each bar
// being included full then we can find the maximum rectangle are.
// S1: Find the largest rectangle including each bar one by one.
//    S1.1: find the nearest left bar with height < current bar (else 0)
//    S1.2: find the nearest right bar with height < current bar (else 0)
// S2: Take the maximum of all the max areas for each bar found.

int largestRectangleArea(vector<int> &heights) {
    int n = heights.size();
    vector<int> left(n), right(n);
    stack<int> myStack;
    int i;
    //Fill left array
    for (i = 0; i < n; i++) {
        if (myStack.empty()) {
            left[i] = 0;
            myStack.push(i);
        } else {
            while (!myStack.empty() and heights[myStack.top()] >= heights[i]) {
                myStack.pop();
            }
            left[i] = myStack.empty() ? 0 : myStack.top() + 1;
            myStack.push(i);
        }
    }

    //Clear the stack
    while(!myStack.empty()){
        myStack.pop();
    }

    //Fill the right Array
    for(i = n-1; i>=0 ; i--){
        if(myStack.empty()){
            right[i] = n-1;
            myStack.push(i);
        }else{
            while(!myStack.empty() and heights[myStack.top()] >= heights[i]){
                myStack.pop();
            }
            right[i] = myStack.empty()? n-1:myStack.top() - 1;
            myStack.push(i);
        }
    }

    int max_area = 0;
    for(i = 0 ; i < n ; i++){
        max_area = max(max_area, heights[i] * (right[i] - left[i] + 1));
    }

    return max_area;
}


int main() {
    vector<int> histogram = {6, 2, 5, 4, 5, 1, 6}; // 12
    cout << "Maximum area is: " << largestRectangleArea(histogram);
    return 0;
}
