//
// Created by Akshansh Gusain on 23/03/21.
//

#include<stdc++.h>
using namespace std;

/*
    N – Maximum unit of food you can buy each day.
    S – Number of days you are required to survive.
    M – Unit of food required each day to survive.
 */

void survival(int s, int n, int m){
        //if we cant buy at least a week of supply of food during the first week OR we can not buy a day supply of food
        //on the first day then we cant survive.

        if((n*6) < (m*7) && s>6 || m>n)
            cout<<"No"<<endl;
        else{
            int days = (m*s) / n;
            if( (m*s)% n != 0){
                days++;
            }
            cout<<"Yes "<<days<<endl;
        }
}

int main(){
    int s= 10, n =16, m=2;
    survival(s,n,m);
    return 0;
}