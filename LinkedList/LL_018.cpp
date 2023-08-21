//
// Created by Akshansh Gusain on 16/10/21.
//

#include<stdc++.h>

using namespace std;

class Node {
public:
    char data;
    Node *next;

    explicit Node(char data) {
        this->data = data;
        next = nullptr;
    }
};

void push(Node *&head, char value) {
    Node *temp = new Node(value);
    temp->next = head;
    head = temp;
}

void print(Node *node) {
    while (node != nullptr) {
        if (node->next != nullptr) {
            cout << node->data << "->";
        } else {
            cout << node->data;
        }

        node = node->next;
    }
    cout << endl;
}

void reverse(struct Node* &head_ref) {
    struct Node *prev = NULL;
    struct Node *current = head_ref;
    struct Node *next;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head_ref = prev;
}

bool compareLists(struct Node *head1, struct Node *head2) {
    struct Node *temp1 = head1;
    struct Node *temp2 = head2;

    while (temp1 && temp2) {
        if (temp1->data == temp2->data) {
            temp1 = temp1->next;
            temp2 = temp2->next;
        } else
            return 0;
    }

    /* Both are empty reurn 1*/
    if (temp1 == NULL && temp2 == NULL)
        return 1;

    /* Will reach here when one is NULL
    and other is not */
    return 0;
}


bool isPalindrome(Node *&head) {
     Node *slow_ptr = head, *fast_ptr = head;
     Node *second_half, *prev_of_slow_ptr = head;
     Node *midnode = nullptr; // To handle odd size list
    bool res = true; // initialize result

    if (head != nullptr && head->next != nullptr) {
        /* Get the middle of the list. Move slow_ptr by 1
        and fast_ptrr by 2, slow_ptr will have the middle
        node */
        while (fast_ptr != nullptr && fast_ptr->next != nullptr) {
            fast_ptr = fast_ptr->next->next;

            /*We need previous of the slow_ptr for
            linked lists with odd elements */
            prev_of_slow_ptr = slow_ptr;
            slow_ptr = slow_ptr->next;
        }

        /* fast_ptr would become NULL when there are even elements in list.
        And not NULL for odd elements. We need to skip the middle node
        for odd case and store it somewhere so that we can restore the
        original list*/
        if (fast_ptr != nullptr) {
            midnode = slow_ptr;
            slow_ptr = slow_ptr->next;
        }

        // Now reverse the second half and compare it with first half
        second_half = slow_ptr;
        prev_of_slow_ptr->next = NULL; // NULL terminate first half
        reverse(second_half); // Reverse the second half
        res = compareLists(head, second_half); // compare

        /* Construct the original list back */
        reverse(second_half); // Reverse the second half again

        // If there was a mid node (odd size case) which
        // was not part of either first half or second half.
        if (midnode != nullptr) {
            prev_of_slow_ptr->next = midnode;
            midnode->next = second_half;
        } else
            prev_of_slow_ptr->next = second_half;
    }
    return res;
}

int main() {
    string inputString = "abacabad";
    Node *head = nullptr;

    for (char i: inputString) {
        push(head, i);
        print(head);
        isPalindrome(head)? cout<<"Palindrome" : cout<<"Not a Palindrome";
        cout<<endl;
    }
    return 0;
}