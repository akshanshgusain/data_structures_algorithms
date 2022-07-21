//
// Created by Akshansh Gusain on 28/01/21.
//
#include<stdc++.h>
using namespace std;
const int MAX_CHARS = 256;

string findSubString(string str, string pat){
        int len1 = str.length();
        int len2 = pat.length();
        if(len1<len2){
            cout<<"No Such String";
            return "";
        }
        int hash_str[MAX_CHARS] = {0};
        int hash_pat[MAX_CHARS] = {0};

        //store occurrence of characters of pattern
        for(int i=0; i< len2; i++){
            hash_pat[pat[i]]++;
        }
        int start = 0, start_index = -1, min_len = INT_MAX;
        //start traversing the string
        //Count of characters
        int count = 0;
        for(int j=0; j< len1; j++){
            //count occurrence of characters of String
            hash_str[str[j]]++;

            //if string's char matches with the pattern's char then increment the count
            if(hash_str[str[j]] <= hash_pat[str[j]]){
                count++;
            }

            //if all chars are matched
            if(count == len2){

                //Try to minimize the window
                while(hash_str[str[start]] > hash_pat[str[start]] || hash_pat[str[start]] == 0){
                    if(hash_str[str[start]] > hash_pat[str[start]]){
                        hash_str[str[start]]--;
                        start++;
                    }
                }
                // update window size
                int len_window = j - start + 1;
                if (min_len > len_window) {
                    min_len = len_window;
                    start_index = start;
                }
            }
        }

    // If no window found
    if (start_index == -1) {
        cout << "No such window exists";
        return "-1";
    }

    // Return substring starting from start_index
    // and length min_len
    return str.substr(start_index, min_len);
}

int main(){
    string str = "this is a test string";
    string pat = "tist";
    cout<<"Smallest window containing all distinct chars is: "<<findSubString(str, pat);
    ///  t stri
    return 0;
}