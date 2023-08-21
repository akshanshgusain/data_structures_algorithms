//
// Created by Akshansh Gusain on 16/03/22.
//
//https://www.youtube.com/watch?v=0do2734xhnU

//
//#include<stdc++.h>
//
//using namespace std;
//
//int getMaxArea(vector<int> &histogram) {
//    int n = histogram.size();
//
//    // Nearest smallest element on the right
//    vector<int> nearestSmallestRight(n);
//
//    stack<int> smallestSoFar;
//
//    // Going from right to left
//
//    smallestSoFar.push(histogram[n - 1]);
//    nearestSmallestRight[n - 1] = n;
//
//    for (int i = n - 2; i >= 0; i--) {
//        while (!smallestSoFar.empty() and
//               histogram[i] <= histogram[smallestSoFar.top()]) {
//            smallestSoFar.pop(); // we have found smaller peek
//        }
//
//        if (smallestSoFar.empty()) {
//            //current i is the smallest peek
//            nearestSmallestRight[i] = n;
//        } else {
//            nearestSmallestRight[i] = smallestSoFar.top();
//        }
//        smallestSoFar.push(i);
//    }
//
//    // Going from left to right
//
//    // Nearest smallest element on the left
//    vector<int> nearestSmallestLeft(n);
//    smallestSoFar={};
//
//    smallestSoFar.push(0);
//    nearestSmallestLeft[-1];
//
//    for(int i = 1; i < n; i++){
//        while(!smallestSoFar.empty()
//        and histogram[i] <= histogram[smallestSoFar.top()]){
//            smallestSoFar.pop();
//        }
//
//        if(smallestSoFar.empty()){
//            nearestSmallestLeft[i] = -1;
//        }else{
//            nearestSmallestLeft[i] = smallestSoFar.top();
//        }
//
//        smallestSoFar.push(i);
//    }
//
//    int max = 0;
//    for (int i = 0; i < n; i++) {
//        int width = nearestSmallestRight[i] - nearestSmallestLeft[i] - 1;
//        int area = width * histogram[i];
//        if (area > max) {
//            max = area;
//        }
//    }
//
//    return max;
//}
//
//int main() {
//    vector<int> histogram = {6, 2, 5, 4, 5, 1, 6};
//    cout << "Maximum area is " << getMaxArea(histogram);
//    return 0;
//}


#include<bits/stdc++.h>

using namespace std;



int getMaxArea(vector<int> &histogram) {
    int n = histogram.size();

    stack<int> stack;
    vector<int> leftSmallest(n), rightSmallest(n);

    for (int i = 0; i < n; i++) {
        while (!stack.empty() and histogram[stack.top()] >= histogram[i]) {
            stack.pop();
        }
        if (stack.empty()) {
            leftSmallest[i] = 0;
        } else {
            leftSmallest[i] = stack.top() + 1;
        }

        stack.push(i);
    }

    // clear the stack for reuse
    while (!stack.empty()) {
        stack.pop();
    }

    for (int i = n - 1; i >= 0; i--) {
        while (!stack.empty() and histogram[stack.top()] >= histogram[i]) {
            stack.pop();
        }

        if (stack.empty()) {
            rightSmallest[i] = n - 1;
        } else {
            rightSmallest[i] = stack.top() - 1;
        }
        stack.push(i);
    }

    int maxArea = 0;
    for (int i = 0; i < n; i++) {
        maxArea = max(maxArea, histogram[i] * (rightSmallest[i] - leftSmallest[i] + 1));
    }

    return maxArea;
}


int getMaxAreaOptimised(vector<int> &histogram) {
    int n = histogram.size();

    // Create an empty stack. The stack holds indexes
    // of hist[] array. The bars stored in stack are
    // always in increasing order of their heights.
    stack<int> s;

    int max_area = 0; // Initialize max area
    int tp; // To store top of stack
    int area_with_top; // To store area with top bar
    // as the smallest bar

    int i;

    for (i = 0; i < n;) {
        // If this bar is higher than the bar on top
        // stack, push it to stack
        if (s.empty() or histogram[s.top()] <= histogram[i]) {
            s.push(i++);
        }

            // If this bar is lower than top of stack,
            // then calculate area of rectangle with stack
            // top as the smallest (or minimum height) bar.
            // 'i' is 'right index' for the top and element
            // before top in stack is 'left index'
        else {
            tp = s.top(); // store the top index
            s.pop(); // pop the top

            // Calculate the area with hist[tp] stack
            // as smallest bar
            area_with_top = histogram[tp] * (s.empty() ? i : i - s.top() - 1);

            // update max area, if needed
            if (max_area < area_with_top) {
                max_area = area_with_top;
            }
        }
    }

    // Now pop the remaining bars from stack and calculate
    // area with every popped bar as the smallest bar
    while (!s.empty()) {
        tp = s.top();
        s.pop();
        area_with_top = histogram[tp] * (s.empty() ? i : i - s.top() - 1);

        if (max_area < area_with_top) {
            max_area = area_with_top;
        }
    }

    return max_area;
}

int main() {
    vector<int> histogram = {6, 2, 5, 4, 5, 1, 6};
    cout << "Maximum area is " << getMaxArea(histogram);
    return 0;
}