//
// Created by Akshansh Gusain on 07/01/22.
//https://www.geeksforgeeks.org/count-derangements-permutation-such-that-no-element-appears-in-its-original-position/


#include<stdc++.h>

using namespace std;

//countDer(n) = (n - 1) * [countDer(n - 1) + countDer(n - 2)]
/*There are n – 1 way for element 0 (this explains multiplication with n – 1).
Let 0 be placed at index i. There are now two possibilities, depending on whether or not element i is
 placed at 0 in return.

i is placed at 0: This case is equivalent to solving the problem for n-2 elements as two elements have just
 swapped their positions.
i is not placed at 0: This case is equivalent to solving the problem for n-1 elements as now there are n-1
elements, n-1 positions and every element has n-2 choices */

// Recursive approach with exponential time complexity
//int countDer(int n)
//{
//    // Base cases
//    if (n == 1) return 0;
//    if (n == 2) return 1;
//
//    // countDer(n) = (n-1)[countDer(n-1) + der(n-2)]
//    return (n - 1) * (countDer(n - 1) + countDer(n - 2));
//}
//
//int main() {
//    int n = 4;
//    cout << "Count of Derangements is "
//         << countDer2(n);
//    return 0;
//}


// Optimised with TOP DOWn = Time: O(N), Space: O(N)

int countDer2(int n){
    int T[n+1];

    // Base Cases
    T[0] = T[1] = 0;
    T[2] = 1;

    for(int i = 3; i <= n ; i++){
        T[i] = (i-1) * (T[i-1] + T[i-2]);
    }

    return T[n];
}

// Spaced Optimised Approach :As we only need to remember only two previous values So

// Time: O(N), Space: O(1)

int countDer3(int n){

    // Base Cases
    int first = 0;
    int second = 1;
    int third = 0;

    for(int i = 3; i <= n ; i++){
        third = (i-1) * (second + first);
        first = second;
        second = third;
    }

    return second;
}

int main() {
    int n = 4;
    cout << "Count of Derangements is "
         << countDer3(n);
    return 0;
}
