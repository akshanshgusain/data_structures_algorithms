//
// Created by Akshansh Gusain on 02/08/21.
//

#include<stdc++.h>
using namespace std;

int main(){
    string str;
    cin>> str;
    int li = 0;
    int ri  = str.length() - 1;

    while(li < ri){
        if (str[li] != str[ri]){
            cout<<"NO";
            return 0;
        }
        li++;
        ri--;
    }
    cout<<"YES";
    return 0;
}