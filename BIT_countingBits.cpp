 //
// Created by Akshansh Gusain on 04/06/21.
//
//Counting the set bits

#include<stdc++.h>
using namespace std;

 unsigned int countSetBits(unsigned int n)
 {

     unsigned int count = 0;
     while (n) {
         count += n & 1;
         n >>= 1;
     }
     return count;
 }

/* Program to test function countSetBits */
 int main()
 {
     int i = 9;
     cout << countSetBits(i);
     return 0;
 }