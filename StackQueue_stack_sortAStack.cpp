//
// Created by Akshansh Gusain on 03/04/21.
//

#include<stdc++.h>

using namespace std;

struct Stack {
    int data;
    struct Stack *next;
};

int isEmpty(struct Stack *s) {
    if (s == nullptr) {
        return 1;
    }
    return 0;
}

void initStack(struct Stack **s) {
    *s = nullptr;
}

void push(struct Stack **s, int x) {

    auto *p = new Stack;
    p->data = x;
    p->next = *s;
    *s = p;
}

int pop(struct Stack **s) {
    int x;
    struct Stack *temp;

    x = (*s)->data;
    temp = *s;
    (*s) = (*s)->next;
    free(temp);

    return x;
}

int top(struct Stack *s) {
    return (s->data);
}

void printStack(struct Stack *s) {
    while (s) {
        cout << s->data << " ";
        s = s->next;
    }
    cout << "\n";
}


void sortedInsert(struct Stack **s, int x) {
    // Base case: Either stack is empty or newly inserted
    // item is greater than top (more than all existing)
    if (isEmpty(*s) or x > top(*s)) {
        push(s, x);
        return;
    }

    // If top is greater, remove the top item and recur
    int temp = pop(s);
    sortedInsert(s, x);

    // Put back the top item removed earlier
    push(s, temp);
}

void sortStack(struct Stack **s) {
    // If stack is not empty
    if (!isEmpty(*s)) {
        // Remove the top item
        int x = pop(s);

        // Sort remaining stack
        sortStack(s);

        // Push the top item back in sorted stack
        sortedInsert(s, x);
    }
}

int main() {
    struct Stack *top;

    initStack(&top);
    push(&top, 30);
    push(&top, -5);
    push(&top, 18);
    push(&top, 14);
    push(&top, -3);

    cout << "Stack elements before sorting:\n";
    printStack(top);

    sortStack(&top);
    cout << "\n";

    cout << "Stack elements after sorting:\n";
    printStack(top);

    return 0;
}