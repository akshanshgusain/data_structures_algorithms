//
// Created by Akshansh Gusain on 06/04/21.
//

#include<stdc++.h>
using namespace std;

const int MAX_CHAR = 26;

int minStringValue(string str, int k){
    int l = str.length();

    if (k >= l)
        return 0;

    // Else find Frequency of each character and
    // store in an array
    int frequency[MAX_CHAR] = { 0 };
    for (int i = 0; i < l; i++)
        frequency[str[i] - 'a']++;

    // Push each char frequency into a priority_queue
    priority_queue<int> q;
    for (int i = 0; i < MAX_CHAR; i++)
        q.push(frequency[i]);

    // Removal of K characters
    while (k--) {
        // Get top element in priority_queue,
        // remove it. Decrement by 1 and again
        // push into priority_queue
        int temp = q.top();
        q.pop();
        temp = temp - 1;
        q.push(temp);
    }

    int result = 0; // Initialize result
    while (!q.empty()) {
        int temp = q.top();
        result += temp * temp;
        q.pop();
    }

    return result;

}

int main(){

    string str = "abbccc"; // Input 1
    int k = 2;
    cout << minStringValue(str, k) << endl;

    str = "aaab"; // Input 2
    k = 2;
    cout << minStringValue(str, k);

    return 0;
}

