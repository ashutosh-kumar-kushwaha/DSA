#include <iostream>
#include "linkedList.cpp"
using namespace std;

Node* merge(Node* first, Node* second){
    if(first == NULL){
        return second;
    }
    if(second == NULL){
        return first;
    }
    
    if(first -> data > second -> data){
        Node* temp = first;
        first = second;
        second = temp;
    }

    Node* curr1 = first;
    Node* next1 = curr1 -> next;
    Node* curr2 = second;
    Node* next2 = curr2 -> next;
    while(curr2 != NULL && next1 != NULL){
        if(curr2 -> data >= curr1 -> data && curr2 -> data <= next1 -> data){
            curr1 -> next = curr2;
            curr2 -> next = next1;
            curr1 = curr2;
            curr2 = next2;
            if(next2 != NULL)
            next2 = next2 -> next;
        }
        else{
            curr1 = next1;
            next1 = next1 -> next;
        }
    }
    
    if(next1 == NULL){
        curr1 -> next = curr2;
    }

    return first;
}

int main(){
    Node* head1 = new Node(10);
    Node* tail1 = head1;
    insertAtTail(tail1, 20);
    insertAtTail(tail1, 40);
    insertAtTail(tail1, 80);
    insertAtTail(tail1, 90);

    Node* head2 = new Node(30);
    Node* tail2 = head2;
    insertAtTail(tail2, 50);
    insertAtTail(tail2, 60);
    insertAtTail(tail2, 70);
    Node* head = merge(head2, head1);
    print(head);

    return 0;
}