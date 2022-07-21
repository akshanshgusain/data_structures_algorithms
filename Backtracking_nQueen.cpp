//
// Created by Akshansh Gusain on 27/03/21.
//
#include<stdc++.h>

using namespace std;
#define N 4

void printSolution(int board[N][N]) {
    static int k = 1;
    printf("%d-\n", k++);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf(" %d ", board[i][j]);
        printf("\n");
    }
    printf("\n");
}

bool isSafe(int board[N][N], int row, int col) {
    int i, j;
    //check this row on left side
    for (i = 0; i < col; i++) {
        if (board[row][i]) {
            return false;
        }
    }

    //check upper diagonal on left side
    for (i = row, j = col; i >= 0 and j >= 0; i--, j--) {
        if (board[i][j]) {
            return false;
        }
    }

    //check lower diagonal on left side
    for (i = row, j = col; j >= 0 and i < N; i++, j--) {
        if (board[i][j]) {
            return false;
        }
    }
    return true;
}

bool solveNQ(int board[N][N], int col) {
    if(col == N){
        printSolution(board);
        return true;
    }
    bool res = false;
    for (int i = 0; i < N; i++) {
        //check if a queen can be placed on board[i][col]
        if (isSafe(board, i, col)) {
            //place the queen in board[i, col]
            board[i][col] = 1;

            //make result true if any placement is possible
            res = solveNQ(board, col + 1) || res;

            /* If placing queen in board[i][col]
        doesn't lead to a solution, then
        remove queen from board[i][col] */
            board[i][col] = 0; // BACKTRACK
        }
    }
    /* If queen can not be place in any row in
       this column col then return false */
    return res;
}

int main() {
    int board[N][N];
    memset(board, 0, sizeof(board));
    if (!solveNQ(board, 0)) {
        cout << "No Solution Exist! " << endl;
    }
    return 0;
}
