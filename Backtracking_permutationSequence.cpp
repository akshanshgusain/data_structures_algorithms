//
// Created by Akshansh Gusain on 30/03/21.
// Leetcode - https://leetcode.com/problems/permutation-sequence/
//https://www.youtube.com/watch?v=W9SIlE2jhBQ
//https://www.youtube.com/watch?v=W9SIlE2jhBQ&t=804s

//  Kth Permutation sequence of First N Natural numbers

#include<stdc++.h>
using namespace std;

vector<int> fact, digits;

void solve(string& ans, int n, int k){

    if(n==1){   //Insert whatever digit is left at the end
        ans+=to_string(digits.back());
        return;
    }
    // This runs of we have more than 1 digit in digits array
    int index = k/fact[n-1]; //Define no. blocks to skip (each block of size fact[n-1])
    if(k%fact[n-1] == 0){
        index -= 1;
    }

    ans+=to_string(digits[index]); //Add new character
    digits.erase(digits.begin()+index);

    k -= fact[n-1]*index;
    solve(ans, n-1, k);

}

string getPermutation(int n, int k){
    //Store all factorials from 0 t N
    fact.push_back(1);
    int f = 1;
    for(int i=1; i<n;i++){
        f*=i;
        fact.push_back(f);
    }
    //push you digits in array
    for(int i=1; i<=n; i++){
        digits.push_back(i);
    }
    string ans = "";
    solve(ans, n, k);
    return ans;
}
int main(){
    cout<< "Kth : "<<getPermutation(3, 5);
    return 0;
}
