#include<bits/stdc++.h>

#define int long long int
#define F first
#define S second
#define pb push_back
#define all(p) p.begin(), p.end()

using namespace std;
const int inf = 1e15;
const int M = 1e9 + 7;

vector<int> spiralOrder(vector<vector<int>> &matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    vector<int> op;

    if (m == 0) {
        return op;
    }

    vector<vector<bool>> seen(n, vector<bool>(m, false));
    int directionRow[] = { 0, 1, 0, -1 };
    int directionColumn[] = { 1, 0, -1, 0 };

    int x = 0, y = 0, di = 0;
    // Iterate from 0 to m * n - 1


}


int32_t main() {

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    vector<vector<int>> matrix = {{1,  2,  3,  4},
                                  {5,  6,  7,  8},
                                  {9,  10, 11, 12},
                                  {13, 14, 15, 16}};
    vector<int> op = spiralOrder(matrix);
    for (auto &it: op) {
        cout << it << " ";
    }

    return 0;
}