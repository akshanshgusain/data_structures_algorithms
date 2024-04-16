//
// Created by Akshansh Gusain on 16/03/24.
//

#include<stdc++.h>
using namespace std;

void reverseQueueFirstKElements(int k, queue<int>& Queue){
    if (Queue.empty() == true || k > Queue.size())
        return;
    if (k <= 0)
        return;

    stack<int> stack;

    // push the first K element to the stack
    for(int i = 0 ; i < k ;i ++){
        stack.push(Queue.front());
        Queue.pop();
    }

    // enqueue the contents of stack back to the queue
    while(!stack.empty()){
        Queue.push(stack.top());
        stack.pop();
    }

    // remove the remaining(n - k ) elements from the front and
    // enqueue them to the back
    for(int i = 0; i < Queue.size() - k; i++ ){
        Queue.push(Queue.front());
        Queue.pop();
    }
}

int main(){
    queue<int> Queue;
    Queue.push(10);
    Queue.push(20);
    Queue.push(30);
    Queue.push(40);
    Queue.push(50);
    Queue.push(60);
    Queue.push(70);
    Queue.push(80);
    Queue.push(90);
    Queue.push(100);

    // 10 20 30 40 50 60 70 80 90 100

    int k = 5;
    reverseQueueFirstKElements(k, Queue);

    Print(Queue);

    // 50 40 30 20 10 60 70 80 90 100
    return 0;
}