//
// Created by Akshansh Gusain on 15/08/23.
//

#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class Queue {
private:
    Node* frontNode;
    Node* rearNode;

public:
    Queue() : frontNode(nullptr), rearNode(nullptr) {}

    void enqueue(int value) {
        Node* newNode = new Node(value);
        if (empty()) {
            frontNode = newNode;
            rearNode = newNode;
        } else {
            rearNode->next = newNode;
            rearNode = newNode;
        }
    }

    void dequeue() {
        if (!empty()) {
            Node* temp = frontNode;
            frontNode = frontNode->next;
            delete temp;
        }
    }

    int front() {
        if (!empty()) {
            return frontNode->data;
        }
        return -1; // Return a sentinel value to indicate an empty queue
    }

    bool empty() {
        return frontNode == nullptr;
    }

    int size() {
        int count = 0;
        Node* current = frontNode;
        while (current != nullptr) {
            count++;
            current = current->next;
        }
        return count;
    }

    ~Queue() {
        while (!empty()) {
            dequeue();
        }
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
