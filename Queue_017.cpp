//
// Created by Akshansh Gusain on 15/08/23.
//
#include<bits/stdc++.h>
using namespace std;


class Queue {
private:
    vector<int> data;

public:
    void enqueue(int value) {
        data.push_back(value);
    }

    void dequeue() {
        if (!empty()) {
            data.erase(data.begin());
        }
    }

    int front() {
        if (!empty()) {
            return data[0];
        }
        return -1; // Return a sentinel value to indicate an empty queue
    }

    bool empty() {
        return data.empty();
    }

    int size() {
        return data.size();
    }
};

int main() {
    Queue queue;

    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);

    std::cout << "Front element: " << queue.front() << std::endl;
    std::cout << "Queue size: " << queue.size() << std::endl;

    queue.dequeue();

    std::cout << "Front element after dequeue: " << queue.front() << std::endl;
    std::cout << "Queue size after dequeue: " << queue.size() << std::endl;

    return 0;
}
