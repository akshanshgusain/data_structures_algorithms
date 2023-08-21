//
// Created by Akshansh Gusain on 14/07/21.
//
#include<stdc++.h>
using namespace std;

// Only positive elements
// Time: O(N), Space: O(1)
int smallestSubWithSum(int arr[], int n, int x){

    int mi = INT_MAX;
    int i = 0, j = 0;
    int s = 0;

    while( i <= j and j < n){

        while(s <= x and j <n){
            s += arr[j++];
        }

        while(s > x and i < j){
            mi = min(mi, j-i);
            s -= arr[i];
            i++;
        }

    }
    return mi;
}



int main(){
    int arr1[] = { 1, 4, 45, 6, 10, 19 };
    int x = 51;
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int res1 = smallestSubWithSum(arr1, n1, x);
    (res1 == n1 + 1) ? cout << "Not possible\n"
                     : cout << res1 << endl;

    int arr2[] = { 1, 10, 5, 2, 7 };
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    x = 9;
    int res2 = smallestSubWithSum(arr2, n2, x);
    (res2 == n2 + 1) ? cout << "Not possible\n"
                     : cout << res2 << endl;

    int arr3[] = { 1, 11, 100, 1, 0, 200, 3, 2, 1, 250 };
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    x = 280;
    int res3 = smallestSubWithSum(arr3, n3, x);
    (res3 == n3 + 1) ? cout << "Not possible\n"
                     : cout << res3 << endl;
    return 0;
}
