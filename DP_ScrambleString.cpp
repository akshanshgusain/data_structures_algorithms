//
// Created by Akshansh Gusain on 28/05/21.
//
#include<stdc++.h>

using namespace std;

unordered_map<string,bool> mem;
//keys : a + b

bool solve(string a, string b) {
    if (a.size() == 1) {
        return a == b;
    }
    if (a == b) {
        return true;
    }

    string key=a+b;
    if(mem.find(key)!=mem.end())
        return mem[key];

    int n = a.size();
    bool flag = false;

    for (int i = 1; i < n; i++) {

        if ((solve(a.substr(0, i), b.substr(0, i))
             && solve(a.substr(i), b.substr(i)))
            or
            (solve(a.substr(0, i), b.substr(n - i))
             && solve(a.substr(i), b.substr(0, n - i)))
                ) {
            flag = true;
            break;
        }
    }
    return mem[key] = flag;
}

bool isScramble(string a, string b){
    int n = a.size();
    int m = b.size();
    if(n != m)
        return false;
    return solve(a,b);
}

int main() {

    string a = "great";
    string b = "eatgr";
    if(isScramble(a,b)){
        cout<<"YES";
    }else{
        cout<<"NO";
    }
    return 0;
}
