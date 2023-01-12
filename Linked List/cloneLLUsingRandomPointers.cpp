#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* random;

    Node(int data){
        this->data = data;
        this->next = NULL;
        this->random = NULL;
    }
};

void insertAtTail(Node* &tail, int d){
    Node* node = new Node(d);
    tail->next = node;
    tail = node;
}

void print(Node *head){
    Node* node = head;
    while(node != NULL){
        cout << "Data : " << node -> data << "\t" << "Random : " << node -> random -> data << endl;
        node = node -> next;
    }
}

Node* cloneList(Node* originalHead){
    if(originalHead == NULL){
        return NULL;
    }
    Node* originalNode = originalHead;
    Node* cloneHead = new Node(originalHead -> data);
    Node* cloneNode = cloneHead;
    map<Node*, Node*> mapping;
    mapping[originalHead] = cloneHead;
    while(originalNode -> next != NULL){
        Node* newNode = new Node(originalNode -> next -> data);
        cloneNode -> next = newNode;
        cloneNode = newNode;
        originalNode = originalNode -> next;
        mapping[originalNode] = cloneNode;
    }

    originalNode = originalHead;
    cloneNode = cloneHead;

    while(originalNode != NULL){
        mapping[originalNode] -> random = mapping[originalNode -> random];
        originalNode = originalNode -> next;
    }
    
    return cloneHead;
}

Node* cloneList2(Node* originalHead){
    if(originalHead == NULL){
        return NULL;
    }
    Node* originalNode = originalHead;
    Node* cloneHead = new Node(originalHead -> data);
    Node* cloneNode = cloneHead;

    while(originalNode -> next != NULL){
        Node* newNode = new Node(originalNode -> next -> data);
        cloneNode -> next = newNode;
        cloneNode = newNode;
        originalNode = originalNode -> next;
    }
    
    originalNode = originalHead;
    cloneNode = cloneHead;
    Node* node;

    while(originalNode != NULL && cloneNode != NULL){
        node = cloneNode -> next;
        cloneNode -> next = originalNode -> next;
        originalNode -> next = cloneNode;
        originalNode = cloneNode -> next;
        cloneNode = node;
    }

    node = originalHead;

    while(node != NULL){
        node -> next -> random = node -> random -> next;
        node = node -> next -> next;
    }

    originalNode = originalHead;

    while(originalNode != NULL){
        cloneNode = originalNode -> next;
        originalNode -> next = cloneNode -> next;
        originalNode = originalNode -> next;
        if(originalNode != NULL)
            cloneNode = originalNode -> next;
        cloneNode = cloneNode -> next; 
    }

    return cloneHead;
}

int main(){
    Node* head = new Node(10);
    Node* tail = head;
    insertAtTail(tail, 20);
    insertAtTail(tail, 30);
    insertAtTail(tail, 40);
    insertAtTail(tail, 50);
    head -> random = head -> next -> next;   // 10 -> 30
    head -> next -> random = head;      // 20 -> 10
    head -> next -> next -> random = head -> next -> next -> next -> next;     // 30 -> 50
    head -> next -> next -> next -> random = head -> next -> next;
    head -> next -> next -> next -> next -> random = head -> next;

    print(head);
    Node* cloneHead = cloneList2(head);
    cout << endl;
    print(cloneHead);

    return 0;
}