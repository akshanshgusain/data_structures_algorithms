//
// Created by Akshansh Gusain on 29/01/21.
//
#include<stdc++.h>
using namespace  std;
const int MAX_CHAR = 26;

struct Key{
    int freq;
    char ch;

    // function for priority_queue to store Key
    // according to freq
    bool operator<(const Key &k) const{
        return freq < k.freq;
    }
};

void rearrangeString(string str){

    int n = str.length();

    //store freq of all chars in string
    int count[MAX_CHAR] = {0};
    for(int i=0; i<n ;i++){
        count[str[i]-'a']++;
    }

    //Insert all chars with their frequencies in the priority queue
    priority_queue<Key> pq;
    for(char ch = 'a'; ch< 'z'; ch++){
        if(count[ch-'a']){
            pq.push(Key{count[ch-'a'], ch});
        }
    }
    str ="";
    //previous element: frequency as-1 and '#' as char
    Key prev {-1, '#'};

    //traverse the queue
    while(!pq.empty()){

        //pop the top element of the queue and add it to string.
        Key k = pq.top();
        pq.pop();
        str = str+k.ch;

        // If frequency of previous char is less than zero then we need not push it back into the queue
        if(prev.freq>0){
            pq.push(prev);
        }

        //make the current char as the previous char, decrease frequency by 'one'
        k.freq--;
        prev = k;
    }
    if(n!=str.length()){
        cout<<"Not valid string"<<endl;
    }
    else{
        cout<<str<<endl;
    }

}

int main(){
    string str = "bbbaa";
    rearrangeString(str);
    return 0;
}

