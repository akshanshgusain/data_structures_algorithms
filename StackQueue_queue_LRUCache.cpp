//
// Created by Akshansh Gusain on 05/04/21.
//https://www.geeksforgeeks.org/lru-cache-implementation/
//We Will be using 2 Data Structures for LRU Cache :

//1. Queue which is implemented using a doubly linked list. The maximum size of the queue will be equal to the total
// number of frames available (cache size). The most recently used pages will be near front end and least recently
// pages will be near the rear end.

//2. A Hash with page number as key and address of the corresponding queue node as value.  (K,V) = (Page Number, Address of corresponding queue Node);
// We can use stl container list as a double ended queue to store the cache keys, with the descending time of reference
// from front to back and a set container to check presence of a key. But to fetch the address of the key in the list
// using find(), it takes O(N) time. This can be optimized by storing a reference (iterator) to each key in a hash map.

#include<stdc++.h>
using namespace std;

class LRUCache{
    //store keys of cache
    list<int> dq;
    unordered_map<int, list<int>::iterator> map;
    int cacheSize;
public:
    LRUCache(int);
    void refer(int);
    void display();
};

LRUCache::LRUCache(int n) {
    cacheSize = n;
}

void LRUCache::refer(int x) {
    //not present in the cache
    if(map.find(x) == map.end()){
        //if cache is full  - delete from rear
        if(dq.size() == cacheSize){
            int last = dq.back();
            dq.pop_back();
            map.erase(last);
        }
    }

    //if present in cache - bring the element to front and update the reference in the map
    dq.erase(map[x]);
    dq.push_front(x);
    map[x] = dq.begin();
}

void LRUCache:: display(){
    for (auto it = dq.begin(); it != dq.end();
         it++)
        cout << (*it) << " ";

    cout << endl;
}

int main(){
    LRUCache ca(4);

    ca.refer(1);
    ca.refer(2);
    ca.refer(3);
    ca.refer(1);
    ca.refer(4);
    ca.refer(5);
    ca.display();

    return 0;
}