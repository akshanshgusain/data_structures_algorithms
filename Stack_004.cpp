//
// Created by Akshansh Gusain on 12/03/22.
//

#include<stdc++.h>

using namespace std;

class Queue {
    int start, end, size, capacity;
    vector<int> q;

public:
    Queue(int capacity) {
        this->capacity = capacity;
        this->start = 0;
        this->end = capacity - 1;
        this->size = 0;
    }

    int isFull() {
        return capacity == size;
    }

    int isEmpty() {
        return size == 0;
    }

    bool enqueu(int item) {
        if (isFull()) {
            cout << "Queue is Full \n";
            return false;
        }
        this->q.push_back(item);
        end = (end + 1)%capacity;
        size = size + 1;
        cout << item << " enqueued to queue\n";
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is Empty \n";
            return INT_MIN;
        }
        int item = q[start];
        start = (start + 1) % capacity;
    }

    int front(){
        if(isEmpty()){
            return INT_MIN;
        }
        return q[start];
    }

    int rear(){
        if(isEmpty()){
            return INT_MIN;
        }
        return q[end];
    }
};

int main() {
    Queue q = Queue(1000);
    q.enqueu(10);
    q.enqueu(20);
    q.enqueu(30);
    q.enqueu(40);


    cout << q.dequeue()
         << " dequeued from queue\n";

    cout << "Front item is "
         << q.front() << endl;
    cout << "Rear item is "
         << q.rear() << endl;


    return 0;
}