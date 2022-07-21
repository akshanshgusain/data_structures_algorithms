//
// Created by Akshansh Gusain on 03/03/21.
//

//Method 1: Using Sorting: Sort the LL and apply remove element in sorted array
//Method 2: Using two loops:
/*#include<stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;
};
void removeDuplicates(Node* head){
    Node *ptr1, *ptr2, *dup;
    ptr1 = head;

    while (ptr1 != nullptr && ptr1->next != nullptr)
    {
        ptr2 = ptr1;

        while (ptr2->next != nullptr)
        {

            if (ptr1->data == ptr2->next->data)
            {

                dup = ptr2->next;
                ptr2->next = ptr2->next->next;
                delete(dup);
            }
            else
                ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
}

void push(Node** head_ref, int data){
    Node* new_node = new Node();
    new_node->data = data;
    new_node->next = (*head_ref);
    *head_ref = new_node;
}
void printList(Node *node){
        while(node!=nullptr){
            cout<<" "<<node->data;
            node = node->next;
        }
}

int main(){
    Node* head = nullptr;

    push(&head, 20);
    push(&head, 43);
    push(&head, 20);
    push(&head, 9);
    push(&head, 1);
    push(&head, 43);

    cout<<"LL Before: "<<endl;
    printList(head);

    removeDuplicates(head);

    cout<<"LL After: "<<endl;
    printList(head);

    return 0;
}
 */
//Method 3: Using Hashmap
#include<stdc++.h>
using namespace std;

/* A linked list node */
struct Node
{
    int data;
    struct Node *next;
};

// Utility function to create a new Node
struct Node *newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->next = NULL;
    return temp;
}

/* Function to remove duplicates from a
   unsorted linked list */
void removeDuplicates(struct Node *start)
{
    // Hash to store seen values
    unordered_set<int> seen;

    /* Pick elements one by one */
    struct Node *curr = start;
    struct Node *prev = NULL;
    while (curr != NULL)
    {
        // If current value is seen before
        if (seen.find(curr->data) != seen.end())
        {
            prev->next = curr->next;
            delete (curr);
        }
        else
        {
            seen.insert(curr->data);
            prev = curr;
        }
        curr = prev->next;
    }
}

/* Function to print nodes in a given linked list */
void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
}

/* Driver program to test above function */
int main()
{
    /* The constructed linked list is:
     10->12->11->11->12->11->10*/
    struct Node *start = newNode(10);
    start->next = newNode(12);
    start->next->next = newNode(11);
    start->next->next->next = newNode(11);
    start->next->next->next->next = newNode(12);
    start->next->next->next->next->next =
            newNode(11);
    start->next->next->next->next->next->next =
            newNode(10);

    cout<<"LL Before :\n";
    printList(start);

    removeDuplicates(start);

    printf("\nLinked list after removing duplicates : \n");
    printList(start);

    return 0;
}