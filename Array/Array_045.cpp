//
// Created by Akshansh Gusain on 02/08/21.
//


// Use "Merge K Sorted Arrays"
// The idea is to use a Min Heap of size N which stores elements of first column. Then do extract minimum.
// In extract minimum, replace the minimum element with the next element of the row from which the element
// is extracted.

// Time: O(N^2LogN), Space: O()
#include<stdc++.h>

using namespace std;


void printSortedMat(vector<vector<int>> &mat) {
    int row = mat.size();
    int col = mat[0].size();

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;
    int columnIdx[col]; //store col index

    // Every heap node has first element of an array
    for(int i = 0 ; i < row; i++){
        minHeap.push(make_pair(mat[i][0], i));
        columnIdx[i] = 0;
    }

    // Now one by one get the minimum element from min heap and replace it with next element of its array
    int ai, i;
    while(!minHeap.empty()){
        tie(ai, i) = minHeap.top();
        minHeap.pop();
        cout<<ai<<" ";
        columnIdx[i] = columnIdx[i] + 1;
        if(columnIdx[i] < 4){
            minHeap.push(make_pair(mat[i][columnIdx[i]], i));
        }
    }
    cout<<endl;
}

int main() {
    vector<vector<int>> mat = {{10, 20, 30, 40},
                               {15, 25, 35, 45},
                               {27, 29, 37, 48},
                               {32, 33, 39, 50}};
    printSortedMat(mat);
    return 0;
}