//
// Created by Akshansh Gusain on 28/03/21.
//Leetcode hard: https://leetcode.com/problems/remove-invalid-parentheses/


#include<stdc++.h>

using namespace std;

bool isParenthesis(char ch) {
    return ((ch == '(') || (ch == ')'));
}

bool isValidString(string str) {
    int cnt = 0;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '(') {
            cnt++;
        } else if (str[i] == ')') {
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
    set<string> visit;
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
            //if ans is found make level true so that valid string of only that level are proceeded.
            level = true;
        }
        if(level){
            continue;
        }
        for(int i = 0; i<str.length(); i++){

            if(!isParenthesis(str[i])){
                continue;
            }

            //removing parenthesis from str and pushing into queue, if not visited already
            temp = str.substr(0,i)+str.substr(i+1);
            if(visit.find(temp) == visit.end()){
                q.push(temp);
                visit.insert(temp);
            }
        }

    }
}

int main() {
    string expression = "()())()";
    removeInvalidParenthesis(expression);

    expression = "()v)";
    removeInvalidParenthesis(expression);

    return 0;
}