//
// Created by Akshansh Gusain on 10/04/21.
//

#include<stdc++.h>
using namespace std;

int solve(int arr[], int n)
{
    // sort the array
    sort(arr, arr + n);

    // let two numbers be a and b
    int a = 0, b = 0;
    for (int i = 0; i < n; i++)
    {
        // fill a and b with every alternate digit
        // of input array
        if (i & 1)
            a = a*10 + arr[i];
        else
            b = b*10 + arr[i];
    }

    // return the sum
    return a + b;
}

int main(){
    int arr[] = {6, 8, 4, 5, 2, 3};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Sum is " << solve(arr, n);
    return 0;
}