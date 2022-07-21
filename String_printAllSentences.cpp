//
// Created by Akshansh Gusain on 31/01/21.
//
#include<stdc++.h>
using namespace std;
#define R 3
#define C 3

void printUtil(string arr[R][C], int m, int n, string output[R]){
    // Add current word to output array
    output[m] = arr[m][n];

    // If this is last word of current output sentence, then print
    // the output sentence
    if (m==R-1)
    {
        for (int i=0; i<R; i++)
            cout << output[i] << " ";
        cout << endl;
        return;
    }

    // Recur for next row
    for (int i=0; i<C; i++){
        if (arr[m+1][i] != ""){
            printUtil(arr, m+1, i, output);
        }
    }
}

void print(string arr[R][C]){
    //create an array to store sentences
    string output[R];
    
    // Consider all words for first row as starting points and
    // print all sentences
    for(int i=0; i<C; i++){
        if(arr[0][i] != ""){
            printUtil(arr, 0, i, output);
        }
    }
}
int main(){
    string arr[R][C]  = {{"you", "we"},
                         {"have", "are"},
                         {"sleep", "eat", "drink"}};

    print(arr);
    return 0;
}