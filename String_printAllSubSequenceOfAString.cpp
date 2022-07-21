//
// Created by Akshansh Gusain on 13/01/21.
//
#include<stdc++.h>
using namespace std;

unordered_set<string> st;

void subSequence(string str){

    for(int i= 0; i<str.length(); i++){

        for(int j=str.length(); j>i; j--){
             string sub_string = str.substr(i, j);
             st.insert(sub_string);

             //Drop kth char in the sub String
             //and if its not in the set then recur
             for(int k=1; k<sub_string.length(); k++){
                 string sb = sub_string;
                 sb.erase(sb.begin()+ k);
                 subSequence(sb);
             }
        }
    }
}

int main(){
    string s = "aabc";
    subSequence(s);
    for(auto i: st){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}