//
// Created by Akshansh Gusain on 19/08/21.
//

#include<stdc++.h>
using namespace std;

/// Remove all consecutive duplicates from the string
// IP: aaaaabbbbbb, OP: ab
void removeDuplicates(char* str){
    if(str[0] == '\0'){
        return;
    }
    if(str[0]==str[1]){
        int i  = 0;
        while(str[i] != '\0'){
            str[i] = str[i+1];
            i++;
        }

        removeDuplicates(str);
    }

    removeDuplicates(str + 1);
}

/// Remove all adjacent duplicates from the string
// Input: azxxzy, Output: ay

int main(){
    char S1[] = "geeksforgeeks";
    removeDuplicates(S1);
    cout << S1 << endl;

    return 0;
}