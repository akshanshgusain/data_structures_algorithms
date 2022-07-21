//
// Created by Akshansh Gusain on 05/06/21.
// only works for cases where n in small like n=15 or n=18;
#include<stdc++.h>
using namespace std;

vector<vector<int>> getSubset(vector<int> num){
    int size = num.size();
    int subsetNum = (1<<size);

    vector<vector<int>> powerset;
    for(int subsetMask = 0; subsetMask < subsetNum; subsetMask++){
        vector<int> subset;
        for(int i=0; i< size; i++){
            if((subsetMask & (1<<i)) != 0){
                subset.push_back(num[i]);
            }
        }
        powerset.push_back(subset);
    }
    return powerset;
}
int main(){
    vector<int> nums = {1,2,3};
    vector<vector<int>> powerset = getSubset(nums);
    for(int i=0; i< powerset.size();i++){
        for(int j=0; j< powerset[i].size(); j++){
            cout<<powerset[i][j]<<", ";
        }
        cout<<endl;
    }
    return 0;
}