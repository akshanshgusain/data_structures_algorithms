//
// Created by Akshansh Gusain on 21/03/21.
//
#include<stdc++.h>
using namespace std;

// number of houses and number
// of pipes
int numOfHouses, numOfPipes;

// Array endingVOfPipes stores the
// ending vertex of pipe
int endingVOfPipes[1100];

// Array wd stores the value
// of diameters between two pipes
int diameter[1100];

// Array startingVOfPipes stores the
// starting end of pipe
int startingVOfPipes[1100];

// Vector tanks, taps, diameters are used
// to store the final output
vector<int> tanks; //tanks
vector<int> taps; //taps
vector<int> diameters;//diameter

int ans;

int dfs(int j){
    if (startingVOfPipes[j] == 0)
        return j;
    if (diameter[j] < ans)
        ans = diameter[j];
    return dfs(startingVOfPipes[j]);
}

void solve(int arr[][3]){
    int i =0;

    while(i < numOfPipes){
        int start = arr[i][0];
        int end = arr[i][1];
        int dia = arr[i][2];

        startingVOfPipes[start] = end;
        diameter[start] = dia;
        endingVOfPipes[end] = start;
        i++;
    }

    tanks.clear();
    taps.clear();
    diameters.clear();

    for (int j = 1; j <= numOfHouses; ++j)

        /*If tanks pipe has no ending vertex
        but has starting vertex i.e is
        an outgoing pipe then we need
        to start DFS with this vertex.*/
        if (endingVOfPipes[j] == 0 && startingVOfPipes[j]) {
            ans = 1000000000;
            int w = dfs(j);

            // We put the details of component
            // in final output array
            tanks.push_back(j);
            taps.push_back(w);
            diameters.push_back(ans);
        }

    cout << tanks.size() << endl;
    for (int j = 0; j < tanks.size(); ++j)
        cout << tanks[j] << " " << taps[j] << " " << diameters[j] << endl;
}

int main(){
    numOfHouses = 9, numOfPipes = 6;

    memset(endingVOfPipes, 0, sizeof(endingVOfPipes));
    memset(startingVOfPipes, 0, sizeof(startingVOfPipes));
    memset(diameter, 0, sizeof(diameter));

    int arr[][3] = { { 7, 4, 98 },
                     { 5, 9, 72 },
                     { 4, 6, 10 },
                     { 2, 8, 22 },
                     { 9, 7, 17 },
                     { 3, 1, 66 } };

    solve(arr);
}
