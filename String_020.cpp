//
// Created by Akshansh Gusain on 13/08/21.
//

#include<stdc++.h>
using namespace std;

// Time: O(n), Space: O(1)

long swapCount(string s){
    // Odd length strings can't be balanced
    if(s.length()%2 != 0){
        return -1;
    }

    int left_brackets = 0, right_brackets = 0, ans = 0;
    for(char i : s){
        if(i == '{'){
            left_brackets ++;
        }else{
            if(left_brackets > 0){
                left_brackets--;
            }else{
                right_brackets++;
            }
        }
    }

    ans = ceil(left_brackets/2.0) + ceil(right_brackets/2.0);
    return ans;
}

int main(){

    string s = "}{{}}{{{";
    cout << swapCount(s) << "\n";

    s = "{{}{{{}{{}}{{";
    cout << swapCount(s) << "\n";
    return 0;
}