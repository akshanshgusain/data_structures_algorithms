//
// Created by Akshansh Gusain on 02/03/21.
//
/*---------------  USING HASHING  ------------  START  ---------------
#include<stdc++.h>
using namespace std;


struct Node {
    int data;
    struct Node* next;
};

void push(struct Node** head_ref, int new_data)
{
    // allocate node
    struct Node* new_node = new Node;

    // put in the data
    new_node->data = new_data;

    // link the old list off the new node
    new_node->next = (*head_ref);

    // move the head to point to the new node
    (*head_ref) = new_node;
}

// Returns true if there is a loop in linked list
// else returns false.
bool detectLoop(struct Node* h)
{
    unordered_set<Node*> s;
    while (h != NULL) {
        // If this node is already present
        // in hashmap it means there is a cycle
        // (Because you we encountering the
        // node for the second time).
        if (s.find(h) != s.end())
            return true;

        // If we are seeing the node for
        // the first time, insert it in hash
        s.insert(h);

        h = h->next;
    }

    return false;
}


int main(){
    //Start with the empty list
    struct Node* head = NULL;

    push(&head, 20);
    push(&head, 4);
    push(&head, 15);
    push(&head, 10);

    // Create a loop for testing
    head->next->next->next->next = head;

    if (detectLoop(head))
        cout << "Loop found";
    else
        cout << "No Loop";

    return 0;
}
---------------  USING HASHING  ------------  END  ---------------*/

/*---------------  USING MODIFIED LL  ------------  START  ---------------
#include <stdc++.h>
using namespace std;

//Link list node
struct Node {
    int data;
    struct Node* next;
    int flag;
};

void push(struct Node** head_ref, int new_data)
{
    // allocate node
    struct Node* new_node = new Node;

    // put in the data
    new_node->data = new_data;

    new_node->flag = 0;

    // link the old list off the new node
    new_node->next = (*head_ref);

    // move the head to point to the new node
    (*head_ref) = new_node;
}
// Returns true if there is a loop in linked list
// else returns false.
bool detectLoop(struct Node* h)
{
    while (h != NULL) {
        // If this node is already traverse
        // it means there is a cycle
        // (Because you we encountering the
        // node for the second time).
        if (h->flag == 1)
            return true;

        // If we are seeing the node for
        // the first time, mark its flag as 1
        h->flag = 1;

        h = h->next;
    }

    return false;
}

// Driver program to test above function
int main()
{
    // Start with the empty list
    struct Node* head = NULL;

    push(&head, 20);
    push(&head, 4);
    push(&head, 15);
    push(&head, 10);

    // Create a loop for testing
    head->next->next->next->next = head;

    if (detectLoop(head))
        cout << "Loop found";
    else
        cout << "No Loop";

    return 0;
}
---------------  USING MODIFIED LL  ------------  END  ---------------*/

/*---------------  USING FLOYD"S CYCLE-FINDING ALGO  ------------  START  ---------------*/
#include <stdc++.h>
using namespace std;

/* Link list node */
class Node {
public:
    int data;
    Node* next;
};

void push(Node** head_ref, int new_data)
{
    /* allocate node */
    Node* new_node = new Node();

    /* put in the data */
    new_node->data = new_data;

    /* link the old list off the new node */
    new_node->next = (*head_ref);

    /* move the head to point to the new node */
    (*head_ref) = new_node;
}

int detectLoop(Node* list)
{
    Node *slow_p = list, *fast_p = list;

    while (slow_p && fast_p && fast_p->next) {
        slow_p = slow_p->next;
        fast_p = fast_p->next->next;
        if (slow_p == fast_p) {
            return 1;
        }
    }
    return 0;
}

/* Driver code*/
int main()
{
    /* Start with the empty list */
    Node* head = NULL;

    push(&head, 20);
    push(&head, 4);
    push(&head, 15);
    push(&head, 10);

    /* Create a loop for testing */
    head->next->next->next->next = head;
    if (detectLoop(head))
        cout << "Loop found";
    else
        cout << "No Loop";
    return 0;
}

/*---------------  USING FLOYD"S CYCLE-FINDING ALGO  ------------  END  ---------------*/

