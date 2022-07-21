//
// Created by Akshansh Gusain on 13/08/21.
//

#include<stdc++.h>

using namespace std;

char flipExpected(char x) {
    return (x == '0') ? '1' : '0';
}

int countFlips(string str, char expected) {
    int flips = 0;

    for (int i = 0; i < str.length(); i++) {
        if(str[i] != expected){
            flips++;
        }
        expected = flipExpected(expected);
    }

    return flips;
}

int minFlipToMakeStringAlternate(string str) {
    return min(countFlips(str, '0'), countFlips(str, '1'));
}

int main() {
    string str = "0001010111";
    cout << minFlipToMakeStringAlternate(str);
    return 0;
}