#include<stdc++.h>

using namespace std;

bool halvesAreAlike(string s) {
//    transform(s.begin(), s.end(), s.begin(), ::tolower);
    unordered_set<char> seti = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    int n = s.size(), countA = 0, countB = 0;

    for (int i = 0, j = (n / 2) ; i < n / 2; i++, j++) {
        cout<<s[i]<<" - "<<s[j]<<endl;
        if(seti.find(s[i]) != seti.end()){
            countA++;
        }
        if(seti.find(s[j]) != seti.end()){
            countB++;
        }
    }
    return countA == countB;
}

// Driver Code
int main() {
    string s = "Uu";
    cout << halvesAreAlike(s);
    return 0;
}

