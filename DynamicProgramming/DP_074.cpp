//
// Created by Akshansh Gusain on 02/01/22.
//

//https://www.geeksforgeeks.org/maximum-difference-zeros-ones-binary-string-set-2-time/
// Idea behind that if we convert all zeros into 1 and all ones into -1.now our problem reduces to find
// out the maximum sum sub_array Using Kadane’s Algorithm.
#include<stdc++.h>
using namespace std;


int findLength(string str, int n){
    int SUM_ENDING_HERE = 0;
    int MAX_SO_FAR = 0;

    // traverse a binary string from left
    // to right
    for (int i = 0; i < n; i++) {

        // add current value to the SUM_ENDING_HERE
        // according to the Character
        // if it's '0' add 1 else -1

        // Here # of 0s are more than # of 1s hence 0 is being replaced by one.
        SUM_ENDING_HERE += (str[i] == '0' ? 1 : -1);

        if (SUM_ENDING_HERE < 0)
            SUM_ENDING_HERE = 0;

        // update maximum sum
        MAX_SO_FAR = max(SUM_ENDING_HERE, MAX_SO_FAR);
    }

    // return -1 if string does not contain
    // any zero that means all ones
    // otherwise MAX_SO_FAR
    return MAX_SO_FAR == 0 ? -1 : MAX_SO_FAR;
}

int main(){
    string s = "11000010001";
    int n = 11;
    cout << findLength(s, n) << endl;
    return 0;
}