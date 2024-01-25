//
// Created by Akshansh Gusain on 24/01/24.
//
#include "LL_000.cpp"

void deleteNode(ListNode* &head, int key){
    // if the list is empty
    if(head == nullptr){
        return;
    }

    ListNode *curr = head, *prev = nullptr;
     while(curr->val != key){
         if(curr->next == head){
             cout<<"Key not found";
             return;
         }
         prev = curr;
         curr = curr->next;
     }

    // If the node to be deleted is the only node in the list
    if (curr->next == head && prev == nullptr) {
        delete curr;
        head = nullptr;
        return;
    }

    // if the node to be deleted is the head of the list
    if(curr == head){
        prev = head;
        while(prev->next != head){
            prev = prev->next;
        }
        head = curr->next;
        prev->next = head;
    }else{
        // If the node to be deleted is not the head
        prev->next = curr->next;
    }

    delete curr;
}

int main(){
    ListNode *head = nullptr;

    /* Created linked list will be 2->5->7->8->10 */
    push(head, 2);
    push(head, 5);
    push(head, 7);
    push(head, 8);
    push(head, 10);
    makeCircular(head);

    cout << "List Before Deletion: ";
    printCircularList(head);

    deleteNode(head, 7);

    cout << "List After Deletion: ";
    printCircularList(head);


    return 0;
}