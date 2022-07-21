//
// Created by Akshansh Gusain on 24/01/21.
//
#include<stdc++.h>
using namespace std;

long swapCount(string s){
    int len = s.length();

    // Expressions of odd lengths
    // cannot be balanced
    if (len % 2 != 0) {
        return -1;
    }
    int left_brace = 0, right_brace = 0;
    int ans;
    for (int i = 0; i < len; i++) {

        // If we find a left bracket then we simply
        // increment the left bracket
        if (s[i] == '{') {
            left_brace++;
        }

        // Else if left bracket is 0 then we find
        // unbalanced right bracket and increment
        // right bracket or if the expression
        // is balanced then we decrement left
        else {
            if (left_brace == 0) {
                right_brace++;
            }
            else {
                left_brace--;
            }
        }
    }
    ans = ceil(left_brace / 2.0) + ceil(right_brace / 2.0);
    return ans;
}


int main(){

    string s = "}{{}}{{{";
    cout << swapCount(s) << "\n";

    s = "{{}{{{}{{}}{{";
    cout << swapCount(s) << "\n";
    return 0;
}
