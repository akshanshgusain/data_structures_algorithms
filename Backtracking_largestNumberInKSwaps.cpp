//
// Created by Akshansh Gusain on 30/03/21.
//

#include<stdc++.h>
using namespace std;

void findMaximumNum(string str, int k, string& max, int ctr){
    if(k==0){
        return;
    }

    int n = str.length();

    //consider digit at the cur position
    char maxm = str[ctr];

    for(int j = ctr +1; j< n ;j++){
        //find maximum digit greater than at maxm
        if(maxm < str[j]){
            maxm = str[j];
        }
    }

    //If maxm is not equal to str[ch],thats means we need to make a swap, decrement k
    if(maxm != str[ctr]) {
        --k;
    }

    //search this maximum among the rest
    for(int j = ctr; j< n; j++){
        //if digit equals maxm, swap the digit with current digit and recur for the rest
        if(str[j] == maxm){
            swap(str[ctr], str[j]);

            //if current num is greater than maximum so far
            if(str.compare(max) > 0){
                max = str;
            }

            //recur for other swaps after cur
            findMaximumNum(str, k,max,ctr+1);

            //backtrack - to original string(without current swap)
            swap(str[ctr], str[j]);
        }
    }
}


int main(){
    string str = "129814999";
    int k = 4;
    string max = str;
    findMaximumNum(str, k, max,0);

    cout<< max<<endl;
    return 0;
}
