//
// Created by Akshansh Gusain on 04/08/21.
//


#include <stdc++.h>

using namespace std;
using namespace std;

int main() {
  int n= 5;
  int arr[5] = {3,0,5,7,4};

    int arrMax = INT_MIN;
    for (int i = 0; i < n; i++) {
        if (arr[i] > arrMax) {
            arrMax = arr[i];
        }
    }


    for (int i = 0; i < arrMax; i++) {
        for (int j = 0; j < n; j++) {
            if ((arrMax - arr[j]) > i) {
                cout << " "<<" ";
            } else {
                cout << "*"<<" ";
            }
        }
        cout << endl;
    }

    return 0;
}