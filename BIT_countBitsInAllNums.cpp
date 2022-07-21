//
// Created by Akshansh Gusain on 05/06/21.
//

#include<stdc++.h>
using namespace std;

int main(){
    int n =8; //13 bits total
    vector<int> mem(n+1);
    mem[0] = 0;

    int count = 0;
    for(int i =1; i<= n; i++){
        mem[i] = mem[i/2] + i%2;
        count += mem[i];
    }
    for(auto it: mem){
        cout<<it<<endl;
    }
    cout<<count;
    return 0;
}