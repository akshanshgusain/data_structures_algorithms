//
// Created by Akshansh Gusain on 23/08/22.
//

#include<bits/stdc++.h>
using namespace std;

class Train{
public:
    int arrivalTime;
    int departureTime;

    Train(int arrivalTime, int departureTime) : arrivalTime(arrivalTime), departureTime(departureTime) {}

};

bool comparator(Train &a, Train &b){
    return a.departureTime < b.departureTime;
}

int findMax(vector<Train> &input){
    sort(input.begin(), input.end(), comparator);
    int cnt = 0;
    int maxi = INT_MIN;
    int lastExistTime = input[0].departureTime;
    for(int i= 1; i < input.size();i++){
        if(input[i].arrivalTime < lastExistTime){
            cnt++;
        }else{
            cnt = 1;
        }
        maxi = max(maxi, cnt);
        lastExistTime = input[i].departureTime;
    }
    return maxi;
}

int main(){
    int n = 6;
    vector<int> arr= {900, 940, 950, 1100, 1500, 1800};
    vector<int> dep= {910, 1200, 1120, 1130, 1900, 2000};
//    vector<int> arr= {900, 1100, 1235};
//    vector<int> dep= {1000, 1200, 1240};
    vector<Train> input;

    for(int i = 0 ; i < n; i++){
        input.emplace_back(arr[i], dep[i]);

    }
    cout<<findMax(input);
    return 0;
}