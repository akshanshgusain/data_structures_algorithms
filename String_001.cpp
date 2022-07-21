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

    while(li <= ri){
        char temp = str[li];
        str[li] = str[ri];
        str[ri] = temp;
        li++;
        ri--;
    }

    cout<<endl<<str;
    return 0;
}