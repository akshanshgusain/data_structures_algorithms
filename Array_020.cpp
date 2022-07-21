//
// Created by Akshansh Gusain on 07/07/21.
//
#include<stdc++.h>
using namespace std;

void findCommon(int ar1[], int ar2[], int ar3[], int n1,
                int n2, int n3){
    int i=0, j =0, k =0;
    int prev1, prev2, prev3;
    prev1 = prev2 = prev3 = INT_MIN;

    while(i< n1 and j< n2 and k< n3){
        while(ar1[i] == prev1 and i<n1)
            i++;
        while (ar2[j] == prev2 && j < n2)
            j++;
        while (ar3[k] == prev3 && k < n3)
            k++;

        if(ar1[i] == ar2[j] and ar2[j] == ar3[k]){
            cout<<ar1[i]<<" ";
            prev1 = ar1[i];
            prev2 = ar2[j];
            prev3 = ar3[k];
            i++; j++;k++;
        }

        else if (ar1[i]<ar2[j]){
            prev1 = ar1[i];
            i++;
        }else if (ar2[j] < ar3[k]){
            prev2 = ar2[j];
            j++;
        }else{
            prev3 = ar3[k];
            k++;
        }
    }

}


// Using STL
//The idea is to use hash map. Here we maintain frequency of each
// element in array in three maps and then check if frequency of
// a particular element is greater than 0  in all three maps.
void findCommon2(int a[], int b[], int c[], int n1, int n2,
                int n3)
{
    // three maps to maintain frequency of elements
    unordered_map<int, int> m1;
    unordered_map<int, int> m2;
    unordered_map<int, int> m3;

    // creating frequency  maps
    for (int i = 0; i < n1; i++)
        m1[a[i]]++;
    for (int i = 0; i < n2; i++)
        m2[b[i]]++;
    for (int i = 0; i < n3; i++)
        m3[c[i]]++;

    // check if frequency of element greater than 0 in all
    // three maps
    for (int i = 0; i < n1; i++) {
        if (m1[a[i]] > 0 and m2[a[i]] > 0 and m3[a[i]] > 0)
            cout << a[i] << endl;
        // avoding same element being considered twice
        m1[a[i]] = 0;
    }
}

int main(){
    int ar1[] = { 1, 5, 10, 20, 40, 80, 80 };
    int ar2[] = { 6, 7, 20, 80, 80, 100 };
    int ar3[] = { 3, 4, 15, 20, 30, 70, 80, 80, 120 };
    int n1 = sizeof(ar1) / sizeof(ar1[0]);
    int n2 = sizeof(ar2) / sizeof(ar2[0]);
    int n3 = sizeof(ar3) / sizeof(ar3[0]);

    cout << "Common Elements are ";
    findCommon(ar1, ar2, ar3, n1, n2, n3);
    return 0;
}
