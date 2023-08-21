//
// Created by Akshansh Gusain on 09/01/21.

#include<stdc++.h>
using namespace std;

void printSubString(char* str, int low, int high){
    for(int i =low; i<=high ;i++){
        cout<<str[i];
    }
}

int longestPalindrome(char* str){

    int maxLength = 1;
    int start = 0;
    int len = strlen(str);

    int low,high;

    for(int i=1; i<len; i++){
        //For even Length Palindrome
        low = i-1;
        high = i;
        while(low>=0 && high<=len && str[low]==str[high]){
            if(high - low + 1 > maxLength){
                maxLength = high - low + 1;
                start = low;
            }
            --low;
            ++high;
        }


        //For Odd length
        low = i-1;
        high = i+1;

        while(low>=0 && high<=len && str[low]==str[high]){
            if(high - low + 1 > maxLength){
                maxLength = high - low + 1;
                start = low;
            }
            --low;
            ++high;
        }
    }

    cout<<"Longest Palindromic Substring is: ";
    printSubString(str, start, start+maxLength-1);
    return maxLength;
}

int main(){
    char str[] = "aaaabbaa";
    cout << longestPalindrome(str)
        << "\nLength is: "
        << endl;

    return 0;
}