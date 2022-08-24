#include <iostream>
#include "linkedList.cpp"
using namespace std;

//--------------- iterative approach ------------------------------------
void reverse(Node* &head){
    if(head == NULL || head->next == NULL){
        return ;
    }
    Node* prev = NULL;
    Node* curr = head;
    Node* forward = head;
    while(forward != NULL){
        forward = forward->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    head = prev;
}

//--------------------------------------------------------------------------------

//-------------------------- Recursive approach ------------------------------

Node* fun(Node* prev, Node* curr, Node* forward){
    if(forward==NULL){
        curr->next = prev;
        return curr;
    }
    curr->next = prev;
    return fun(curr, forward, forward->next);
}

void reverse2(Node* &head){
    if(head == NULL){
        return;
    }
    Node* prev = NULL;
    Node* curr = head;
    Node* forward = curr->next;
    head = fun(prev, curr, forward);
}

//------------------------------------------------------------------------------


int main(){
    Node* head = new Node(10);
    Node* tail = head;
    insertAtTail(tail, 20);
    insertAtTail(tail, 30);
    insertAtTail(tail, 40);
    insertAtTail(tail, 50);
    insertAtTail(tail, 60);
    reverse2(head);
    print(head);
}