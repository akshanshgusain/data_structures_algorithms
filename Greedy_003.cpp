//
// Created by Akshansh Gusain on 19/08/22.
//
#include<bits/stdc++.h>

using namespace std;

int dfs(int index, int &ans, vector<int> &startingVOfPipes, vector<int> &diameter) {
    // base case
    if (startingVOfPipes[index] == 0) {
        return index;
    }
    if (diameter[index] < ans) {
        ans = diameter[index];
    }
    return dfs(startingVOfPipes[index], ans, startingVOfPipes, diameter);
}

void solve(int n, int p, vector<int> &a, vector<int> &b, vector<int> &d) {

    // index is the starting and value is the ending position.
    vector<int> startingVOfPipes(p,0);
    // index is the ending and value is the starting position.
    vector<int> endingVOfPipes(p,0);
    // ith position is the starting and ith value is the diameter.
    vector<int> diameter(p,0);

    // Create a graph
    int index = 0;
    while (index < p) {
        int start = a[index];
        int end = b[index];
        int dia = d[index];

        startingVOfPipes[start] = end;
        endingVOfPipes[end] = start;
        diameter[start] = dia;
        index++;
    }

    // Vector tanks, taps, diameters are used
    // to store the final output
    vector<int> tanks; //tanks
    vector<int> taps; //taps
    vector<int> diameters;//diameter
    int ans;
    for (int j = 1; j <= n; j++) {
        //a tank - house has no incoming vertex: endingVOfPipes[j] == 0
        // and one outgoing vertex startingVOfPipes[j] have some value
        // start DFS from there
        if (endingVOfPipes[j] == 0 and startingVOfPipes[j]) {
            ans = INT_MAX;
            int w = dfs(j, ans, startingVOfPipes, diameter);

            tanks.push_back(j);
            taps.push_back(w);
            diameters.push_back(ans);
        }
    }

    cout << tanks.size() << endl;
    for (int j = 0; j < tanks.size(); ++j)
        cout << tanks[j] << " " << taps[j] << " " << diameters[j] << endl;

}

int main() {
    int n = 9, p = 6;
    vector<int> a = {7, 5, 4, 2, 9, 3};
    vector<int> b = {4, 9, 6, 8, 7, 1};
    vector<int> d = {98, 72, 10, 22, 17, 66};
    solve(n, p, a, b, d);
    return 0;
}