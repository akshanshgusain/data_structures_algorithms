//
// Created by Akshansh Gusain on 14/07/21.
//

#include<stdc++.h>
using namespace std;

//Time: O(NlogN), Space: O(1)

int main(){
    vector<int> arr = { 12, 4,  7,  9,  2,  23, 25, 41, 30,
                        40, 28, 42, 30, 44, 48, 43, 50 };
    int n = arr.size();
    int m = 7;

    sort(arr.begin(), arr.end());
    int min_diff = INT_MAX;

    for(int i=0; i + m - 1 < n; i++){
        int diff = arr[i+m-1] - arr[i];

        if(diff < min_diff){
            min_diff = diff;
        }
    }

    cout<<min_diff;
    return 0;
}