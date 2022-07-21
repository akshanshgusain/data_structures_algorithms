//
// Created by Akshansh Gusain on 28/01/21.
//
#include<stdc++.h>
using namespace std;
const int MAX_CHARS = 256;

string findSubString(string str){
    int n = str.length();

    //count all distinct chars
    int dist_count = 0;
    unordered_map<int, int> hash_map;
    for(int i=0; i<n ; i++){
        hash_map[str[i]]++;
    }
    dist_count = hash_map.size();

    int size = INT16_MAX;
    string result;

    for(int i=0; i< n; i++){
        int count = 0;
        int visited[256] = {0};
        string sub_str;
        for(int j=i; j<n;j++){
            if(visited[str[j]] == 0){
                count++;
                visited[str[j]] = 1;
            }
            sub_str += str[j];

        }
        if (sub_str.length() < size && count == dist_count){
            result = sub_str;
        }
    }
    return result;
}

int main(){
    string str = "aabcbcdbca";
    cout<<"Smallest window containing all distinct chars is: "<<findSubString(str);
    return 0;
}