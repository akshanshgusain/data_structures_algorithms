//
// Created by Akshansh Gusain on 19/08/21.
//
#include<stdc++.h>

using namespace std;

bool isIsoMorphic(string s, string t) {
    int n = s.length();
    int m = t.length();
    if (n != m) {
        return false;
    }

    unordered_map<char, char> map1;
    unordered_map<char, bool> map2;

    for(int i = 0; i < s.length(); i++){
        char ch1 = s[i];
        char ch2 = t[i];

        if(map1.find(ch1) != map1.end()){
               if(map1[ch1] != ch2){
                   return false;
               }
        }else{
            if(map2.find(ch2) != map2.end()){
                return false;
            }else{
                map1[ch1] = ch2;
                map2[ch2] = true;
            }
        }
    }

    return true;
}

int main() {
    cout<<isIsoMorphic("aab", "xxy")<<endl;
    cout<<isIsoMorphic("aab", "xyz")<<endl;
    return 0;
}
