//
// Created by Akshansh Gusain on 16/03/24.
//
#include<stdc++.h>

using namespace std;

class Cell {
public:
    int x;
    int y;
};

// Function to check whether the cell is delimiter
// which is (-1, -1)
bool isdelim(Cell temp) {
    return (temp.x == -1 && temp.y == -1);
}

bool isValid(int i, int j, int rows, int cols) {
    return (i >= 0 and j >= 0 and i < rows and j < cols);
}

// Function to check whether there is still a fresh
// orange remaining
bool checkall(vector<vector<int>> &arr) {
    int rows = arr.size();
    int cols = arr[0].size();

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            if (arr[i][j] == 1)
                return true;
    return false;
}

int rotOranges(vector<vector<int>> &arr) {
    int rows = arr.size();
    int cols = arr[0].size();

    queue<Cell> Q;
    Cell temp{};
    int ans = 0;

    // Store all the cells having rotten orange in first time frame
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (arr[i][j] == 2) {
                temp.x = i;
                temp.y = j;
                Q.push(temp);
            }
        }
    }

    // Separate these rotten oranges from the oranges which will rotten
    // due the oranges in first time frame using delimiter which is (-1, -1)
    temp.x = -1;
    temp.y = -1;
    Q.push(temp);

    //Process the grid while there are rotten oranges in the Queue
    while (!Q.empty()) {
        // This flag is used to determine whether even a single fresh
        // orange gets rotten due to rotten oranges in current time
        // frame so we can increase the count of the required time.
        bool flag = false;

        //Process all the rotten oranges in current time frame.
        while (!isdelim(Q.front())) {
            temp = Q.front();

            //Check right adjacent cell that if it can be rotten
            if (isValid(temp.x + 1, temp.y, rows, cols) and arr[temp.x + 1][temp.y] == 1) {

                // if this is the first orange to get rotten, increase
                // count and set the flag.

                if (!flag) {
                    ans++;
                    flag = true;
                }

                // Make the orange rotten
                arr[temp.x + 1][temp.y] = 2;

                // push the adjacent orange to Queue
                temp.x++;
                Q.push(temp);

                temp.x--; // Move back to current cell
            }

            // Check left adjacent cell that if it can be rotten
            if (isValid(temp.x - 1, temp.y, rows, cols) && arr[temp.x - 1][temp.y] == 1) {
                if (!flag) ans++, flag = true;
                arr[temp.x - 1][temp.y] = 2;
                temp.x--;
                Q.push(temp); // push this cell to Queue
                temp.x++;
            }

            // Check top adjacent cell that if it can be rotten
            if (isValid(temp.x, temp.y + 1, rows, cols) && arr[temp.x][temp.y + 1] == 1) {
                if (!flag) ans++, flag = true;
                arr[temp.x][temp.y + 1] = 2;
                temp.y++;
                Q.push(temp); // Push this cell to Queue
                temp.y--;
            }

            // Check bottom adjacent cell if it can be rotten
            if (isValid(temp.x, temp.y - 1, rows, cols) && arr[temp.x][temp.y - 1] == 1) {
                if (!flag) ans++, flag = true;
                arr[temp.x][temp.y - 1] = 2;
                temp.y--;
                Q.push(temp); // push this cell to Queue
                temp.y++;
            }

            Q.pop();

        }

        // Pop the delimiter
        Q.pop();

        // If oranges were rotten in current frame than separate the
        // rotten oranges using delimiter for the next frame for processing.
        if (!Q.empty()) {
            temp.x = -1;
            temp.y = -1;
            Q.push(temp);
        }
    }

    return (checkall(arr)) ? -1 : ans;
}


int main() {
    vector<vector<int>> arr{{2, 1, 0, 2, 1},
                            {1, 0, 1, 2, 1},
                            {1, 0, 0, 2, 1}};

    int ans = rotOranges(arr);

    if (ans == -1)
        cout << "All oranges cannot rotten";
    else
        cout << "Time required for all oranges to rot => " << ans << endl;

    return 0;
}
// Time required for all oranges to rot => 2