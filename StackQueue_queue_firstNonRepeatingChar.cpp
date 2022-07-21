//
// Created by Akshansh Gusain on 06/04/21.
//

#include<stdc++.h>

using namespace std;
const int MAX_CHAR = 26;

void firstnonrepeating(char str[]) {
    queue<char> q;
    int charCount[MAX_CHAR] = {0};

    for(int i =0; str[i]; i++){

        q.push(str[i]);

        charCount[str[i]-'a']++;

        // check for the non repeating character
        while (!q.empty()) {
            if (charCount[q.front() - 'a'] > 1)
                q.pop();
            else {
                cout << q.front() << " ";
                break;
            }
        }

        if (q.empty())
            cout << -1 << " ";
    }

    cout << endl;
}

int main() {

    char str[] = "aabc";
    firstnonrepeating(str);
    return 0;

}