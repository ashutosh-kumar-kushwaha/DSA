#include <iostream>
#include <vector>
#include "linkedList.cpp"
using namespace std;


// ---------------------------------------------Approach 1-----------------------------------------------------------------

bool isPalindrome(vector<int> v){
    int start = 0;
    int end = v.size()-1;
    while(start <= end){
        if(v[start++] != v[end--]){
            return false;
        }
    }
    return true;
}

bool isPalindrome(Node* head){
    vector<int> v;
    Node* node = head;
    while(node != NULL){
        v.push_back(node -> data);
        node = node -> next;
    }
    return isPalindrome(v);
}
//----------------------------------------------------------------------------------------------------------------------------

//--------------------------------------------------Approach 2----------------------------------------------------------------

Node* middleElement(Node* head){
    bool check = false;
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

Node* reverse(Node* head){
    if(head -> next == NULL){
        return head;
    }
    Node* prev = NULL;
    Node* curr = head;
    Node* forward;
    while(curr != NULL){
        forward = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = forward;
        if(forward!=NULL)
            forward = forward -> next;
    }
    return prev;
}

bool isPalindrome2(Node* head){
    if(head -> next == NULL){
        return true;
    }
    Node* middle = middleElement(head);
    middle -> next = reverse(middle -> next);
    Node* node1 = head;
    Node* node2 = middle -> next;
    while(node2 != NULL){
        if(node1 -> data != node2 -> data){
            return false;
        }
        node2 = node2 -> next;
        node1 = node1 -> next;
    }
    return true;
}

//----------------------------------------------------------------------------------------------------------------------------

int main(){
    Node* head = new Node(10);
    Node* tail = head;
    insertAtTail(tail, 20);
    insertAtTail(tail, 30);
    insertAtTail(tail, 40);
    insertAtTail(tail, 30);
    insertAtTail(tail, 20);
    insertAtTail(tail, 10);

    cout << isPalindrome2(head) << endl;

    return 0;
}