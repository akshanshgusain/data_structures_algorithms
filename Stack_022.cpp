//
// Created by Akshansh Gusain on 16/03/22.
//
//https://www.youtube.com/watch?v=0do2734xhnU


#include<stdc++.h>

using namespace std;

int getMaxArea(vector<int> &histogram) {
    int n = histogram.size();

    // Nearest smallest element on the right
    vector<int> nearestSmallestRight(n);

    stack<int> smallestSoFar;

    // Going from right to left

    smallestSoFar.push(histogram[n - 1]);
    nearestSmallestRight[n - 1] = n;

    for (int i = n - 2; i >= 0; i--) {
        while (!smallestSoFar.empty() and
               histogram[i] <= histogram[smallestSoFar.top()]) {
            smallestSoFar.pop(); // we have found smaller peek
        }

        if (smallestSoFar.empty()) {
            //current i is the smallest peek
            nearestSmallestRight[i] = n;
        } else {
            nearestSmallestRight[i] = smallestSoFar.top();
        }
        smallestSoFar.push(i);
    }

    // Going from left to right

    // Nearest smallest element on the left
    vector<int> nearestSmallestLeft(n);
    smallestSoFar={};

    smallestSoFar.push(0);
    nearestSmallestLeft[-1];

    for(int i = 1; i < n; i++){
        while(!smallestSoFar.empty()
        and histogram[i] <= histogram[smallestSoFar.top()]){
            smallestSoFar.pop();
        }

        if(smallestSoFar.empty()){
            nearestSmallestLeft[i] = -1;
        }else{
            nearestSmallestLeft[i] = smallestSoFar.top();
        }

        smallestSoFar.push(i);
    }

    int max = 0;
    for (int i = 0; i < n; i++) {
        int width = nearestSmallestRight[i] - nearestSmallestLeft[i] - 1;
        int area = width * histogram[i];
        if (area > max) {
            max = area;
        }
    }

    return max;
}

int main() {
    vector<int> histogram = {6, 2, 5, 4, 5, 1, 6};
    cout << "Maximum area is " << getMaxArea(histogram);
    return 0;
}

