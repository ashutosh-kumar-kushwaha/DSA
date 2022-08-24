#include <iostream>
#include "linkedList.cpp"
using namespace std;

Node* middleElement(Node* head){
    bool check = true;
    Node* fast = head;
    Node* slow = head;
    while(fast -> next != NULL){
        fast = fast -> next;
        if(check){
            slow = slow -> next;
            check = false;
        }
        else{
            check = true;
        }
    }
    return slow;
}

int main(){
    Node* head = new Node(10);
    Node* tail = head;
    insertAtTail(tail, 20);
    insertAtTail(tail, 30);
    insertAtTail(tail, 40);
    insertAtTail(tail, 50);
    insertAtTail(tail, 60);
    cout << middleElement(head) -> data <<endl;
}