#include <iostream>
#include "linkedList.cpp"
using namespace std;

void removeDuplicates(Node* head){
    if(head == NULL){
        return ;
    }
    Node* curr = head;
    while(curr != NULL){
        if(curr -> next != NULL && curr -> data == curr -> next -> data){
            Node* nodeToBeDeleted = curr -> next;
            curr -> next = curr -> next -> next;
            delete(nodeToBeDeleted);
        }
        else{
            curr = curr -> next;
        }
    }
}

int main(){
    Node* head = new Node(10);
    Node* tail = head;
    insertAtTail(tail, 20);
    insertAtTail(tail, 20);
    insertAtTail(tail, 30);
    insertAtTail(tail, 30);
    insertAtTail(tail, 40);
    insertAtTail(tail, 40);
    insertAtTail(tail, 40);
    insertAtTail(tail, 50);
    insertAtTail(tail, 50);
    insertAtTail(tail, 50);
    insertAtTail(tail, 50);
    insertAtTail(tail, 60);
    insertAtTail(tail, 60);
    print(head);
    removeDuplicates(head);
    print(head);

    return 0;
}