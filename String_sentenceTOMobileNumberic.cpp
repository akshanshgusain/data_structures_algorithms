//
// Created by Akshansh Gusain on 21/01/21.
//
//Convert a sentence into its equivalent mobile numeric keypad sequence

//For each character, store the sequence which should be obtained at its respective position in an array,
// i.e. for Z, store 9999. For Y, store 999. For K, store 55 and so on.
#include<stdc++.h>

using namespace std;

string printSequence(string arr[], string input) {
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


int main() {
    //storing the sequence in array
    string str[] = {"2", "22", "222",
                    "3", "33", "333",
                    "4", "44", "444",
                    "5", "55", "555",
                    "6", "66", "666",
                    "7", "77", "777", "7777",
                    "8", "88", "888",
                    "9", "99", "999", "9999"
    };

    string input = "Akshansh Gusain";
    cout << printSequence(str, input);
    return 0;
}