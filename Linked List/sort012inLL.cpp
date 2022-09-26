#include <iostream>
#include "linkedList.cpp"
using namespace std;

void sort1(Node* head){
    int count[3] = {0,0,0};
    Node* node = head;
    while(node != NULL){
        count[node -> data]++;
        node = node -> next;
    }

    node = head;
    for(int value = 0; value <= 2; value++){
        while(count[value]--){
            node -> data = value;
            node = node -> next;
        }
    }
}

void insertAtTail(Node* &tail, Node* node){
    tail -> next = node;
    tail = node;
}

void sort2(Node* &head){
    Node* zeroHead = new Node(-1);
    Node* zeroTail = zeroHead;
    Node* oneHead = new Node(-1);
    Node* oneTail = oneHead;
    Node* twoHead = new Node(-1);
    Node* twoTail = twoHead;
    
    Node* node = head;
    
    while(node != NULL){
        if(node -> data == 0){
            insertAtTail(zeroTail, node);
        }
        else if(node -> data == 1){
            insertAtTail(oneTail, node);
        }
        else if(node -> data == 2){
            insertAtTail(twoTail, node);
        }
        node = node -> next;
    }

    zeroTail -> next = NULL;
    oneTail -> next = NULL;
    twoTail -> next = NULL;

    if(zeroHead -> next != NULL){
        head = zeroHead -> next;
        if(oneHead -> next != NULL){
            zeroTail -> next = oneHead -> next;
            oneTail -> next = twoHead -> next;
        }
        else{
            zeroTail -> next = twoHead -> next;
        }
    }
    else if(oneHead -> next != NULL){
        head = oneHead -> next;
        oneTail -> next = twoHead -> next;
    }
    else{
        head = twoHead -> next;
    } 
}

int main(){
    Node* head = new Node(1);
    Node* tail = head;
    insertAtTail(tail, 0);
    insertAtTail(tail, 1);
    insertAtTail(tail, 2);
    insertAtTail(tail, 1);
    insertAtTail(tail, 0);
    print(head);
    sort2(head);
    print(head);

    return 0;
}