//
// Created by Akshansh Gusain on 10/08/21.
//
#include<stdc++.h>

using namespace std;
#define int long long
#define prime 119
#define CHAR 265

//// (prime^i) * str[i]
//// e.g.: for a string: ("abc"): (a * prime^0) + (b * prime^1) +(c * prime^2)
//// Time: O(nm): When the hash value of the pattern matches with the hash value of a window of the
/// text but the window is not the actual pattern then it is called a spurious hit.
/// , average: (m+n)

//ll createHashValue(string str, int n) {
//    ll result = 0;
//    for (int i = 0; i < n; i++) {
//        result += (ll) (str[i] * (ll)pow(prime, i));
//    }
//    return result;
//}
//
//ll reCalculateHashValue(string str, int oldIndex, int newIndex, ll oldHash, int patternLength) {
//    ll newHash = oldHash - str[oldIndex];
//    newHash /= prime;
//    newHash += (ll)(str[newIndex] * (ll)pow(prime, patternLength - 1));
//    return newHash;
//}
//
//bool checkEqual(string str1, string str2, int start1, int end1, int start2, int end2) {
//    if (end1 - start1 != end2 - start2) {
//        return false;
//    }
//    while (start1 <= end1 and start2 <= end2) {
//        if (str1[start1] != str2[start2]) {
//            return false;
//        }
//        start1++;
//        start2++;
//    }
//    return true;
//}
//
//int main() {
//    string str = "ababcabdab2390hfinsdmf983iogndlkg,dsbkjvk";
//    string pat = "90hfinsd"; // Max: 8 digits
//    ll patHash = createHashValue(pat, pat.length());
//    ll strHash = createHashValue(str, pat.length());
//    for (int i = 0; i <= str.length() - pat.length(); i++) {
//        if (patHash == strHash and checkEqual(str, pat, i, i + pat.length() - 1, 0, pat.length() - 1)) {
//            cout << i << endl;
//            return 0;
//        }
//        if (i < str.length() - pat.length()) {
//            strHash = reCalculateHashValue(str, i, i + pat.length(), strHash, pat.length());
//        }
//    }
//    return 0;
//}

void searchRK(string pattern, string text){

    int M = pattern.length();
    int N = text.length();
    int pHash = 0;
    int tHash = 0;
    int i, j, h = 1;

    for(i = 0; i < M - 1 ; i++){
        h = (h * CHAR) % prime;
    }

    // Calculate Hashes for the first window
    for(i = 0; i < M; i++){
        pHash = (CHAR * pHash + pattern[i]) % prime;
        tHash = (CHAR * tHash + text[i]) % prime;
    }

    for(i = 0 ; i <= N-M; i++){
        if(pHash == tHash){
            for(j = 0; j< M; j++){
                if(pattern[j] != text[i+j]){
                    break;
                }
            }

            if(j == M){
                cout<<"Pattern Found, stating at: "<<i<<endl;
            }
        }

        // Re-Calculate the hash for next window (Roll the hash)
        if(i < N-M){
            tHash = (CHAR * (tHash - text[i]*h) + text[i+M]) % prime;
            if(tHash<0){
                tHash = (tHash + prime);
            }
        }
    }
}

int32_t main(){
    char text [] = "abcdfertyoig34jt9034ionfdwoig3hjt390wo";
    char pattern[] = "34jt9034ionfdwoig";

    searchRK(pattern, text);

    return 0;
}