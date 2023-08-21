//
// Created by Akshansh Gusain on 04/08/21.
//


#include <stdc++.h>

using namespace std;



void findNextSmallest(string &ip){
    int len = ip.size();
    int i;
    // Find the first smaller digit from the right
    for(i = len-1; i > 0; i--){
        if(ip[i] > ip[i-1]){
            break;
        }
    }

    cout<<ip[i]<<endl;

    if(i == 0){
       ip = "No solution possible";
       return;
    }


    //find the smallest digit grater than ip[i]

    int smallestDigitIndex = i;

    for(int j = i+1;  j < len; j++){
        if(ip[j] > ip[i-1] and ip[smallestDigitIndex] > ip[j]){
            smallestDigitIndex = j;
        }
    }

    swap(ip[i-1], ip[smallestDigitIndex]);

    reverse(ip.begin() + i, ip.end());


}

int main() {
    string str = "536976";
    findNextSmallest(str);
    cout <<str;
    return 0;
}