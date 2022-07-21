//
// Created by Akshansh Gusain on 31/01/21.
//
#include<stdc++.h>
using namespace std;
#define MAX_CHAR 256

bool areIsomorphic(string str1, string str2){
    int m = str1.length(), n = str2.length();
    if(m!= n){
        return false;
    }
    //To mark visited characters in str2
    bool marked[MAX_CHAR] = {false};

    //To store mapping of every character from str1 to that of str2. Initialize all entries of map as -1
    int map[MAX_CHAR];
    memset(map, -1, sizeof(map));

    //process all characters
    for(int i=0 ; i<n ; i++){
        //If current character of str1 is seen first time in it
        if(map[str1[i]] == -1){

            //If current chars of str2 as visited seen, one to one mapping not possible
            if(marked[str2[i]]){
                return false;
            }
            //mark current chars of str2 as visited
            marked[str2[i]] = true;

            //Store mapping of current characters
            map[str1[i]] = str2[i];
        }
        else if(map[str1[i]] != str2[i]){
            return false;
        }
    }
    return true;
}

int main(){
    cout << areIsomorphic("aab", "xxy") << endl;
    cout << areIsomorphic("aab", "xyz") << endl;
    return 0;
}