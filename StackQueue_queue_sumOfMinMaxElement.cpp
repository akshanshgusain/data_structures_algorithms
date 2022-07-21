//
// Created by Akshansh Gusain on 06/04/21.
//
//The idea is to use Dequeue data structure and sliding window concept. We create two empty double ended queues of size
// k (‘S’ , ‘G’) that only store indexes of elements of current window that are not useless. An element is useless if
// it can not be maximum or minimum of next subarrays.

#include<stdc++.h>
using namespace std;

int SumOfKsubArray(int arr[], int n, int k){

    int sum = 0;
    deque<int> S(k), G(k);
    int i =0;
    for(i; i<k;i++){
        // Remove all previous greater elements
        // that are useless.
        while ( (!S.empty()) && arr[S.back()] >= arr[i])
            S.pop_back(); // Remove from rear

        // Remove all previous smaller that are elements
        // are useless.
        while ( (!G.empty()) && arr[G.back()] <= arr[i])
            G.pop_back(); // Remove from rear

        // Add current element at rear of both deque
        G.push_back(i);
        S.push_back(i);
    }

    for(;i <n ;i++){

        // Element at the front of the deque 'G' & 'S'
        // is the largest and smallest
        // element of previous window respectively
        sum += arr[S.front()] + arr[G.front()];

        //remove all elements which are out of this window
        while ( !S.empty() && S.front() <= i - k)
            S.pop_front();
        while ( !G.empty() && G.front() <= i - k)
            G.pop_front();

        // remove all previous greater element that are
        // useless
        while ( (!S.empty()) && arr[S.back()] >= arr[i])
            S.pop_back(); // Remove from rear

        // remove all previous smaller that are elements
        // are useless
        while ( (!G.empty()) && arr[G.back()] <= arr[i])
            G.pop_back(); // Remove from rear

        // Add current element at rear of both deque
        G.push_back(i);
        S.push_back(i);
    }

    sum += arr[S.front()] + arr[G.front()];

    return sum;
}

int main(){
    int arr[] = {2, 5, -1, 7, -3, -1, -2} ;
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 3;
    cout << SumOfKsubArray(arr, n, k) ;
    return 0;
}