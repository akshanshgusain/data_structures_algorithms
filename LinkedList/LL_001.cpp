//
// Created by Akshansh Gusain on 16/01/24.
//
#include<bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;

    ListNode(){
        val = 0;
        next = nullptr;
    }
    explicit ListNode(int x){
        val = x;
        next = nullptr;
    }
    ListNode(int x, ListNode* next){
        val = x;
        this->next = next;
    }
};

void addAtEnd(ListNode* &head, int data){
    auto* myNode = new ListNode(data);
    ListNode* last = head;

    if(head == nullptr){
        head = myNode;
        return;
    }
    while(last->next != nullptr){
        last = last->next;
    }
    last->next = myNode;
}

void addAtStart(ListNode* &head, int data){
    auto* myNode = new ListNode(data);
    myNode->next = head;
    head = myNode;
}

void printLL(ListNode* head){
    while(head != nullptr){
        cout<<head->val<<" ";
        head = head->next;
    }
    cout<<endl;
}

int main() {
    ListNode* head = nullptr;
    addAtEnd(head, 20);
    addAtEnd(head, 30);
    addAtEnd(head, 50);
    addAtEnd(head, 60);
    addAtEnd(head, 40);
    addAtStart(head, 100);
    printLL(head);
    return 0;
}