#include <iostream>
#include "linkedList.cpp"
using namespace std;

Node* reverse(Node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    Node* prev = NULL;
    Node* curr = head;
    Node* forward = head;
    while(forward != NULL){
        forward = forward->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
}

// void insertAtTail(Node* &tail, int d){
//     Node* node = new Node(d);
//     tail->next = node;
//     tail = node;
// }

Node* add(Node* first, Node* second){

    first = reverse(first);
    second = reverse(second);

    Node* node1 = first;
    Node* node2 = second;

    int sum;
    int carry = 0;
    Node* dummy = new Node(-1);
    Node* tail = dummy;
    int val1, val2;

    while(node1 != NULL || node2 != NULL || carry != 0){
        val1 = 0;
        if(node1 != NULL){
            val1 = node1 -> data;
        }

        val2 = 0;
        if(node2 != NULL){
            val2 = node2 -> data;
        }

        sum = val1 + val2 + carry;
        insertAtTail(tail, sum % 10);
        carry = sum/10;

        if(node1 != NULL){
            node1 = node1 -> next;
        }
        
        if(node2 != NULL){
            node2 = node2 -> next;
        }
    }

    Node* head = dummy -> next;

    head = reverse(head);

    return head;
}

int main(){
    Node* head1 = new Node(2);
    Node* tail1 = head1;
    insertAtTail(tail1, 4);
    insertAtTail(tail1, 3);

    Node* head2 = new Node(5);
    Node* tail2 = head2;
    insertAtTail(tail2, 6);
    insertAtTail(tail2, 4);
    print(add(head1, head2));
}