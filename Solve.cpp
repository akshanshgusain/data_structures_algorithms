#include<bits/stdc++.h>
using namespace std;


struct Interval{
    int start;
    int end;
};

bool comparator(Interval a, Interval b){
    return a.start < b.start;
}

void mergeIntervalsOptimised(vector<Interval> &arr){
    int n = arr.size();
    if(n <= 0){
        return;
    }

    sort(arr.begin(), arr.end(), comparator);
    vector<Interval> mergedIntervals;
    mergedIntervals.push_back(arr[0]);

    for(int i= 0; i < n; i++){
        if(mergedIntervals.back().end >= arr[i].start){
            mergedIntervals.back().end = max(mergedIntervals.back().end, arr[i].end);
        }else{
            mergedIntervals.push_back(arr[i]);
        }
    }

    cout<<"merged Intervals: "<<endl;
    for(auto it : mergedIntervals){
        cout<<" {"<<it.start<<", "<<it.end<<" }   ";
    }
}


int main(){
    vector<Interval> arr = {
            Interval{1, 3},
            Interval{2, 4},
            Interval{6, 8},
            Interval{9, 10},
    };

    mergeIntervalsOptimised(arr);
    return 0;
}