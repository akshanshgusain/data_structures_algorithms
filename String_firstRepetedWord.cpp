//
// Created by Akshansh Gusain on 23/01/21.
//
#include<stdc++.h>
using namespace std;

string findFirstRepeated(string s){

    istringstream iss(s);
    string token;

    unordered_map<string, int> setOfWords;

    while(getline(iss, token, ' ')){
        if(setOfWords.find(token) != setOfWords.end()){
            setOfWords[token] += 1;
        }else{
            setOfWords.insert(make_pair(token, 1));
        }
    }

    istringstream iss2(s);
    while(getline(iss2, token, ' ')){
        int count = setOfWords[token];
        if(count>1){
            return token;
        }
    }
    return "NoRepetition";
}

int main(){
    string s("Ravi had been saying that he had been there");
    string firstWord = findFirstRepeated(s);

    if (firstWord != "NoRepetition")
        cout << "First repeated word :: "
             << firstWord << endl;
    else
        cout << "No Repetitionn";

    return 0;
}