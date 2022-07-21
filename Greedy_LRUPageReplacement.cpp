//
// Created by Akshansh Gusain on 25/03/21.
//
#include<stdc++.h>
using namespace std;

int pageFaults(int pages[], int n,int capacity){
    unordered_set<int> s;
    unordered_map<int, int> indexes;

    int pages_fault = 0;
    for(int i = 0; i<n ;i++){
        //check of the set can hold more pages
        if(s.size() < capacity){
            //Insert it into set if not present already which represents page fault
            if(s.find(pages[i]) == s.end()){
                s.insert(pages[i]);
                pages_fault++;
            }

            //store the recently used index of each page
            indexes[pages[i]] = i;
        }

        //If the set is full then need to perform LRU
        //remove the least recently used page and insert the current page;
        else{
            //check if current page is not already present
            if(s.find(pages[i]) == s.end()){
                //find the least recently used pages that is present in the set

                int lru = INT_MAX, val;
                for(auto it = s.begin(); it!= s.end(); it++){
                    if(indexes[*it] < lru){
                        lru = indexes[*it];
                        val = *it;
                    }
                }
                //remove the indexes page
                s.erase(val);
                //insert current page
                s.insert(pages[i]);
                //Increment page fault
                pages_fault++;
            }

            indexes[pages[i]] = i;
        }
    }
    return pages_fault;
}

int main(){
    int pages[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2};
    int n = sizeof(pages)/sizeof(pages[0]);
    int capacity = 4;
    cout<< pageFaults(pages, n, capacity) ;
    return 0;
}
