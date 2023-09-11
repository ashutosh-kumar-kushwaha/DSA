#include <iostream>
#include "linkedList.cpp"
using namespace std;

Node* middleElement(Node* head){
    Node* fast = head;
    Node* slow = head;
    while(fast != NULL && fast -> next != NULL){
        fast = fast -> next -> next;
        slow = slow -> next;
    }
    return slow;
}

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

Node* mergeSort(Node* head){
    if(head == NULL || head -> next == NULL){
        return head;
    }
    Node* mid = middleElement(head);
    Node* left = head;
    Node* right = mid -> next;
    mid -> next = NULL;
    left = mergeSort(left);
    right = mergeSort(right);
    Node* result = merge(left, right);
    return result;
}

int main(){
    Node* head = new Node(10);
    Node* tail = head;
    insertAtTail(tail, 40);
    insertAtTail(tail, 30);
    insertAtTail(tail, 60);
    insertAtTail(tail, 50);
    insertAtTail(tail, 20);
    print(head);
    mergeSort(head);
    print(head);

    return 0;
}