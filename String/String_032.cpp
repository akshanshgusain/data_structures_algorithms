//
// Created by Akshansh Gusain on 19/08/21.
//
#include<stdc++.h>

using namespace std;
#define CHAR 256

// Time: O(N),  Space: O(N)
string findSubString(string s) {
    int n = s.length();
    int distCount = 0;
    bool visited[CHAR] = {false};

    for (int i = 0; i < n; i++) {
        if (!visited[s[i]]) {
            visited[s[i]] = true;
            distCount++;
        }
    }

    int start = 0, start_index = 0, count = 0, min_len = INT_MAX, win_len = 0;
    int currCount[CHAR] = {0};
    for (int j = 0; j < n; j++) {
        currCount[s[j]]++;
        if (currCount[s[j]] == 1) {
            count++;
        }
        if (count == distCount) {
            while (currCount[s[start]] > 1) {
                if (currCount[s[start]] > 1) {
                    currCount[s[start]]--;
                }
                start++;
            }

            // Re calculate the window
            win_len = j - start + 1;
            if (min_len > win_len) {
                min_len = win_len;
                start_index = start;
            }
        }

    }


    return s.substr(start_index, min_len);
}

int main() {
    string str = "aabcbcdbca";
    cout << "Smallest window containing all distinct chars is: " << findSubString(str);
    return 0;
}
