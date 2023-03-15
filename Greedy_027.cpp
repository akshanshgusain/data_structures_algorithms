//
// Created by Akshansh Gusain on 13/09/22.
//

#include<bits/stdc++.h>

using namespace std;

void findSmallest(int s, int d) {


    // If sum of digits is 0, then a number is possible
    // only if number of digits is 1.
    if (s == 0) {
        (d == 1) ? cout << "Smallest number is " << 0
                 : cout << "Not possible";
        return;
    }

    // Sum greater than the maximum possible sum.
    if (s > 9 * d) {
        cout << "Not possible";
        return;
    }


    vector<int> result(d);
    // deduct sum by one to account for cases later
    // (There must be 1 left for the most significant
    //  digit)
    s -= 1;


    // Fill last m-1 digits (from right to left)
    for (int i = d - 1; i > 0; i--) {
        // If sum is still greater than 9,
        // digit must be 9.
        if (s > 9)
        {
            result[i] = 9;
            s -= 9;
        }
        else
        {
            result[i] = s;
            s = 0;
        }
    }

    result[0] = s + 1;
    cout << "Smallest number is ";
    for (int i=0; i<d; i++)
        cout << result[i];
}


int main() {
    int s, d;
    cin >> s >> d;
    findSmallest(s, d);
    return 0;
}