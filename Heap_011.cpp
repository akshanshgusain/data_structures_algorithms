//
// Created by Akshansh Gusain on 28/07/22.
//
//

//https://www.youtube.com/watch?v=1LkOrc-Le-Y&list=WL&index=1&t=916s

#include<bits/stdc++.h>

using namespace std;

priority_queue<int> maxHeap; //First half of the stream
priority_queue<int, vector<int>, greater<int>> minHeap; // 2nd half of the stream

void addNum(int num) {
    int lSize = maxHeap.size();
    int rSize = minHeap.size();

    //Num is the first element in the stream
    if (lSize == 0) {
        maxHeap.push(num); //Push one element in maxHeap for sure
    } else if (lSize == rSize) {

        //num can be pushed to maxHeap (1st half) to maintain order
        if (num < minHeap.top()) {
            maxHeap.push(num);
        }
            //Push root of minHeap(2nd half) to maxHeap(2nd half)
        else {
            int temp = minHeap.top();
            minHeap.pop();
            minHeap.push(num);
            maxHeap.push(temp);
        }
    }
        //we assume that maxHeap can be larger than minHeap by a max of 1 element only
    else {
        if (rSize== 0) {

            //Push num to second half
            if (num > maxHeap.top()) {
                minHeap.push(num);
            }
                //push num to first half
            else {
                int temp = maxHeap.top();
                maxHeap.pop();
                maxHeap.push(num);
                minHeap.push(temp);
            }
        }
            //Push the element directly in min Heap(2nd half)
        else if (num >= minHeap.top()) {
            minHeap.push(num);
        }
            //Push root of maxHeap to minHeap
        else {
            //Push num to 1st half
            if (num < maxHeap.top()) {
                int temp = maxHeap.top();
                maxHeap.pop();
                maxHeap.push(num);
                minHeap.push(temp);
            } else {
                //Push num to 2nd half
                minHeap.push(num);
            }
        }
    }
}

double findMedian() {
    int lSize = maxHeap.size();
    int rSize = minHeap.size();
    if (lSize > rSize) {
        return double(maxHeap.top());
    }
    return (double(maxHeap.top()) + double(minHeap.top())) / 2;
}

void printMedian(vector<int> stream) {
    for (auto i: stream) {
        cout << i << " added to Stream \t";
        addNum(i);
        cout << "current median is : " << findMedian() <<endl;
    }
}

int main() {
    vector<int> stream = {5, 15, 1, 3, 2, 8, 7, 9, 10, 6, 11, 4};
    printMedian(stream);
    return 0;
}
