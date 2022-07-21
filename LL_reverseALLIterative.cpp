//
// Created by Akshansh Gusain on 02/03/21.
//
#include<stdc++.h>
using namespace std;

//Liked List Node
struct Node{
    int data;
    struct Node* next;

    Node(int data){
        this->data = data;
        next = NULL;
    }
};

struct LinkedList{
    Node* head;
    LinkedList(){
        head = NULL;
    }

    //Function to reverse the linked lISt
    void reverse(){
        //Initilize current, previous and next pointers
        Node* current = head;
        Node *prev = NULL, *next = NULL;

        while(current != NULL){
            //store next
            next = current->next;
            //Reverse current node's pointer
            current->next = prev;

            //Move pointers one position ahead
            prev = current;
            current = next;
        }
        head = prev;
    }

    //Function to print Linked List
    void print(){
        struct Node* temp = head;
        while(temp != NULL){
            cout<< temp->data <<" ";
            temp = temp->next;
        }
    }

    void push(int data){
        Node* temp = new Node(data);
        temp->next = head;
        head = temp;
    }
};

int main(){
    LinkedList l1;
    l1.push(20);
    l1.push(4);
    l1.push(15);
    l1.push(85);
    l1.push(47);

    cout<<"Given Linked List: "<<endl;
    l1.print();cout<<endl;
    l1.reverse();

    cout<<"Reversed Linked List: "<<endl;
    l1.print();

    return 0;
}
