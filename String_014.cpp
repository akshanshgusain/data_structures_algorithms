//
// Created by Akshansh Gusain on 06/08/21.
//
//Find next greater number with same set of digits
//https://www.geeksforgeeks.org/find-next-greater-number-set-digits/

#include<stdc++.h>

using namespace std;

void swap(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

void findNext(char number[], int n)
{
    int i, j;

    // I) Start from the right most digit and find the first digit that is
    // smaller than the digit next to it.
    for (i = n-1; i > 0; i--)
        if (number[i] > number[i-1])
            break;

        // If no such digit is found, then all digits are in descending order
        // means there cannot be a greater number with same set of digits
        if (i==0)
        {
            cout << "Next number is not possible";
            return;
        }

        // II) Find the smallest digit on right side of (i-1)'th digit that is
        // greater than number[i-1]
        int x = number[i-1], smallest = i;
        for (j = i+1; j < n; j++)
            if (number[j] > x && number[j] < number[smallest])
                smallest = j;

            // III) Swap the above found smallest digit with number[i-1]
            swap(&number[smallest], &number[i-1]);

            // IV) Sort the digits after (i-1) in ascending order
            sort(number + i, number + n);

            cout << "Next number with same set of digits is " << number;

}

int main() {
    //char digits[] = "534976";
    //    char digits[] = "4321";
    // char digits[] = "1234";
    char digits[] = "536976"; //537669
    int n = strlen(digits);
    findNext(digits, n);
    return 0;
}