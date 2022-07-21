//
// Created by Akshansh Gusain on 12/07/21.
//
#include<stdc++.h>
using namespace std;

// Time: O(NlogN), Space: O(1)

// After sorting the array and removing the multiple occurrences of elements
//run a loop and keep a count and max (both initially zero). Run a loop from start to end and if the current
// element is not equal to the previous (element+1) then set the count to 1 else increase the count.
// Update max with a maximum of count and max.

int longestConsecutiveSubSeq(vector<int> arr){
    int n = arr.size();
     int ans = 0, count = 0, start = 0, end = 0;

     sort(arr.begin(), arr.end());

     // Remove repeated elements
     vector<int> v;
     v.push_back(arr[0]);
     for(int i = 1; i < n ; i++){
         if (arr[i] != arr[i - 1])
             v.push_back(arr[i]);
     }

     for(int i = 0; i< v.size() ; i++){

         if(i > 0 and v[i] == v[i-1]+1){
             count++;
             end = i;
         }else{
             // reset count
             count = 1;
             start = i;
         }

         // update max leng
         ans = max(ans, count);
     }
}

// Time: O(N), Space: O(N)

// Using Hashing
// We first insert all elements in a Set. Then check all the possible starts of consecutive subsequences.
// Insert all array elements to hash.
// Check if this element is the starting point of a subsequence. To check this, simply look for arr[i] – 1
// in the hash, if not found, then this is the first element a subsequence.
// If this element is the first element, then count the number of elements in the consecutive starting with this
// element. Iterate from arr[i] + 1 till the last element that can be found.


int longestConsecutiveSubSeq2(vector<int> arr){
    int size = arr.size();

    unordered_set<int> s;
    int ans = 0;

    for(auto it: arr){
        s.insert(it);
    }

    //check each possible sequence from the start the update optimal length
    for(int i = 0 ; i <s.size(); i++){

        if(s.find(arr[i]-1) == s.end()){
            int  j  = arr[i];
            while(s.find(j) != s.end()){
                j++;
                ans = max(ans, j - arr[i]);
            }
        }
    }
    return ans;
}

int main() {
    vector<int> arr ={ 1, 2, 2, 3 };
    cout<<longestConsecutiveSubSeq(arr);
    return 0;
}
