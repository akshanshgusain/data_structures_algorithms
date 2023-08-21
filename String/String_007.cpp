//
// Created by Akshansh Gusain on 08/01/21.
//

#include<stdc++.h>
using namespace std;

unordered_map<int, string> mapping;



void countAndSay(string entry){
    int i =0, j=0;
    string result;
    while(i < entry.length()){
        for(j=i; j<entry.length(); j++){ // j Counts consecutive duplicates
            if(entry[i] == entry[j+1]){
                j++;
            }else{
                break;
            }
        }
        int count =0;
        if(i==j){
            count = 1;

            result += to_string(count)+entry[i];
           // cout<< mapping[count] << " "<<entry[i]<<"'s"<<endl;
        }
        else{
            count = j-i;
            result += to_string(count)+entry[i];
           // cout<< mapping[count] << " "<<entry[i]<<"'s"<<endl;
        }

        i = i+count;
    }

    cout<<"Result:"<<endl<<result;
}


int main(){
    //string entry = "3322225110";
    string entry = "1211";
    countAndSay(entry);
    return 0;
}
