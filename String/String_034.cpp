//
// Created by Akshansh Gusain on 19/08/21.
//
#include<stdc++.h>
using namespace std;
#define CHAR 26

struct Key{
    int freq;
    char ch;

    bool operator< (const Key &k) const{
        return freq < k.freq;
    }
};

string reArrangeString(string s){
    int  n = s.length();

    int frequencies[CHAR] = {0};
    for(int i =0 ; i < n; i++){
        frequencies[s[i] -'a']++;
    }


    priority_queue<Key> heap;
    for(char ch = 'a'; ch <= 'z' ; ch++){
        if(frequencies[ch-'a']){
            heap.push(Key{frequencies[ch-'a'], ch});
        }
    }

    string st = "";
    Key previousEle = Key{-1, '#'};

    while(!heap.empty()){

        Key curr = heap.top();
        heap.pop();
        st += curr.ch;

        if(previousEle.freq>0){
            heap.push(previousEle);
        }

        curr.freq--;
        previousEle = curr;
    }

    if(n!=st.length()){
        return "Not a valid String";
    }

    return st;
}

int main() {
    string str = "bbbaa";
    cout<<reArrangeString(str);
    return 0;
}
