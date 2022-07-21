//
// Created by Akshansh Gusain on 16/03/22.
//

//https://www.geeksforgeeks.org/design-a-stack-with-find-middle-operation/
//Deleting an element from middle is not O(1) for array. Also, we may need to move the middle pointer up when we push
// an element and move down when we pop(). In singly linked list, moving middle pointer in both directions is not possible.
//The idea is to use Doubly Linked List (DLL). We can delete middle element in O(1) time by maintaining mid pointer.
// We can move mid pointer in both directions using previous and next pointers.


#include<stdc++.h>
using namespace std;

class DLLNode{
public:
    int data;
    DLLNode *prev,*next;
};

class Stack{
public:
    DLLNode *head, *mid;
    int count;
};

Stack* createStack(){
    auto *stack = new Stack();
    stack->count = 0;
    return stack;
}

void push(Stack *stack, int data){
    DLLNode* new_DLLNode = new DLLNode();
    new_DLLNode->data = data;

    //Adding in the beginning
    new_DLLNode->prev = nullptr;
    new_DLLNode->next = stack->head;
    stack->count +=1;

    //Change mid pointer in 2 cases:
    //1. LL is empty
    //Number of nodes in Ll is odd

    if(stack->count ==1){
        stack->mid = new_DLLNode;
    }else{
        stack->head->prev = new_DLLNode;
        if(!(stack->count & 1)){ //update mid if stack->count is even
            stack->mid = stack->mid->prev;
        }
    }

    stack->head = new_DLLNode;
}

int pop(Stack *stack){
    if(stack->count == 0){
        cout<<"Stack is empty \n";
        return -1;
    }

    DLLNode *head = stack->head;
    int item = head->data;
    stack->head = head->next;

    // If linked list doesn't
    // become empty, update prev
    // of new head as NULL
    if (stack->head != NULL)
        stack->head->prev = NULL;

    stack->count -=1;

    // update the mid pointer when
    // we have odd number of
    // elements in the stack, i,e
    // move down the mid pointer.
    if ((stack->count) & 1 )
        stack->mid = stack->mid->next;

    free(head);

    return item;
}

// Function for finding middle of the stack
int findMiddle(Stack *ms)
{
    if (ms->count == 0)
    {
        cout << "Stack is empty now\n";
        return -1;
    }

    return ms->mid->data;
}


int main(){
    Stack *ms = createStack();
    push(ms, 11);
    push(ms, 22);
    push(ms, 33);
    push(ms, 44);
    push(ms, 55);
    push(ms, 66);
    push(ms, 77);

    cout << "Item popped is " << pop(ms) << endl;
    cout << "Item popped is " << pop(ms) << endl;
    cout << "Middle Element is " << findMiddle(ms) << endl;
    return 0;
}