#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

void insertAtTail(Node* &tail, int d){
    Node* node = new Node(d);
    tail->next = node;
    tail = node;
}

void insertAtHead(Node* &head, int d){
    Node* node = new Node(d);
    node->next = head;
    head = node;
}

void print(Node* &head){
    Node* node = head;
    while(node != NULL){
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

void insertAtPosition(Node* &head, Node* &tail, int position, int d){
    if(position==1){
        insertAtHead(head,d);
        return ;
    }
    Node* node = head;
    int count = 1;
    while(count < position-1){
        node = node->next;
        count++;
    }
    
    if(node->next == NULL){
        insertAtTail(tail, d);
        return ;
    }

    Node* nodeToInsert = new Node(d);
    nodeToInsert->next = node->next;
    node->next = nodeToInsert;
}

void deleteNode(Node* &head, Node* &tail, int position){
    if(position == 1){
        Node* node = head;
        head = head -> next;
        node -> next = NULL;
        delete node;
        return ;
    }
    
    Node* node = head;
    int count = 1;
    while(count < position-1){
        node = node -> next;
        count++;
    }

    Node* nodeToBeDeleted = node->next;

    if(nodeToBeDeleted -> next == NULL){
        tail = node;
    }

    
    node->next = nodeToBeDeleted->next;
    nodeToBeDeleted-> next = NULL;
    delete nodeToBeDeleted;
}