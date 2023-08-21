
#include<bits/stdc++.h>

#define int long long int
#define F first
#define S second
#define pb push_back
#define all(p) p.begin(), p.end()

using namespace std;

int minCost(vector<int> &lens){
    priority_queue<int, vector<int>, greater<>> queue;

    for(auto it: lens){
        queue.push(it);
    }
    int cost = 0;
    while(queue.size()!= 1){
        int top = queue.top(); queue.pop();
        int secondTop = queue.top(); queue.pop();

        cost += (top + secondTop);
        queue.push(top + secondTop);
    }

    return cost;
}

int32_t main(){
    vector<int> lens = { 4, 3, 2, 6 };
    cout << "Total cost for connecting ropes is " << minCost(lens);

    return 0;
}