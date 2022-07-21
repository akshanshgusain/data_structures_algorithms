//
// Created by Akshansh Gusain on 22/01/21.
//
#include<stdc++.h>
using namespace std;
# define NO_OF_CHARS 256


void badCharHeuristic( string pattern, int size, int badChar[NO_OF_CHARS]){
        int  i ;
        for(i=0; i<NO_OF_CHARS; i++){
            badChar[i]= -1;
        }
        //fill the actual value of last occurrence of character
        for(i = 0; i < size ; i++){
            badChar[(int)pattern[i]] = i;
        }
}

void search(string text, string pattern){
    int m = pattern.size();
    int n = text.size();

    int badChar[NO_OF_CHARS];
    badCharHeuristic(pattern, m, badChar);

    int s=0; // s is shift of pattern with respect to text

    while(s <= (n-m)){
        int j = m-1;

        //Keep reducing index j of pattern while chars of pattern and text are matching at the shift
        while(j >= 0 && pattern[j] == text[s+j]){
            j--;
        }

        //if the pattern is present at the current shift then the j becomes -1
        if(j < 0){
            cout<<"Pattern occurs at shift = "<< s<<endl;

            /* Shift the pattern so that the next character in text aligns with the last
            occurrence of it in pattern. The condition s+m < n is necessary for
            the case when pattern occurs at the end of text */
            s+= (s+m < n) ? m-badChar[text[s+m]] : 1;
        }

        else{
            /* Shift the pattern so that the bad character in text aligns with the last occurrence of
            it in pattern. The max function is used to make sure that we get a positive shift.
            We may get a negative shift if the last occurrence of bad character in pattern
            is on the right side of the current character. */

            s+= max(1 , j-badChar[text[s+j]]);
        }
    }
}

int main(){
    string text = "ABAABCD";
    string pattern = "ABC";
    search(text, pattern);
    return 0;
}
