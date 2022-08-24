#include <iostream>
#include "linkedList.cpp"
#include <map>
using namespace std;

bool detectLoop(Node* head){
    map<Node*,bool> mp;
    Node* node = head;
    while(node != NULL && mp[node] == false){
        mp[node] = true;
        node = node -> next;
    }

    if( node == NULL ){
        return false;
    }
    else{
        return true;
    }
}

int main(){
    Node* head = new Node(10);
    Node* tail = head;
    insertAtTail(tail, 20);
    insertAtTail(tail, 30);
    insertAtTail(tail, 40);
    insertAtTail(tail, 50);
    insertAtTail(tail, 60);
    cout << detectLoop(head) << endl;

    return 0;
}