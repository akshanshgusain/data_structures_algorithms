//
// Created by Akshansh Gusain on 25/03/21.
//
//Maximum sum of absolute difference of any permutation
/*Input : { 1, 2, 4, 8 }
Output : 18
Explanation : For the given array there are
several sequence possible
like : {2, 1, 4, 8}
       {4, 2, 1, 8} and some more.
Now, the absolute difference of an array sequence will be
like for this array sequence {1, 2, 4, 8}, the absolute
difference sum is
= |1-2| + |2-4| + |4-8| + |8-1|
= 14
For the given array, we get the maximum value for
the sequence {1, 8, 2, 4}
= |1-8| + |8-2| + |2-4| + |4-1|
= 18*/

//To get the maximum sum, we should have a sequence in which small and large elements comes alternate.
// This is done to get maximum difference.
#include<stdc++.h>
using namespace std;

int MaxSumDifference(int a[], int n){
    vector<int> finalSequence;
    sort(a,a+n);

    for(int i =0 ;i<n/2 ;i++){
        finalSequence.push_back(a[i]);
        finalSequence.push_back(a[n-i-1]);
    }
    if(n%2 != 0){
        finalSequence.push_back(a[n/2]);
    }
    int max =0;
    for(int i =0; i< n-1; i++){
        max = max + (abs(finalSequence[i] - finalSequence[i+1]));
    }
    // absolute difference of last element
    // and 1st element

    max = max + abs(finalSequence[n-1] - finalSequence[0]);

    return max;
}

int main(){
    int a[] = {1,2,3,4,8};
    int n = sizeof(a)/sizeof(a[0]);
    cout<< MaxSumDifference(a,n)<<endl;
    return 0;
}