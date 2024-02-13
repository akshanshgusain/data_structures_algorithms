#include<stdc++.h>

using namespace std;

int firstUniqChar(string s) {
    vector<int> count(26, 0);
    for(auto it:s){
        count[it-'a']++;
    }
    for(int i=0; i < s.size(); i++){
        if(count[s[i]-'a']==1){
            return i;
        }
    }
    return -1;
}

void findListOrder(vector<string> &ip){
    if(ip.size() == 0){
        return 0; // little coffe ho jaye ???
        // New ONLcikListner
        // new new OnlickListnrwet berw
    }
}

// Driver Code
int main() {
   string a = "loveleetcode";

    cout<< firstUniqChar(a);

    return 0;
}

