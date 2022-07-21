//
// Created by Akshansh Gusain on 28/03/21.
//
#include<stdc++.h>
using namespace std;

int dictionaryContains(string &word){
    string dictionary[] = {"mobile","samsung","sam","sung",
                           "man","mango", "icecream","and",
                           "go","i","love","ice","cream"};
    int n = sizeof(dictionary)/ sizeof dictionary[0];
    for(int i=0; i<n; i++){
        if(dictionary[i].compare(word)==0){
            return true;
        }
    }
    return false;
}

void wordBreakUtil(string str, int n, string result){
        //process all prefixes one by one
        for(int i=1; i<=n ;i++){
            string prefix = str.substr(0,i);

            if(dictionaryContains(prefix)){

                //Base case: If there are no elements present
                if(i==n){
                    result += prefix;
                    cout<< result <<endl;
                    return;
                }
                wordBreakUtil(str.substr(i, n-1), n-i, result+prefix+" ");
            }
        }
}
void wordBreak(string str){
    wordBreakUtil(str, str.size(),"");
}

int main(){
    cout << "First Test:\n";
    wordBreak("iloveicecreamandmango");

    cout << "\nSecond Test:\n";
    wordBreak("ilovesamsungmobile");

    return 0;
}
