//
// Created by Akshansh Gusain on 26/03/21.
//
//Very similar to huffman encoding

#include<stdc++.h>

using namespace std;


int minCost(int arr[], int n) {
    priority_queue<int , vector<int>, greater<>> pq(arr,arr+n);
    int result =0;

    while(pq.size() > 1){
        int first = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();

        result+= first+second;
        pq.push(first+second);
    }
    return result;
}

int main() {
    int len[] = {4, 3, 2, 6};
    int size = sizeof(len) / sizeof(len[0]);
    cout << "Total cost for connecting ropes is "
         << minCost(len, size);
    return 0;
}
