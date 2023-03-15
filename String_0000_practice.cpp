//
// Created by Akshansh Gusain on 04/08/21.
//


#include <stdc++.h>
using namespace std;

bool isPalindrome(string ip){
    int i = 0, j = ip.size()-1;
    while(i <= j){
        if(tolower(ip[i]) != tolower(ip[j])){
            return false;
        }
        i++, j--;
    }
    return true;
}

int main() {
    string ip = "anant";
    isPalindrome(ip)? cout<<"True" : cout<<"False";
    return 0;
}