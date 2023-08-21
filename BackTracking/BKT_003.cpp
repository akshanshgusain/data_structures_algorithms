//
// Created by Akshansh Gusain on 20/08/23.
//

//Leetcode hard: https://leetcode.com/problems/remove-invalid-parentheses/


#include<stdc++.h>

using namespace std;

bool isParenthesis(char ch) {
    return ((ch == '(') || (ch == ')'));
}

bool isValidString(const string& str) {
    int cnt = 0;
    for (char i : str) {
        if (i == '(') {
            cnt++;
        } else if (i == ')') {
            cnt--;
        }
        if (cnt < 0) {
            return false;
        }
    }
    return (cnt == 0);
}

void removeInvalidParenthesis(string str) {
    if (str.empty()) {
        return;
    }
    //visited set to ignore already visited string
    unordered_set<string> visit;
    //queue to maintain BFS
    queue<string> q;

    string temp;
    bool level;

    //pushing given string as starting node into queue
    q.push(str);
    visit.insert(str);

    while (!q.empty()) {
        str = q.front();
        q.pop();

        if (isValidString(str)) {
            cout << str << endl;
            // If answer is found, make level true
            // so that valid string of only that level
            // are processed.
            level = true;
        }
        if (level) {
            continue;
        }
        for (int i = 0; i < str.length(); i++) {

            if (!isParenthesis(str[i])) {
                continue;
            }

            //removing parenthesis from str and pushing into queue, if not visited already
            temp = str.substr(0, i) + str.substr(i + 1);
            if (visit.find(temp) == visit.end()) {
                q.push(temp);
                visit.insert(temp);
            }
        }

    }
}

int main() {
    removeInvalidParenthesis("(a)())()");
    cout << endl;
//    removeInvalidParenthesis("()())()");
//    cout << endl;

    return 0;
}

/*
(a())()
(a)()()

(())()
()()()

 */
