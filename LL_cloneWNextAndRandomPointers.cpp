//
// Created by Akshansh Gusain on 08/03/21.
// Using Hash Map O(n) time and O(n) space

#include<stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node *next, *random;

    Node(int data){
        this->data = data;
        this->random = nullptr;
    }
};

class LinkedList{
public:
    Node *head;
    explicit LinkedList(Node *head){
        this->head = head;
    }
    void push(int data){
        Node *node = new Node(data);
        node->next = head;
        head = node;
    }

    void print() const
    {
        Node *temp = head;
        while (temp != NULL)
        {
            Node *random = temp->random;
            int randomData = (random != NULL)?
                             random->data: -1;
            cout << "Data = " << temp->data
                 << ", ";
            cout << "Random Data = " <<
                 randomData << endl;
            temp = temp->next;
        }
        cout << endl;
    }

    //Clone Method
    LinkedList* clone(){
        Node *origCurr = head;
        Node *cloneCurr = nullptr;

        unordered_map<Node*, Node*> mymap;
        while(origCurr != nullptr){
            cloneCurr = new Node(origCurr->data);
            mymap[origCurr] = cloneCurr;
            origCurr = origCurr->next;
        }

        origCurr = head;

        while(origCurr != nullptr){
            cloneCurr = mymap[origCurr];
            cloneCurr->next = mymap[origCurr->next];
            cloneCurr->random = mymap[origCurr->random];
            origCurr = origCurr->next;

        }

        return new LinkedList(mymap[head]);
    }

};


int main(){
    // Pushing data in the linked list.
    auto *mylist = new LinkedList(new Node(5));
    mylist->push(4);
    mylist->push(3);
    mylist->push(2);
    mylist->push(1);

    // Setting up random references.
    mylist->head->random = mylist->head->next->next;

    mylist->head->next->random =
            mylist->head->next->next->next;

    mylist->head->next->next->random =
            mylist->head->next->next->next->next;

    mylist->head->next->next->next->random =
            mylist->head->next->next->next->next->next;

    mylist->head->next->next->next->next->random =
            mylist->head->next;

    // Making a clone of the original
    // linked list.
    LinkedList *clone = mylist->clone();

    // Print the original and cloned
    // linked list.
    cout << "Original linked list\n";
    mylist->print();
    cout << "\nCloned linked list\n";
    clone->print();

    return 0;
}
