//
// Created by Akshansh Gusain on 21/01/21.
//
//Search a Word in a 2D Grid of characters. search in 8 directions
#include<stdc++.h>
using namespace std;
#define R 3
#define C 14

// Time: O(R*C*N) // N is the length of the input string, Space: O(1)
// For searching in all 8 direction

int x[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int y[] = { -1, 0, 1, -1, 1, -1, 0, 1 };


//// This function searches in all 8-direction from point (row, col) in grid[][]
bool search2D(char grid[R][C], int row, int col, string word){

    if(grid[row][col] != word[0]){
        return false;
    }
    int len = word.length();
    //search word in all 8 directions

    for(int dir=0; dir< 8 ; dir++){
        //init a starting point for current direction
        int k, rd = row+x[dir], cd = col+y[dir];

        //first char is already checked match remaining characters
        for(k=1;k<len; k++){
            //if out of bonds break
            if(rd>= R || rd<0 || cd >=C || cd<0)
                break;
            if(grid[rd][cd] != word[k])
                break;
            rd+= x[dir];
            cd+= y[dir];
        }

        //if the k is equal to the length of the word then: the word must be found
        if(k==len){
            return true;
        }

    }
    return false;
}

void patternSearch(char grid[R][C], string word){
    //consider every point as starting point and search for given word
    for(int row = 0; row< R ; row++){
        for(int col=0; col< C ;col++){
            if(search2D(grid, row, col, word)){
                cout<<"Pattern found at: "<<row<<" ,"<<col<<endl;
            }
        }
    }
}

int main(){
    char grid[R][C] = { "GEEKSFORGEEKS",
                        "GEEKSQUIZGEEK",
                        "IDEQAPRACTICE" };

    patternSearch(grid, "GEEKS");
    cout << endl;

    return 0;
}
