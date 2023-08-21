//
// Created by Akshansh Gusain on 20/08/23.
//
#include<bits/stdc++.h>

using namespace std;

void printSolutions(vector<vector<string>> &result) {
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[0].size(); j++) {
            cout << result[i][j];
        }
        cout << endl;
    }
}


bool isSafe(vector<string> &board, int row, int col) {

    // since we are placing one queen per row, we will have to check:
    // 1.  If there is any queen on the same column as current queen
    for (int i = row; i >= 0; i--) {
        if (board[i][col] == 'Q') {
            return false;
        }
    }

    // 2. if there is any queen on the Left-Up-Diagonal as current queen
    for (int i = row, j = col; i >= 0 and j >= 0; i--, j--) {
        if (board[i][j] == 'Q') {
            return false;
        }
    }

    // 3. if there is any queen on the Right-Up-Diagonal as current queen
    for (int i = row, j = col; i >= 0 and j < board.size(); i--, j++) {
        if (board[i][j] == 'Q') {
            return false;
        }
    }

    return true;
}


void dfs(vector<string> &board, int row, vector<vector<string>> &result) {

    if (row == board.size()) {
        result.push_back(board);
        return;
    }

    //iterate over all possible positions
    for (int i = 0; i < board.size(); i++) {
        //check if a queen can be placed on board[i][col]
        if (isSafe(board, row, i)) {

            // place a queen in this box of the board
            board[row][i] = 'Q';

            // recursively solve for rest of the bard
            dfs(board, row + 1, result);

            // backtrack
            board[row][i] = '.';
        }
    }
}

vector<vector<string>> solveNQueens(int n) {
    vector<string> board(n, string(n, '.'));
    vector<vector<string>> result;
    dfs(board, 0, result);
    printSolutions(result); // optional step
    return result;
}


/*
Input: n = 4
Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above
 */

int main() {
    int n = 4;
    vector<vector<string>> res = solveNQueens(n);
    return 0;
}