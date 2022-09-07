#include <iostream>
#include "linkedList.cpp"
using namespace std;

bool floydCycleDetection(Node* head){
    if(head == NULL){
        return false;
    }
    Node* fast = head;
    Node* slow = head;
    do{
        fast = fast -> next;
        if(fast != NULL){
            fast = fast -> next;
        }
        slow = slow -> next;
    }while(fast != NULL && fast != slow);

    if(fast == NULL){
        return false;
    }
    return true;
}

Node* floydCycleDetection2(Node* head){
    if(head == NULL){
        return NULL;
    }
    Node* fast = head;
    Node* slow = head;
    do{
        fast = fast -> next;
        if(fast != NULL){
            fast = fast -> next;
        }
        slow = slow -> next;
    }while(fast != NULL && fast != slow);
    
    return fast;
}

Node* getStartingOfLoop(Node* head){
    if(head == NULL){
        return NULL;
    }

    Node* fast = floydCycleDetection2(head);
    if(fast == NULL){
        return NULL;
    }
    Node* slow = head;
    while(fast != slow){
        fast = fast -> next;
        slow = slow -> next;
    }
    return fast;
}

void removeLoop(Node* head){
    Node* startOfLoop = getStartingOfLoop(head);
    if(startOfLoop == NULL){
        return ;
    }
    Node* node = startOfLoop;
    while(node -> next != startOfLoop){
        node = node -> next;
    }
    node -> next = NULL;
    
}

int main(){
    Node* head = new Node(10);
    Node* tail = head;
    insertAtTail(tail, 20);
    insertAtTail(tail, 30);
    insertAtTail(tail, 40);
    insertAtTail(tail, 50);
    insertAtTail(tail, 60);
    tail -> next = head -> next -> next -> next;
    removeLoop(head);
    cout << floydCycleDetection(head) << endl;

    return 0;
}