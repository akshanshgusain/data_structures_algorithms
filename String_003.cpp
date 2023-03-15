//
// Created by Akshansh Gusain on 06/03/23.
//

#include<bits/stdc++.h>
using namespace std;

void countDuplicates(string ip){
    unordered_map<char, int> map;
    for (auto it : ip){
        map[tolower(it)]++;
    }

    for(auto it: map){
        if(it.second > 1){
            cout<<it.first <<" - "<<it.second<<endl;
        }
    }
}

int main(){
    string ip = "Akshansh Gusain";
    countDuplicates(ip);
    return 0;
}