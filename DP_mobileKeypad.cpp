//
// Created by Akshansh Gusain on 04/06/21.
//
#include<stdc++.h>

using namespace std;
// left, up, right, down move from current location
int row[] = {0, 0, -1, 0, 1};
int col[] = {0, -1, 0, 1, 0};


int getCountUtil(char keypad[][3], int i, int j, int n) {
    if (keypad == NULL || n <= 0)
        return 0;

    // From a given key, only one number is possible of length 1
    if (n == 1)
        return 1;

    int k = 0, move = 0, ro = 0, co = 0, totalCount = 0;

    // move left, up, right, down from current location and if
    // new location is valid, then get number count of length
    // (n-1) from that new position and add in count obtained so far
    for (move = 0; move < 5; move++) {
        ro = i + row[move];
        co = j + col[move];
        if (ro >= 0 && ro <= 3 && co >= 0 && co <= 2 &&
            keypad[ro][co] != '*' && keypad[ro][co] != '#') {
            totalCount += getCountUtil(keypad, ro, co, n - 1);
        }
    }

    return totalCount;
}


int getCount(char keypad[][3], int n) {
    // Base cases
    if (keypad == NULL || n <= 0)
        return 0;
    if (n == 1)
        return 10;

    int i = 0, j = 0, totalCount = 0;
    for (i = 0; i < 4; i++)  // Loop on keypad row
    {
        for (j = 0; j < 3; j++)   // Loop on keypad column
        {
            // Process for 0 to 9 digits
            if (keypad[i][j] != '*' && keypad[i][j] != '#') {
                // Get count when number is starting from key
                // position (i, j) and add in count obtained so far
                totalCount += getCountUtil(keypad, i, j, n);
            }
        }
    }
    return totalCount;
}

int main() {
    char keypad[4][3] = {{'1', '2', '3'},
                         {'4', '5', '6'},
                         {'7', '8', '9'},
                         {'*', '0', '#'}};
    cout << "Count for numbers of length : " << 1 << " is : " << getCount(keypad, 1);
    cout << "Count for numbers of length : " << 2 << " is : " << getCount(keypad, 2);
    cout << "Count for numbers of length : " << 3 << " is : " << getCount(keypad, 3);
    cout << "Count for numbers of length : " << 4 << " is : " << getCount(keypad, 4);
    cout << "Count for numbers of length : " << 5 << " is : " << getCount(keypad, 5);
    return 0;
}

