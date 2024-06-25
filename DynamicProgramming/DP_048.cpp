//
// Created by Akshansh Gusain on 28/12/21.
//

#include<stdc++.h>

using namespace std;

unordered_map<string, bool> mem;

bool solve(string a, string b) {
    if(a.length() == 1){
        return a == b;
    }
    if(a==b){
        return true;
    }

    string key = a+b;
    if(mem.find(key) != mem.end()){
        return mem[key];
    }

    bool flag = false;
    for (int i = 1; i < a.length(); i++) {
        if (    // No Swapping
                (solve(a.substr(0, i), b.substr(0, i)) and
                 solve(a.substr(i), b.substr(i)))

                or

                // Swapping
                (solve(a.substr(0, i), b.substr(a.length()-i)) and
                 solve(a.substr(i), b.substr(0, a.length()-i)))
                ) {
                flag = true;
                break;
        }
    }
    return mem[key] = flag;
}

bool isScramble(string a, string b) {
    int n = a.size();
    int m = b.size();
    if (n != m)
        return false;
    return solve(a, b);
}


int main() {
    string a = "great";
    string b = "eatgr";
    if (isScramble(a, b)) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    return 0;
}


