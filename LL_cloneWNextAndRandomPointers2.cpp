//
// Created by Akshansh Gusain on 08/03/21.
// O(n) time and O(1) space

#include<stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next,*random;
    Node(int x)
    {
        data = x;
        next = random = NULL;
    }
};

// Utility function to print the list.
void print(Node *start)
{
    Node *ptr = start;
    while (ptr)
    {
        cout << "Data = " << ptr->data << ", Random  = "
             << ptr->random->data << endl;
        ptr = ptr->next;
    }
}

Node* clone(Node *head){
    Node* curr = head, *temp;

    //Insert additional node after every node of original list
    while(curr){
        temp = curr->next;

        curr->next = new Node(curr->data);
        curr->next->next = temp;
        curr = temp;
    }
    curr = head;

    //Adjust the random pointers of newly added nodes
    while(curr){
        if(curr->next){
            curr->next->random = curr->random? curr->random->next:curr->random;
            curr = curr->next?curr->next->next: curr->next;
        }
    }

    Node* original = head, *copy = head->next;
    temp = copy; //save the start of copied LL

    //seperate the original list and copied list
    while(original && copy){
        original->next = original->next? original->next->next: original->next;

        copy->next = copy->next?copy->next->next : copy->next;
        original = original->next;
        copy = copy->next;
    }

    return temp;
}



int main(){
    Node* start = new Node(1);
    start->next = new Node(2);
    start->next->next = new Node(3);
    start->next->next->next = new Node(4);
    start->next->next->next->next = new Node(5);

    // 1's random points to 3
    start->random = start->next->next;

    // 2's random points to 1
    start->next->random = start;

    // 3's and 4's random points to 5
    start->next->next->random =
            start->next->next->next->next;
    start->next->next->next->random =
            start->next->next->next->next;

    // 5's random points to 2
    start->next->next->next->next->random =
            start->next;

    cout << "Original list : \n";
    print(start);

    cout << "\nCloned list : \n";
    Node *cloned_list = clone(start);
    print(cloned_list);

    return 0;

    return 0;
}
