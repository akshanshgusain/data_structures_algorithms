//
// Created by Akshansh Gusain on 13/01/21.
//
//Print distinct sorted permutations with duplicates allowed in input

//Write a program to print all distinct permutations of a given string in sorted order.
// Note that the input string may contain duplicate characters.

#include <stdc++.h>
using namespace std;

int factorial(int n){
    if(n==0){
        return n;
    }
    int previousResult =  factorial(n-1);
    return n+previousResult;
}

int calculateTotal(string temp, int n){
        int f = factorial(n);

        //Building  a map to store frequencies of all characters
        map<char, int> hm;
        for(int i= 0; i<n;i++){
            hm[temp[i]]++;
        }

        //Traversing the map and finding duplicate elements.
        for(auto e: hm){
            int x = e.second;
            if(x>1){
                int tempInt = factorial(x);
                f /= tempInt;
            }
            return f;
        }
}

void nextPermutation(string &temp){
    //Start traversing from the end find position 'i-1' of the first character which is greater than its successor.

    int i;
    for(i = temp.length()-1; i>0; i--){
        if (temp[i]> temp[i-1]) {
            break;
        }
    }

    //Find the smallest character after 'i-1' and greater than temp[i-1]
    int min = i;
    int j,x = temp[i-1];
    for(j=i+1; j< temp.length(); j++){
         if((temp[j] < temp[min]) && (temp[j] > x)){
             min = j;
         }
    }

    //swapping the above found characters.
    swap(temp[i-1], temp[min]);

    //sort all digits from position next to 'i-1' to the end of string
    sort(temp.begin()+i, temp.end());
    cout<< temp << endl;
}

void printAllPermutations(string s){

    string temp(s);
    sort(temp.begin(), temp.end());

    //print out first permutation
    cout<< temp <<endl;

    int total = calculateTotal(temp, temp.length());

    for(int i=0; i<total; i++){
        nextPermutation(temp);
    }
}
// Driver code
int main()
{
    string s = "ABC";
    printAllPermutations(s);
    return 0;
}

