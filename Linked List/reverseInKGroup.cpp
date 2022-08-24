#include <iostream>
#include "linkedList.cpp"
using namespace std;

// ---------------- Approach 1 ------------------------------------------------

int length(Node* head){
    int cnt = 0;
    while(head != NULL){
        cnt++;
        head = head -> next;
    }
    return cnt;
}

void kReverse(Node* head, int k){
    Node* arr[k];
    Node* node = head;
    int n = length(head);
    for(int j = 0; j < n/k; j++){
        for(int i = 0; i < k; i++){
            arr[i] = node;
            node = node -> next;
        }

        int x;
        for(int i = 0; i < k/2; i++){
            x = arr[i] -> data;
            arr[i] -> data = arr[k-i-1] -> data;
            arr[k-i-1] -> data = x;
        }
    }
    if(n%k != 0){
        Node* remaining[n%k];
        for(int i = 0; i < n%k; i++){
            remaining[i] = node;
            node = node -> next;
        }
        int x;
        for(int i = 0; i < (n%k)/2; i++){
            x = remaining[i] -> data;
            remaining[i] -> data = remaining[n%k-i-1] -> data;
            remaining[n%k-i-1] -> data = x;
        }
    }
}

// --------------------------------------------------------------------------


// --------------------------- Approach 2 --------------------------------------

Node* kReverse2(Node* head, int k){
    // if(head == NULL){
    //     return NULL;
    // }
    Node* prev = NULL;
    Node* curr = head;
    Node* forward = NULL;
    int cnt = 0;
    while(cnt < k && curr != NULL){
        forward = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = forward;
        cnt++;
    }
    if(forward!=NULL)
    head -> next = kReverse2(forward, k);

    return prev;
}

// --------------------------------------------------------------------------------

int main(){
    Node* head = new Node(10);
    Node* tail = head;
    insertAtTail(tail, 20);
    insertAtTail(tail, 30);
    insertAtTail(tail, 40);
    insertAtTail(tail, 50);
    insertAtTail(tail, 60);
    insertAtTail(tail, 70);
    insertAtTail(tail, 80);
    insertAtTail(tail, 90);
    // kReverse(head, 4);
    head = kReverse2(head,5);
    print(head);
}