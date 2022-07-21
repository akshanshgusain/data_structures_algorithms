//
// Created by Akshansh Gusain on 02/08/21.
//

#include<stdc++.h>

using namespace std;

//https://leetcode.com/problems/maximal-rectangle/
// Time: O(R * C), Space: O(C)

// We can convert the matrix into histograms row-wise and find maximal area rectangle in each of those histograms.


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


int maximalRectangle(vector<vector<int>> &mat) {
    int row = mat.size();
    int col = mat[0].size();
    int max_area = 0;
    int i,j;
    vector<int> v;

    for(j = 0; j < col; j++){
        v.push_back(mat[0][j]);
    }
    max_area = largestRectangleArea(v);

    for(i = 1; i < row; i++){
        for(j = 0 ; j < col; j++){
            if(mat[i][j] == 0){
                v[j] = 0;
            }else{
                v[j] = v[j] + mat[i][j];
            }
        }
        max_area = max(max_area, largestRectangleArea(v));
    }

    return max_area;
}


int main() {
    vector<vector<int>> mat = {
            {0, 1, 1, 0},
            {1, 1, 1, 1},
            {1, 1, 1, 1},
            {1, 1, 0, 0},
    };

    cout << "Area of maximum rectangle is " << maximalRectangle(mat);

    return 0;
}
