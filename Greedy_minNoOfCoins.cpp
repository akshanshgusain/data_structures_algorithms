//
// Created by Akshansh Gusain on 21/03/21.
//
#include<stdc++.h>
using namespace std;

int deno[] = { 1, 2, 5, 10, 20,
               50, 100, 500, 1000 };
int n = sizeof(deno) / sizeof(deno[0]);

void findMin(int V)
{
    sort(deno, deno + n);

    // Initialize result
    vector<int> ans;

    // Traverse through all denomination
    for (int i = n - 1; i >= 0; i--) {

        // Find denominations
        while (V >= deno[i]) {
            V -= deno[i];
            ans.push_back(deno[i]);
        }
    }

    // Print result
    for (int an : ans)
        cout << an << " ";
}


int main(){
    int n = 93;
    cout << "Following is minimal"
         << " number of change for " << n
         << ": ";
    findMin(n);
    return 0;
}
