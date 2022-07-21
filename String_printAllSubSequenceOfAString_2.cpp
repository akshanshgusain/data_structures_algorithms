//
// Created by Akshansh Gusain on 13/01/21.
//

/*One by one fix characters and recursively generates all subsets starting from them.
 * After every recursive call, we remove last character so that the next permutation can
 * be generated. */

#include<stdc++.h>
using namespace std;

void printSubSequenceRec(string str, int n, int index = -1, string curr = ""){
    //str = input string
    //n = size of the input string
    //index = index of current permutation
    //curr = stores current permutation

    //base case
    if (index == n){
        return;
    }
    if(!curr.empty()){
        cout<< curr <<"\n";
    }

    for(int i = index+1; i<n ;i++) {
        curr += str[i];
        printSubSequenceRec(str, n, i, curr);

        //backtracking
        curr = curr.erase(curr.size() - 1);
    }
}

int main(){
    string s = "cab";
    printSubSequenceRec(s, s.size());
    return 0;
}