#include <iostream>
#include <map>
#include "linkedList.cpp"
using namespace std;

void removeDuplicates1(Node* head){
    Node* node1 = head;
    Node* node2;
    while(node1 != NULL){
        node2 = node1;
        while(node2 -> next != NULL){
            if(node2 -> next -> data == node1 -> data){
                node2 -> next = node2 -> next -> next;
            }
            else{
                node2 = node2 -> next;
            }
        }
        node1 = node1 -> next;
    }
}

void removeDuplicates3(Node* head){
    map<int,bool> visited;
    Node* node = head;
    visited[node -> data] = true;
    while(node -> next != NULL){
        if(visited[node -> next -> data]){
            node -> next = node -> next -> next;
        }
        else{
            visited[node -> next -> data] = true;
            node = node -> next;
        }
    }
}

int main(){
    Node* head = new Node(10);
    Node* tail = head;
    insertAtTail(tail, 40);
    insertAtTail(tail, 30);
    insertAtTail(tail, 10);
    insertAtTail(tail, 20);
    insertAtTail(tail, 40);
    insertAtTail(tail, 20);
    insertAtTail(tail, 30);
    insertAtTail(tail, 30);
    insertAtTail(tail, 40);
    insertAtTail(tail, 10);
    print(head);
    removeDuplicates3(head);
    print(head);
}