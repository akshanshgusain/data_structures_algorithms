//
// Created by Akshansh Gusain on 08/01/21.
//

#include<stdc++.h>
using namespace std;

void shuffleCheck(string str1, string str2,string result){

    if(str1.length() + str2.length() != result.length()){
        cout<<"False Length Does not match";
        return;
    }

    int i =0, j=0,k =0;

    while(k != result.length()){

        if(i<str1.length() && str1[i] == result[k]){
            i++;
        }
        else if(j<str2.length() && str2[j] == result[k]){
            j++;
        }
        else{
            cout<<"False";
            return;
        }

        k++;
    }

    if(i < str1.length() || j< str2.length()){
        cout<<"False char left";
        return;
    }

    cout<<"True";
}

int main(){
    string str1 = "XY";
    string str2 = "51";
    string result = "5XY1";
    shuffleCheck(str1, str2, result);

    return 0;
}