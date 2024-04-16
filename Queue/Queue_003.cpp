//
// Created by Akshansh Gusain on 16/03/24.
//

//https://www.geeksforgeeks.org/lru-cache-implementation/
// Implement Least-Frequently-Used Cache

//We Will be using 2 Data Structures for LRU Cache :

//1. Queue which is implemented using a doubly linked list. The maximum size of the queue will
// be equal to the total number of frames available (cache size). The most recently used pages
// will be near front end and least recently pages will be near the rear end.

//2. A Hash with page number as key and address of the corresponding queue node as value.
// (K,V) = (Page Number, Address of corresponding queue Node);

// We can use stl container list as a double ended queue to store the cache keys, with the descending time of reference
// from front to back and a set container to check presence of a key. But to fetch the address of the key in the list
// using find(), it takes O(N) time. This can be optimized by storing a reference (iterator) to each key in a hash map.


#include<stdc++.h>

using namespace std;

class LRUCache {
private:
    // store keys of cache
    list<int> dq;

    // (K,V) = (Page Number, Address of corresponding queue Node);
    unordered_map<int, list<int>::iterator> map;

    int cacheSize;
public:
    LRUCache(int size) {
        this->cacheSize = size;
    }

    void refer(int x){

        //not present in the cache
        // find operation in dequeue will take O(N)
        // that's why I have used a unordered map here.
        if(map.find(x) == map.end()){
            // if cache is full - delete from the rear
            if(dq.size() == cacheSize){
                int last = dq.back();
                dq.pop_back();
                map.erase(last);
            }
        }else{
            // if present in the cache - bring the element to the front and
            // update the reference in the map
            dq.erase(map[x]); // takes O(N)
            dq.push_front(x);
            map[x] = dq.begin();

        }

    }

    void display(){
        for (int & it : dq)
            cout << it << " ";

        cout << endl;
    }

};


int main() {
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