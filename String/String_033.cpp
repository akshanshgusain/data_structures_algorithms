//
// Created by Akshansh Gusain on 19/08/21.
//
#include<stdc++.h>

using namespace std;
#define CHAR 256

// Time: O(N),  Space: O(N)
string findSubString(string s, string pat) {
    int n = s.length();
    int m = pat.length();

    if(m > n){
        return "-1";
    }

    int hashString[CHAR] = {false};
    int hashPattern[CHAR] = {false};

    for (int i = 0; i < m; i++) {
        hashPattern[pat[i]]++;
    }

    int start = 0, start_index = -1, count = 0, min_len = INT_MAX, win_len = 0;

    for (int j = 0; j < n; j++) {
        hashString[s[j]]++;

        if (hashString[s[j]] <= hashPattern[s[j]]) {
            count++;
        }

        if (count == m) {
            while (hashString[s[start]] > hashPattern[s[start]] || hashPattern[s[start]] == 0) {
                if (hashString[s[start]] > hashPattern[s[start]]) {
                    hashString[s[start]]--;
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

    if(start_index == -1){
        return "-1";
    }

    return s.substr(start_index, min_len);
}

int main() {
    string str = "this is a test string";
    string pat = "tist";
    cout<<"Smallest window containing all distinct chars is: "<<findSubString(str, pat);
    ///  t stri
    return 0;
}
