//
// Created by Akshansh Gusain on 13/09/22.
//
#include<bits/stdc++.h>

using namespace std;

class Key {
public:
    int freq; // store frequency of character
    char ch;

    Key(int freq, char ch){
        this->freq = freq;
        this->ch = ch;
    }

    // Function for priority_queue to store Key
    // according to freq
    bool operator<(const Key &k) const {
        return freq < k.freq;
    }
};

void rearrangeString(string str) {
    int n = str.length();

    // count frequency of all the
    vector<int> count(26, 0);
    for (int i = 0; i < n; i++) {
        count[str[i] - 'a']++;
    }

    // Insert all characters with their frequencies
    // into a priority_queue
    priority_queue<Key> pq;

    for (char c = 'a'; c <= 'z'; c++) {
        int val = c - 'a';
        if (count[val]) {
            pq.push(Key(count[val], c));
//            pq.push(Key{count[val], c});
        }
    }

    // 'str' that will store resultant value
    str = "";

    // work as the previous visited element
    // initial previous element be. ( '#' and
    // it's frequency '-1' )
    Key prev{-1, '#'};

    while (!pq.empty()) {
        Key top = pq.top();
        pq.pop();

        str = str + top.ch;

        // IF frequency of previous character is less
        // than zero that means it is useless, we
        // need not to push it
        if (prev.freq > 0)
            pq.push(prev);

        // Make current character as the previous 'char'
        // decrease frequency by 'one'
        (top.freq)--;
        prev = top;
    }


    // If length of the resultant string and original
    // string is not same then string is not valid
    if (n != str.length()){
        cout << " Not possible " << endl;
        return;
    }

    cout << str << endl;

}

int main() {
    string str = "bbbaa";
    rearrangeString(str);
    return 0;
}