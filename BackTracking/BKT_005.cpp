//
// Created by Akshansh Gusain on 21/08/23.
//

#include<stdc++.h>

using namespace std;


void printPartitions(vector<vector<string>> &allParts) {
    for (int i = 0; i < allParts.size(); i++) {
        for (int j = 0; j < allParts[i].size(); j++) {
            cout << allParts[i][j] << " ";
        }
        cout << endl;
    }
}


bool isPalindrome(string str, int low, int high) {
    while (low < high) {
        if (str[low] != str[high])
            return false;
        low++;
        high--;
    }
    return true;
}

void allPalindromicPartitionsUtil(
        vector<vector<string>> &allPart,
        vector<string> &currPart,
        int start,
        int end,
        const string& str
) {

    // If 'start' has reached len, BASE CASE
    if (start >= end) {
        allPart.push_back((currPart));
    }

    // Pick all possible ending points for substrings
    for (int i = start; i < end; i++) {

        //If substring str[start...i] is palindrome
        if (isPalindrome(str, start, i)) {

            currPart.push_back(str.substr(start, i - start + 1));

            //Recur for remaining substring
            allPalindromicPartitionsUtil(allPart, currPart, i + 1, end, str);

            //Remove substring str[start..i] from current partition
            currPart.pop_back();
        }
    }
}

void allPalindromicPartitions(const string& str) {
    int n = str.size();

    vector<vector<string>> allParts;
    vector<string> currPart;

    allPalindromicPartitionsUtil(allParts, currPart, 0, n, str);

    printPartitions(allParts);
}

int main() {
    string str = "nitin";
    allPalindromicPartitions(str);
    return 0;
}


/*
n i t i n
n iti n
nitin
 */