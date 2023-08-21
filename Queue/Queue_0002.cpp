//
// Created by Akshansh Gusain on 22/07/22.
//

#include<stdc++.h>

using namespace std;

class Queue {
private:
    int front, end, size;
    vector<int> arr;
public:

    Queue(int size) {
        this->size = size;
        front = end = -1;
        arr.resize(size);
    }

    void enQueue(int element) {
        // Check for overflow condition
        if ((front == 0 and end == size - 1) or
            (end == (front - 1) % (size - 1))) {
            cout << "Queue is Full \n";
            return;
        } else if (front == -1) {
            front = end = 0;
            arr[end] = element;
        } else {
            end++;
            arr[end] = element;
        }
    }

    int deQueue() {
        //Check for under flow condition
        if (front == -1) {
            cout << "Stack Under flow \n";
            return INT_MIN;
        }

        int data = arr[front];
        arr[front] = -1;

        if (front == end) {
            front = -1;
            end = -1;
        } else if (front == size - 1) {
            front = 0;
        } else {
            front++;
        }

        return data;
    }

    void displayQueue() {
        if (front == -1) {
            printf("\nQueue is Empty");
            return;
        }
        printf("\nElements in Circular Queue are: ");
        if (end >= front) {
            for (int i = front; i <= end; i++)
                printf("%d ", arr[i]);
        } else {
            for (int i = front; i < size; i++)
                printf("%d ", arr[i]);

            for (int i = 0; i <= end; i++)
                printf("%d ", arr[i]);
        }
    }

};

int main() {
    Queue q(5);

    // Inserting elements in Circular Queue
    q.enQueue(14);
    q.enQueue(22);
    q.enQueue(13);
    q.enQueue(-6);

    // Display elements present in Circular Queue
    q.displayQueue();

    // Deleting elements from Circular Queue
    printf("\nDeleted value = %d", q.deQueue());
    printf("\nDeleted value = %d", q.deQueue());

    q.displayQueue();

    q.enQueue(9);
    q.enQueue(20);
    q.enQueue(5);

    q.displayQueue();
    q.enQueue(20);
    return 0;
}