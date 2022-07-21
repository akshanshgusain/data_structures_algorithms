//
// Created by Akshansh Gusain on 24/01/21.
//
#include<stdc++.h>
using namespace std;

long swapCount(string s){
    //keep track of '['
    vector<int> pos;
    for(int i=0; i<s.length(); i++){
        if(s[i]=='['){
            pos.push_back(i);
        }
    }
    int count =0; //To count number of encountered '['
    int p = 0; //To track position of next '[' in pos
    long sum = 0; //To store result

    for(int i=0; i<s.length(); i++){

        //increment count and move p to the next position
        if(s[i]=='['){
            ++count;
            ++p;
        }else if(s[i] == ']'){
            --count;
        }

        //we have encountered an unbalanced part of string
        if(count < 0){
            //Increment the sum by number of swaps required
            //i.e., position of next '[' - current position

            sum += pos[p] - i;
            swap(s[i], s[pos[p]]);
            ++p;
            //reset count to 1
            count = 1;
        }
    }
    return sum;
}


int main(){

    string s = "[]][][";
    cout << swapCount(s) << "\n";

    s = "[[][]]";
    cout << swapCount(s) << "\n";
    return 0;

    return 0;
}
