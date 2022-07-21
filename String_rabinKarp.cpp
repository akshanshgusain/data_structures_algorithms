//
// Created by Akshansh Gusain on 20/01/21.
//
#include<stdc++.h>
using namespace std;
#define CHAR 256

void searchRK(char pattern[], char text[], int q){
        int M = strlen(pattern);  //Length of pattern
        int N = strlen(text); //Length of text
        int p = 0; //Hash value for pattern;
        int t = 0; //hash value for text;

        int i,j;
        int h=1; // h = pow(CHAR, M-1) % q

        // The value of h would be "pow(CHAR, M-1)%q"
        for(i = 0; i < M - 1 ; i++){
            h = (h * CHAR) % q;
        }

        //calculate the hash value of pattern and first value of window of text
        for( i = 0; i<M; i++){
            p = (CHAR * p + pattern[i]) % q;
            t = (CHAR * t + text[i]) % q;
        }

        //Slide the pattern over text one by one
        for(i=0; i <= N-M; i++ ){

            //Check the hash value of current window of text and pattern.
            // If the hash value matches only then check for character one by one

            if(p == t){
                // check for character one by one
                for(j=0; j<M; j++){
                    if(text[i+j] != pattern[j]){
                        break;
                    }
                }
                if(j == M){
                    cout<<"Pattern found at index: "<< i<<endl;
                }
            }

            //If the hash value does not matches, Calculate hash value for the next window of text:
            //remove leading digit and add trailing digit

            if(i < N-M){
                t = (CHAR*(t-text[i]*h) + text[i+M]) % q;
                if(t<0)
                    t = (t+q);
            }
        }
}

int main(){
    char text [] = "abcdfertyoig34jt9034ionfdwoig3hjt390wo";
    char pattern[] = "34jt9034ionfdwoig";

    int q = 101; //prime Number

    searchRK(pattern, text, q);

    return 0;
}