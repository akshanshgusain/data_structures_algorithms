//
// Created by Akshansh Gusain on 01/07/21.
//
#include<stdc++.h>

using namespace std;

// For Sorted Arrays
// 1. union, time: O(m+n)
void sortedUnion(int a1[], int a2[], int n, int m) {
    int i = 0, j = 0;
    while (i < n and j < m) {
        if (a1[i] < a2[j]) {
            cout << a1[i++] << " ";
        } else if (a1[i] > a2[j]) {
            cout << a2[j++] << " ";
        } else {
            cout << a2[j++] << " ";
            i++;
        }
    }

    //print remaining elements
    while (i < n) {
        cout << a1[i++] << " ";
    }
    while (j < m) {
        cout << a2[j++] << " ";
    }
}

// 2. Intersection
void sortedIntersection(int a1[], int a2[], int n, int m) {
    int i = 0, j = 0;
    while (i < m && j < n) {
        if (a1[i] < a2[j])
            i++;
        else if (a2[j] < a1[i])
            j++;
        else /* if arr1[i] == arr2[j] */
        {
            cout << a2[j] << " ";
            i++;
            j++;
        }
    }
}

//For unSorted Arrays
// 1. Union
//Method 1: Use STL Set, time :O(mlog(m) + nlog(n))
//Method 2: Use STL Map, time :O(m+n)
// Method 3: Sort the arrays and and apply union for sorted array,
// time:O(mlog(m) + nlog(n)).

//2. Intersection
// Method 1: User STL Map.(If the elements in each array are unique)
// Method 2: User HashSet, time: O(m+n)
void unsortedIntersection(int a1[], int a2[], int m, int n) {
    set<int> hs;
    for (int i = 0; i < m; i++)
        hs.insert(a1[i]);

    for (int i = 0; i < n; i++)
        if (hs.find(a2[i]) != hs.end())
            cout << a2[i] << " ";
}

void unsortedUnion(int a1[], int a2[], int m, int n) {
    set<int> hs;
    for (int i = 0; i < m; i++) {
        hs.insert(a1[i]);
    }
    for (int i = 0; i < n; i++) {
        hs.insert(a2[i]);
    }
    for (auto it = hs.begin(); it != hs.end(); it++)
        cout << *it << " ";
    cout << endl;
}


int main() {
    int arr1[] = {1, 2, 4, 5, 6};
    int arr2[] = {2, 3, 5, 7};

    int m = sizeof(arr1) / sizeof(arr1[0]);
    int n = sizeof(arr2) / sizeof(arr2[0]);

    // Function calling
    //sortedUnion(arr1, arr2, m, n);
    sortedIntersection(arr1, arr2, m, n);
    return 0;
}
