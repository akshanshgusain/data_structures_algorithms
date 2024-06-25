//
// Created by Akshansh Gusain on 25/12/21.
//

//#include<stdc++.h>
//
//using namespace std;
//
//bool isPalindrome(string String, int i, int j) {
//    while (i < j) {
//        if (String[i] != String[j])
//            return false;
//        i++;
//        j--;
//    }
//    return true;
//}
//
//
//
//
//int minPalPartition(string str, int i, int j) {
//
//    if (i >= j or isPalindrome(str, i, j)) {
//        return 0;
//    }
//    int res = INT_MAX;
//
//    for (int k = i; k < j; k++) {
//        int tempAns = 1 +
//                      minPalPartition(str, i, k) +
//                      minPalPartition(str, k + 1, j);
//        res = min(res, tempAns);
//    }
//
//    return res;
//}
//
//int main() {
//    string str = "ababbbabbababa";
//   // string str = "nitin";
//    cout << "Min cuts needed for " <<
//         "Palindrome Partitioning is " <<
//         minPalPartition(str, 0, str.length() - 1) << endl;
//    return 0;
//}


#include<stdc++.h>
using namespace std;
int T[1001][1001];

bool isPalindrome(string String, int i, int j) {
    while (i < j) {
        if (String[i] != String[j])
            return false;
        i++;
        j--;
    }
    return true;
}


int minPalPartition(string str, int i, int j) {

    if (i >= j or isPalindrome(str, i, j)) {
        return 0;
    }

    if(T[i][j] != -1){
        return T[i][j];
    }

    int res = INT_MAX;

    for (int k = i; k < j; k++) {
        int tempAns = 1 +
                      minPalPartition(str, i, k) +
                      minPalPartition(str, k + 1, j);
        res = min(res, tempAns);
    }

    return T[i][j] = res;
}

int main() {
    memset(T,-1, sizeof T);
    string str = "ababbbabbababa";
    // string str = "nitin";
    cout << "Min cuts needed for " <<
         "Palindrome Partitioning is " <<
         minPalPartition(str, 0, str.length() - 1) << endl;
    return 0;
}