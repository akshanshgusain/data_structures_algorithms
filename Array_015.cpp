//
// Created by Akshansh Gusain on 05/07/21.
//
#include<stdc++.h>
using namespace std;

struct Interval{
    int start, end;
};

bool compareInterval(Interval i1, Interval i2){
    return (i1.start < i2.start);
}

void mergeIntervals(Interval arr[], int n){
    if(n<=0) return;

    stack<Interval> s;

    sort(arr, arr+n, compareInterval);

    s.push(arr[0]);

    for(int i = 1; i<n ;i++){

        Interval top = s.top();

        if(top.end < arr[i].start){
            s.push(arr[i]);
        }
        else if(top.end < arr[i].end){
            top.end = arr[i].end;
            s.pop();
            s.push(top);
        }
    }
    // Print contents of stack
    cout << "\n The Merged Intervals are: ";
    while (!s.empty())
    {
        Interval t = s.top();
        cout << "[" << t.start << "," << t.end << "] ";
        s.pop();
    }
    return;
}

int main(){
    Interval arr[] =  { {6,8}, {1,9}, {2,4}, {4,7} };
    int n = sizeof(arr)/sizeof(arr[0]);
    mergeIntervals(arr, n);
    return 0;
}
