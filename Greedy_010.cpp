//
// Created by Akshansh Gusain on 23/08/22.
// Time : O(N^2)


#include<bits/stdc++.h>

using namespace std;

// A utility function that returns index of minimum value in arr[]
int getMin(vector<int> &netAmount) {
    int minInd = 0;
    for (int i = 1; i < netAmount.size(); i++)
        if (netAmount[i] < netAmount[minInd])
            minInd = i;
    return minInd;
}

// A utility function that returns index of maximum value in arr[]
int getMax(vector<int> &netAmount) {
    int maxInd = 0;
    for (int i = 1; i < netAmount.size(); i++)
        if (netAmount[i] > netAmount[maxInd])
            maxInd = i;
    return maxInd;
}

void helper(vector<int> &netAmount) {
    //Find the indexes of min and max values in netAmount
    int maxCredit = getMax(netAmount);
    int maxDebit = getMin(netAmount);

    // Base case
    // If both amounts are 0, then all amounts are settled.
    if (netAmount[maxCredit] == 0 and netAmount[maxDebit] == 0) {
        return;
    }

    // Find the mini of two amounts and neutralize
    int mini = min(-netAmount[maxDebit], netAmount[maxCredit]);
    netAmount[maxDebit] += mini;
    netAmount[maxCredit] -= mini;

    // If minimum is the maximum amount to be
    cout << "Person " << maxDebit << " pays " << mini << " to " << "Person " << maxCredit << endl;


    helper(netAmount);
}

void minCashFlow(vector<vector<int>> &graph) {
    int E = graph.size();

    vector<int> netAmount(E, 0);

    // Calculated by subtracting debits of ith from credits of ith
    for (int i = 0; i < E; i++) {
        for (int j = 0; j < E; j++) {
            netAmount[i] += graph[j][i] - graph[i][j];
        }
    }

    helper(netAmount);
}

int main() {
    vector<vector<int>> graph = {{0, 1000, 2000},
                                 {0, 0,    5000},
                                 {0, 0,    0},};

    minCashFlow(graph);
    return 0;
}