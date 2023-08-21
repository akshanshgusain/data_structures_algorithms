//
// Created by Akshansh Gusain on 04/08/21.
//

#include<stdc++.h>
using namespace std;

// Time: O(N), Space: O(N)
//Create a temp string and store concatenation of str1 to str1 in temp.
//If str2 is a substring of temp then str1 and str2 are rotations of each other.

bool areRotations(string str1, string str2){
    if (str1.length() != str2.length())
        return false;

    string temp = str1 + str1;

//    cout<<temp.find(str2)<<endl;
//    cout<<string::npos<<endl;
// IN Case of a mismatch above two returns:
//18446744073709551615
//18446744073709551615

//To put it simply, think of npos as no-position. As a return value, it is usually used to indicate
// that no matches were found in the string. Thus, if it returns true, matches were found at no positions
// (i.e., no matches)

    return (temp.find(str2) != string::npos);
}

int main(){
    string str1 = "AACD", str2 = "ACDA";
    if (areRotations(str1, str2))
        printf("Strings are rotations of each other");
    else
        printf("Strings are not rotations of each other");
    return 0;
}
