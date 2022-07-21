//
// Created by Akshansh Gusain on 02/04/21.
//

#include<stdc++.h>
using namespace std;

bool input[4][4] = {{0,0,1,0},
                    {0,0,1,0},
                    {0,0,0,0},
                    {0,0,1,0}};

bool knows(int a, int b){
    return input[a][b];
}


int findCelebrity(int n){
    stack<int> s;
    for(int i=0; i<n; i++){
        s.push(i);
    }

    int count = 0;
    while(count < n-1){
        int first = s.top();
        s.pop();
        int second = s.top();
        s.pop();

        if(knows(first, second)){
            s.push(second);
        }else{
            s.push(first);
        }
        count++;
    }

    int x = s.top();
    bool flag = true;

    for(int i=0; i<n;i++){
        if(i == x){
            continue;
        }
        if(input[x][i] == 1 || input[i][x] == 0){
            flag = false;
        }
    }
    if(!flag){
        return -1;
    }
    return x;

}
int main(){
    cout<<findCelebrity(4);
    return 0;
}