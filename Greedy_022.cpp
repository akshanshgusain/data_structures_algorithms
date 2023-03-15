//
// Created by Akshansh Gusain on 27/08/22.
//
#include<bits/stdc++.h>

using namespace std;


void solve() {
    int w, h, n;
    cin >> w >> h >> n;
    unordered_set<int> coordinatesX(n);
    unordered_set<int> coordinatesY(n);
    int x, y;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        coordinatesX.insert(x);
        coordinatesY.insert(y);
    }

    int maxArea = INT_MIN;
    x = 0, y = 0;
    int x1 = 1, y1 = 1;

    while (x1 <= w) {
        if (coordinatesX.find(x1) == coordinatesX.end()) {
            // not found
            x1++;
            continue;
        } else {
            while (y1 <= h) {
                if (coordinatesY.find(y1) == coordinatesY.end()) {
                    y1++;
                    continue;
                } else {
                    maxArea = max(maxArea, (x1 - x - 1) * (y1 - y - 1));
                    cout<<x<<" "<<x1<<" "<<y<<" "<<y1<<" "<<endl;
                    y = y1;
                    y1++;
                }
            }
            // reset Y
            y = 0;
            y1 = 1;

            x = x1;
            x1++;
        }

    }

    cout << maxArea;
}


int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

/* Input
 1
15 8 3
3 8
11 2
8 6
 */

/*Output
 12
 */