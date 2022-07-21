//
// Created by Akshansh Gusain on 13/08/21.
//

#include<stdc++.h>
using namespace std;

string printSequence(string input, string arr[]){
    string output = "";

    // length of input string
    int n = input.length();
    for (int i = 0; i < n; i++) {
        // Checking for space
        if (input[i] == ' ')
            output = output + "0";

        else {
            // Calculating index for each
            // character
            int position = 0;
            if (isupper(input[i])) {
                position = input[i] - 'A';
            } else {
                position = input[i] - 'a';
            }

            output = output + arr[position];
        }
    }

    // Output sequence
    return output;
}

int main(){
    // storing the sequence in array
    string str[] = {"2","22","222",
                    "3","33","333",
                    "4","44","444",
                    "5","55","555",
                    "6","66","666",
                    "7","77","777","7777",
                    "8","88","888",
                    "9","99","999","9999"
    };

    string input = "akshansh Gusain";
    cout << printSequence(input, str);
    return 0;
}