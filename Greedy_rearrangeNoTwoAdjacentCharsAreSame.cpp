//
// Created by Akshansh Gusain on 27/03/21.
//
//Using priorityQueue or Binary MaxHeap(highest frequency element as root)
// We one by one take the highest frequency character from the heap and add it to result.
// After we add, we decrease the frequency of the character and we temporarily move this
// character out of priority queue so that it is not picked next time.

#include<stdc++.h>

using namespace std;

const int MAX_CHAR = 26;

struct Key {
    int freq;
    char ch;

    bool operator<(const Key &k) const {
        return freq < k.freq;
    }
};

void rearrangeString(string str){
    int n = str.length();

    // Store frequencies of all characters in string
    int count[MAX_CHAR] = {0};
    for (int i = 0 ; i < n ; i++)
        count[str[i]-'a']++;

    // Insert all characters with their frequencies
    // into a priority_queue
    priority_queue< Key > pq;
    for (char c = 'a' ; c <= 'z' ; c++){
        if (count[c-'a'])
            pq.push( Key { count[c-'a'], c} );
    }

    // 'str' that will store resultant value
    str = "" ;

    // work as the previous visited element
    // initial previous element be. ( '#' and
    // it's frequency '-1' )
    Key prev {-1, '#'} ;

    while(!pq.empty()){
        //pop top element from the queue and add it to the string
        Key k = pq.top();
        pq.pop();
        str = str+k.ch;

        if(prev.freq>0){
            pq.push(prev);
        }
        (k.freq)--;
        prev = k;
    }

    if(n != str.length()){
        cout<<" Not valid String "<<endl;
    }else{
        cout<< str<<endl;
    };


}

int main() {
    string str = "bbbaa" ;
    rearrangeString(str);
    return 0;
}
