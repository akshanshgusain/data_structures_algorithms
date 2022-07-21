//
// Created by Akshansh Gusain on 27/03/21.
//
//Find smallest number with given number of digits and sum of digits
#include<stdc++.h>

using namespace std;

void findSmallest(int m, int s) {
    if (s == 0) {
        (m == 1) ? cout << "Smallest number is " << 0
                 : cout << "Not possible";
        return;
    }

    // Sum greater than the maximum possible sum.
    if (s > 9 * m) {
        cout << "Not possible";
        return;
    }
    int result[m];

    // deduct sum by one to account for cases later
    // (There must be 1 left for the most significant
    //  digit)
    s -= 1;

    // Fill last m-1 digits (from right to left)
    for (int i=m-1; i>0; i--)
    {
        // If sum is still greater than 9,
        // digit must be 9.
        if (s > 9)
        {
            result[i] = 9;
            s -= 9;
        }
        else
        {
            res[i] = s;
            s = 0;
        }
    }

    // Whatever is left should be the most significant
    // digit.
    result[0] = s + 1;  // The initially subtracted 1 is
    // incorporated here.

    cout << "Smallest number is ";
    for (int i=0; i<m; i++)
        cout << result[i];

}

int main() {
    int s = 9, m = 2;
    findSmallest(m, s);
    return 0;
}
