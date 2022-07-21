//
// Created by Akshansh Gusain on 28/03/21.
//
#include<stdc++.h>
using namespace std;

bool isPalindrome(string str, int low, int high ){
    while (low < high)
    {
        if (str[low] != str[high])
            return false;
        low++;
        high--;
    }
    return true;
}

void allPalPartutil(vector<vector<string>> &allPart, vector<string> &currPart, int start, int n, string str){

    // If 'start' has reached len, BASE CASE
    if(start >= n){
        allPart.push_back((currPart));
    }

    // Pick all possible ending points for substrings
    for(int i=start; i<n; i++){

        //If substring str[start...i] is palindrome
        if(isPalindrome(str, start, i)){

            currPart.push_back(str.substr(start, i-start+1));

            //Recur for remaining substring
            allPalPartutil(allPart, currPart, i+1, n, str);

            //Remove substring str[start..i] from current partition
            currPart.pop_back();
        }
    }
}

void allPalPartitions(string str){
    int n = str.size();

    vector<vector<string>> allParts;
    vector<string> currPart;

    allPalPartutil(allParts, currPart,0,n,str);

    for(int i=0; i< allParts.size();i++){
        for(int j=0; j<allParts[i].size();j++){
            cout<< allParts[i][j]<< " ";
        }cout<<endl;
    }
}
int main(){
    string str = "nitin";
    allPalPartitions(str);
    return 0;
}
