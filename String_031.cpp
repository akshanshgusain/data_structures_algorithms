//
// Created by Akshansh Gusain on 18/08/21.
//
#include<stdc++.h>

using namespace std;

void traversal(string s, int index, string currentSegment, string currentString,
               int count, vector<string> &ans) {

    /// Base cases
    // either we have 4 segments or we have exceeded the end of the string
    if (count > 4 or index > s.length()) {
        return;
    }
    // we have reached the end of the string
    if (index == s.length()) {
        if (count == 4) {
            ans.push_back(currentString);
        }
        return;
    }

    string tempStr = currentSegment + s[index];
    int temp = stoi(tempStr); // convert string to integer

    /// If current segment is less than or equal to 255, 1st Traversal
    // 1. Keep increasing the current segment

    if (temp <= 255) {
        if (tempStr.size() > 1 and tempStr[0] == '0');
        else {
            traversal(s, index + 1, tempStr, currentString + s[index],
                      count, ans);
        }
    }

    /// If current segment is less than or equal to 255,  2nd Traversal
    // 2. ending at the current index add "." to the string and  start a new segment with the currentindex.

    if (count <= 4 and currentString.size() != 0) {
        string str = "";
        str += s[index];

        traversal(s, index + 1, str, currentString + '.' + s[index],
                  count + 1, ans);
    }
}

void restoreIP(string s) {
    vector<string> ans;
    traversal(s, 0, "", "", 1, ans);
    for(auto it: ans){
        cout<<it<<endl;
    }
}


int main() {
    string A = "25525511135";
    string B = "25505011535";

    restoreIP(A);
    //convert(B);
    return 0;
}
