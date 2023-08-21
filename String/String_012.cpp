//
// Created by Akshansh Gusain on 06/08/21.
//
// A Dynamic programming solution for Word Wrap Problem
#include <stdc++.h>
using namespace std;
#define INF INT_MAX

// A utility function to print the solution
int printSolution (int p[], int n);

// l[] represents lengths of different words in input sequence.
// For example, l[] = {3, 2, 2, 5} is for a sentence like
// "aaa bb cc ddddd". n is size of l[] and M is line width
// (maximum no. of characters that can fit in a line)
void solveWordWrap (int l[], int n, int M)
{
    // For simplicity, 1 extra space is used in all below arrays

    // extras[i][j] will have number of extra spaces if words from i
    // to j are put in a single line
    int extras[n+1][n+1];

    // lc[i][j] will have cost of a line which has words from
    // i to j
    int lc[n+1][n+1];

    // c[i] will have total cost of optimal arrangement of words
    // from 1 to i
    int c[n+1];

    // p[] is used to print the solution.
    int p[n+1];

    int i, j;

    // calculate extra spaces in a single line. The value extra[i][j]
    // indicates extra spaces if words from word number i to j are
    // placed in a single line
    for (i = 1; i <= n; i++)
    {
        extras[i][i] = M - l[i-1];
        for (j = i+1; j <= n; j++)
            extras[i][j] = extras[i][j-1] - l[j-1] - 1;
    }

    // Calculate line cost corresponding to the above calculated extra
    // spaces. The value lc[i][j] indicates cost of putting words from
    // word number i to j in a single line
    for (i = 1; i <= n; i++)
    {
        for (j = i; j <= n; j++)
        {
            if (extras[i][j] < 0)
                lc[i][j] = INF;
            else if (j == n && extras[i][j] >= 0)
                lc[i][j] = 0;
            else
                lc[i][j] = extras[i][j]*extras[i][j];
        }
    }

    // Calculate minimum cost and find minimum cost arrangement.
    // The value c[j] indicates optimized cost to arrange words
    // from word number 1 to j.
    c[0] = 0;
    for (i = 1; i <= n; i++)
    {
        c[i] = INF;
        for (j = 1; j <= i; j++)
        {
            if (c[j-1] != INF && lc[j][i] != INF &&
            (c[j-1] + lc[j][i] < c[i]))
            {
                c[i] = c[j-1] + lc[j][i];
                p[i] = j;
            }
        }
    }

    printSolution(p, n);
}

int printSolution (int p[], int n)
{
    int k;
    if (p[n] == 1)
        k = 1;
    else
        k = printSolution (p, p[n]-1) + 1;
    cout<<"Line number "<<k<<": From word no. "<<p[n]<<" to "<<n<<endl;
    return k;
}

// Driver program to test above functions
int main()
{
    int l[] = {3, 2, 2, 5};
    int n = sizeof(l)/sizeof(l[0]);
    int M = 6;
    solveWordWrap (l, n, M);

    //Line number 1: From word no. 1 to 1
    //Line number 2: From word no. 2 to 3
    //Line number 3: From word no. 4 to 4

    return 0;
}


