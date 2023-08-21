//
// Created by Akshansh Gusain on 13/08/21.
//

#include<stdc++.h>

using namespace std;

int longestCommonPrefix(vector<string> names){
    int n = names.size();

    string popo = names[0];


    for(int i = 1 ; i < n; i ++){
        int j = 0;

        //compare the chars in the string to get the common prefix
        while( popo[j] == str[i][j] && j < s.length() && j < str[i].length()){
            j++;
        }

        //Update the prefix
        popo = popo.substr(0, j);
    }

    return j;
}

int main() {
    vector<string> names = {"flower", "flow", "flight"};
    cout << longestCommonPrefix(names) << endl;
    return 0;
}
