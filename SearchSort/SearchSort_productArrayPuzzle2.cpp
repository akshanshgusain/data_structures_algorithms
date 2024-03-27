//
// Created by Akshansh Gusain on 23/02/21.
//
#include<stdc++.h>
using namespace std;

/* Function to print product array
for a given array arr[] of size n */
void productArray(int arr[], int n)
{

    // Base case
    if (n == 1) {
        cout << 0;
        return;
    }

    int i, temp = 1;

    /* Allocate memory for the product array */
    int* prod = new int[(sizeof(int) * n)];

    /* Initialize the product array as 1 */
    memset(prod, 1, n);

    /* In this loop, temp variable contains product of
       elements on left side excluding arr[i] */
    for (i = 0; i < n; i++) {
        prod[i] = temp;
        temp *= arr[i];
    }

    /* Initialize temp to 1
    for product on right side */
    temp = 1;

    /* In this loop, temp variable contains product of
       elements on right side excluding arr[i] */
    for (i = n - 1; i >= 0; i--) {
        prod[i] *= temp;
        temp *= arr[i];
    }

    /* print the constructed prod array */
    for (i = 0; i < n; i++)
        cout << prod[i] << " ";

    return;
}

int main(){

    int arr[] = { 10, 3, 5, 6, 2 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "The product array is: \n";
    productArray(arr, n);

    return 0;
}
