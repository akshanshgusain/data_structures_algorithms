//
// Created by Akshansh Gusain on 30/03/21.
//
#include<stdc++.h>
using namespace std;

void permute(string a, int l, int r){
    //base case
    if(l==r){
        cout<< a<<endl;
        return;
    }

    for(int i = 1; i <= r; i++){

        swap(a[l],a[i]);

        permute(a, l+1,r);

        swap(a[1], a[i]); //backtrack to original string
    }

}

int main(){
    string str = "ABC";
    int n = str.size();
    permute(str, 0, n-1);
    return 0;
}
