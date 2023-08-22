#include<bits/stdc++.h>

using namespace std;

// time: O(8^(N^2)
// space: O(N^2)

int isSafe(int x, int y, vector<vector<int>> &chessBoard) {
    int N = chessBoard.size();
    return (x >= 0 && x < N && y >= 0 && y < N && chessBoard[x][y] == -1);
}

void printSolution(vector<vector<int>> &chessboard) {
    int n = chessboard.size();

    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++)
            cout << " " << setw(2) << chessboard[x][y] << " ";
        cout << endl;
    }
}


bool solveKTUtil(int x, int y, int moveCounter, vector<vector<int>> &chessBoard, int n, vector<int> xMove,
                vector<int> yMove) {

    int next_x, next_y;

    if (moveCounter == n * n) {
        return true;
    }

    /* Try all next moves from
    the current coordinate x, y */
    for (int k = 0; k < 8; k++) {
        next_x = x + xMove[k];
        next_y = y + yMove[k];

        if (isSafe(next_x, next_y, chessBoard)) {
            chessBoard[next_x][next_y] = moveCounter;

            if (solveKTUtil(next_x, next_y, moveCounter + 1, chessBoard, n, xMove, yMove)) {
                return true;
            } else {
                // backtracking
                chessBoard[next_x][next_y] = -1;
            }
        }
    }
    return false;
}



int solveKT() {
    vector<vector<int>> chessBoard(8, vector<int>(8, -1));


    /* xMove[] and yMove[] define next move of Knight.
    xMove[] is for next value of x coordinate
    yMove[] is for next value of y coordinate */
    vector<int> xMove = {2, 1, -1, -2, -2, -1, 1, 2};
    vector<int> yMove = {1, 2, 2, 1, -1, -2, -2, -1};

    // Since the Knight is initially at the first block
    chessBoard[0][0] = 0;

    /* Start from 0,0 and explore all tours using
    solveKTUtil() */
    if (solveKTUtil(0, 0, 1, chessBoard, chessBoard.size(), xMove, yMove) == 0) {
        cout << "Solution does not exist";
        return 0;
    } else
        printSolution(chessBoard);

    return 1;
}


// Driver Code
int main() {
    // Function Call
    solveKT();
    return 0;
}