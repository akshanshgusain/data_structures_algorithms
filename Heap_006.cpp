//
// Created by Akshansh Gusain on 25/07/22.
//
#include<stdc++.h>
using namespace std;

typedef pair<int, pair<int, int>> ppi;

// time : O(NKLogK),  Space: O(k)
vector<int> mergeKArrays(vector<vector<int>> arr){
    vector<int> output;

    //Create a min heap with k heap nodes. Every heap node has first element of an array
    priority_queue<ppi, vector<ppi>, greater<>> pq;

    //Push First elements to the heap
    for(int i = 0; i < arr.size(); i++){
        pq.push({arr[i][0], {i, 0}});
    }

    //Now one by one get the min element from the heap and replace it with next element of its array
    while(!pq.empty()){
        ppi curr = pq.top();
        pq.pop();

        //i == Array Number
        //j == Index in the array number
        int i = curr.second.first;
        int j = curr.second.second;

        output.push_back(curr.first);

        // The next element belongs to same array as
        // current.
        if (j + 1 < arr[i].size())
            pq.push({ arr[i][j + 1], { i, j + 1 } });
    }

    return output;
}

int main(){
    vector<vector<int> > arr{ { 2, 6, 12 },{ 1, 9 },{ 23, 34, 90, 2000 } };
    vector<int> output = mergeKArrays(arr);
    cout << "Merged array is " << endl;
    for (auto x : output)
        cout << x << " ";

    return 0;
}