//
// Created by Akshansh Gusain on 30/01/21.
//
#include<stdc++.h>
using namespace std;

bool match(char *first, char *second){
    //base case
    if(*first == '\0' && *second == '\0'){
        return true;
    }

    if(*first == '*' && *(first+1) != '\0' && *second == '\0'){
        return false;
    }

    if(*first == '?' || *first == *second){
        return match(first+1,second+1);
    }

    if(*first == '*'){
        return match(first+1, second) || match(first, second+1);
    }
    return false;
}

void test(char *first, char *second){
    match(first, second)? puts("YES") : puts("NO");
}

int main(){
    test("g*ks", "geeks"); // Yes
    test("ge?ks*", "geeksforgeeks"); // Yes
    test("g*k", "gee");  // No because 'k' is not in second
    test("*pqrs", "pqrst"); // No because 't' is not in first
    test("abc*bcd", "abcdhghgbcd"); // Yes
    test("abc*c?d", "abcd"); // No because second must have 2
    // instances of 'c'
    test("*c*d", "abcd"); // Yes
    test("*?c*d", "abcd"); // Yes
    return 0;
}
