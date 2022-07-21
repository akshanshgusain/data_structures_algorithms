//
// Created by Akshansh Gusain on 02/08/21.
//
#include<stdc++.h>

using namespace std;

int kthSmallestNumber(vector<vector<int>> &mat, int k){
    auto cmp = [=](pair<int,int> a,pair<int,int> b){
        return mat[a.first][a.second] > mat[b.first][b.second];
    };

    priority_queue<pair<int, int>, vector<pair<int,int>>, decltype(cmp)> pq(cmp);
    for(int i = 0; i < mat.size() ; i++){
        pq.push({i,0});
    }

    // running loop for (k-1) times
    for(int i = 1; i< k ; i++){
        auto p = pq.top();
        pq.pop();
        //after popping, we'll push next element of the same row in the heap
        if(p.second+1 < mat.size()){
            pq.push({p.first, p.second+1});
        }
    }
    //on the kth iteration, pq.top() will be our answer
    return mat[pq.top().first][pq.top().second];
}

int main() {
    vector<vector<int>> mat = {{10, 20, 30, 40},
                       {15, 25, 35, 45},
                       {25, 29, 37, 48},
                       {32, 33, 39, 50},};
    cout<<"7th Smallest Number :"<< kthSmallestNumber(mat, 7);
    return 0;
}
