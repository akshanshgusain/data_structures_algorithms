//
// Created by Akshansh Gusain on 22/07/22.
//

#include<stdc++.h>
using namespace std;
//Method 1 is to use stack as intermediate Data structure  O(n) time and O(n) Space
//Method 2 is to use recursion (Function Call stack).


#include<stdc++.h>
using namespace std;

void printQueue(queue<long long int> Queue){

    while (!Queue.empty()) {
        cout << Queue.front() << " ";
        Queue.pop();
    }
}

void reverseQueue(queue<long long int>& q){
    if(q.empty()){
        return;
    }

    long long int data = q.front();
    q.pop();

    reverseQueue(q);

    q.push(data);
}

int main(){
    queue<long long int> Queue;
    Queue.push(56);
    Queue.push(27);
    Queue.push(30);
    Queue.push(45);
    Queue.push(85);
    Queue.push(92);
    Queue.push(58);
    Queue.push(80);
    Queue.push(90);
    Queue.push(100);
    printQueue(Queue);
    cout<<endl <<"Reversal \n";
    reverseQueue(Queue);
    printQueue(Queue);
    return 0;
}
