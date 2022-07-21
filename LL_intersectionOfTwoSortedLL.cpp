//
// Created by Akshansh Gusain on 04/03/21.
//
#include<stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
};

void push(struct Node** head_ref,int new_data){

    auto* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void printList(struct Node* node)
{
    while (node != nullptr) {
        printf("%d ", node->data);
        node = node->next;
    }
}

struct Node* sortedIntersect(
        struct Node* a,
        struct Node* b)
{
    struct Node* result = NULL;
    struct Node** lastPtrRef = &result;

    /* Advance comparing the first
     nodes in both lists.
    When one or the other list runs
     out, we're done. */
    while (a != NULL && b != NULL) {
        if (a->data == b->data) {
            /* found a node for the intersection */
            push(lastPtrRef, a->data);
            lastPtrRef = &((*lastPtrRef)->next);
            a = a->next;
            b = b->next;
        }
        else if (a->data < b->data)
            a = a->next; /* advance the smaller list */
        else
            b = b->next;
    }
    return (result);
}

int main(){
    struct Node* a = nullptr;
    struct Node* b = nullptr;
    struct Node* intersect = nullptr;

    /* Let us create the first sorted
     linked list to test the functions
   Created linked list will be
   1->2->3->4->5->6 */
    push(&a, 6);
    push(&a, 5);
    push(&a, 4);
    push(&a, 3);
    push(&a, 2);
    push(&a, 1);

    /* Let us create the second sorted linked list
   Created linked list will be 2->4->6->8 */
    push(&b, 8);
    push(&b, 6);
    push(&b, 4);
    push(&b, 2);

    /* Find the intersection two linked lists */
    intersect = sortedIntersect(a, b);

    printf("\n Linked list containing common items of a & b \n ");
    printList(intersect);

    return 0;
}
