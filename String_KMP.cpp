//
// Created by Akshansh Gusain on 20/01/21.
//
#include<stdc++.h>
using namespace std;

// Fills lps[]LONGEST PREFIX SUFFIX for given patttern pat[0..M-1]
void computeLPSArray(char* pat, int M, int* lps)
{
    // length of the previous longest prefix suffix
    int len = 0;

    lps[0] = 0; // lps[0] is always 0

    // the loop calculates lps[i] for i = 1 to M-1
    int i = 1;
    while (i < M) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else // (pat[i] != pat[len])
        {
            // This is tricky. Consider the example.
            // AAACAAAA and i = 7. The idea is similar
            // to search step.
            if (len != 0) {
                len = lps[len - 1];

                // Also, note that we do not increment
                // i here
            }
            else // if (len == 0)
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void KMPSearch(char* pattern, char* text){
    int M = strlen(pattern); // Length of the pattern
    int N = strlen(text); // Length of the Text

    //Create lps[] that will store the LONGEST PREFIX SUFFIX value of the pattern
    int lps[M];
    computeLPSArray(pattern, M, lps);

    int i =0, j=0; // i points to text[] and j points to pattern[]
    while(i<N){
        if(pattern[j] == text[i]){
            j++; i++;

        }
        if(j == M){
            cout<<"Pattern Found at :"<< i-j;
            j = lps[j-i];
        }
        //mismatch after j matches
        else if(i < N && pattern[j] != text[i]){
                //do not match lps[o]..lps[j-1] chars, they will match anyway
                if( j != 0){
                    j = lps[j-1];
                }else{
                    i = i+1;
                }
        }
    }

}

int main(){
    char text[] = "ababdabacdababcabab";
    char pattern[] = "ababcabab";
    KMPSearch(pattern, text);
    return 0;
}
