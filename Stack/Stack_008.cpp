//
// Created by Akshansh Gusain on 08/02/24
//
//https://www.geeksforgeeks.org/efficiently-implement-k-stacks-single-array/
//https://www.youtube.com/watch?v=UmyOXVIjUoI
//How to efficiently implement k stacks in a single array?
#include<stdc++.h>

using namespace std;

class kStacks {
    int *arr; // Array of size n to store actual content to be stored in stacks
    int *top; // Array of size k to store indexes of top elements of stacks
    int *next;  // Array of size n to store next entry in all stacks
    int n, k;
    int free; // to store beginning index of free list

public:
    kStacks(int k, int n);

    bool isFull() {
        return (free - 1);
    }

    void push(int item, int sn); // sn = stack number
    int pop(int sn); // sn = stack number

    // To check whether stack number 'sn' is empty or not
    bool isEmpty(int sn) {
        return (top[sn] == -1);
    }
};

kStacks::kStacks(int k1, int n1) {
    k = k1, n = n1;
    arr = new int[n];
    top = new int[k];
    next = new int[n];

    //initialize all stack as empty
    for (int i = 0; i < k; i++) {
        top[i] = -1;
    }

    //initialize all space as empty
    free = 0;
    for (int i = 0; i < n - 1; i++) {
        next[i] = i + 1;
    }
    next[n - 1] = -1; // -1 is used to indicate end of free list
}

//item and stack number
void kStacks::push(int item, int sn) {
    //overflow check

    if (isFull()) {
        cout << "\nStack Overflow\n";
        return;
    }

    int i = free; //store the index of first available free stock
    free = next[i]; //update next of free slot to index of next slot in free list;

    //Update next of top and then top for stack number 'sn'
    next[i] = top[sn];
    top[sn] = i;

    //Put the item in array
    arr[i] = item;
}

int kStacks::pop(int sn){
    //underflow check
    if(isEmpty(sn)){
        cout<<"\nStack Underflow\n";
        return INT_MAX;
    }

    int i = top[sn]; // Find index of Top item in stack number 'sn'
    top[sn] = next[i];  // change top to store next of previous top
    next[i] = free; // attach the previous top to the beginning of free list
    free = i;

    return arr[i];
}

int main() {
    // Let us create 3 stacks in an array of size 10
    int k = 3, n = 10;
    kStacks ks(k, n);

    // Let us put some items in stack number 2
    ks.push(15, 2);
    ks.push(45, 2);

    // Let us put some items in stack number 1
    ks.push(17, 1);
    ks.push(49, 1);
    ks.push(39, 1);

    // Let us put some items in stack number 0
    ks.push(11, 0);
    ks.push(9, 0);
    ks.push(7, 0);

    cout << "Popped element from stack 2 is " << ks.pop(2) << endl;
    cout << "Popped element from stack 1 is " << ks.pop(1) << endl;
    cout << "Popped element from stack 0 is " << ks.pop(0) << endl;
    return 0;
}
