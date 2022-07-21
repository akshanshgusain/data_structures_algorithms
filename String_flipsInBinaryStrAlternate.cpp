//
// Created by Akshansh Gusain on 22/01/21.
//
#include<stdc++.h>
using namespace std;

char flip(char ch){
    return (ch=='0') ? '1' : '0';
}

int getFlipWithStartingChar(string str, char expected){
        int flipCount =0;
        for(int i=0; i<str.length(); i++){
             if(str[i] != expected){
                 flipCount++;
             }
             //flip expected char each time
             expected = flip(expected);
        }
        return flipCount;
}

int minFlipToMakeStringAlternate(string str){

    return min(getFlipWithStartingChar(str, '0'), getFlipWithStartingChar(str, '1'));
}

int main(){
    string str = "0001010111";
    cout << minFlipToMakeStringAlternate(str);
    return 0;
}

