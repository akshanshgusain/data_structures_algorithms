//
// Created by Akshansh Gusain on 23/02/21.
//
#include<stdc++.h>
using namespace std;

vector< pair<int,int> > findSubArray(int arr[], int n){

    unordered_map<int, vector<int>> map;

    vector< pair<int, int>> out; // store stating and ending indexes
    int sum = 0;

    for(int i=0; i< n; i++){
        sum += arr[i];


        if(sum == 0){
            out.push_back(make_pair(0,i));
        }

        if(map.find(sum) != map.end()){
            vector<int> vc = map[sum];
            for(auto &it: vc){
                out.push_back(make_pair(it+1,i));
            }
        }
        map[sum].push_back(i);
    }
    return out;
}

void print(vector<pair<int ,int>> out){
    for(auto & i : out){
        cout<<"Subarray found at Index: "<< i.first <<" to "<<i.second<<endl;
    }
}
int main(){
    int arr[]= {6,3,-1,-3,4,-2,2,4,6,-12,-7};
    int n = sizeof(arr)/sizeof(int);

    vector<pair<int,int>> out = findSubArray(arr,n);

    if(out.size() == 0){
        cout<<"No Subarray exists";
    }
    else{
        print(out);
    }
    return 0;
}
