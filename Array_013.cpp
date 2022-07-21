//
// Created by Akshansh Gusain on 03/07/21.
// Merge Without extra space

//The idea is to begin from last element of ar2[] and
// search it in ar1[]. If there is a greater element in ar1[],
// then we move last element of ar1[] to ar2[]. To keep ar1[]
// and ar2[] sorted, we need to place last element of ar2[]
// at correct place in ar1[]. We can use Insertion Sort type
// of insertion for this.
// Time: O(m*n)
#include<stdc++.h>
using namespace std;

void merge(int ar1[],int ar2[], int m, int n)
{
    // Iterate through all elements
    // of ar2[] starting from the last element
    for (int i = n - 1; i >= 0; i--)
    {
        /* Find the smallest element greater than ar2[i].
        Move all elements one position ahead till the
        smallest greater element is not found */
        int j, last = ar1[m - 1];
        for (j = m - 2; j >= 0
                        && ar1[j] > ar2[i]; j--)
            ar1[j + 1] = ar1[j];

        // If there was a greater element
        if (j != m - 2 || last > ar2[i])
        {
            ar1[j + 1] = ar2[i];
            ar2[i] = last;
        }
    }
}
// OPTIMISED APPROACH :


///Time Complexity: The time complexity while traversing the arrays in while loop is O(n+m)
/// in worst case and sorting is O(nlog(n) + mlog(m)).
/// So overall time complexity of the code becomes O((n+m)log(n+m)).

void merge2(int ar1[], int ar2[], int n, int m){
    int i=0, j=0, k = n-1;

    while(i <= k and j < m){
        if(ar1[i] < ar2[j]){
            i++;
        }else{
            swap(ar1[k], ar2[j]);
            j++, k--;
        }
    }
    sort(ar1, ar1+n);
    sort(ar2, ar2+m);
}


int main(){
    int arr1[] = {1, 5, 9, 10, 15, 20};
    int arr2[] = {2,3,8,13};
    int m = sizeof(arr1) / sizeof(arr1[0]);
    int n = sizeof(arr2) / sizeof(arr2[0]);
    merge2(arr1, arr2, m, n);

    cout << "After Merging nFirst Array: ";
    for (int i = 0; i < m; i++)
        cout << arr1[i] << " ";
    cout << "nSecond Array: ";
    for (int i = 0; i < n; i++)
        cout << arr2[i] << " ";

    return 0;
}

