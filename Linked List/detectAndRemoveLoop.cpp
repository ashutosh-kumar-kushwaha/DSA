#include <iostream>
#include <map>
#include "linkedList.cpp"
using namespace std;

// Node* detectLoop(Node* head)
// {
//     map<Node *, bool> mp;
//     Node *node = head;
//     while (node != NULL && mp[node] == false)
//     {
//         mp[node] = true;
//         node = node -> next;
//     }
//     return node;
// }

// void removeLoop(Node* head)
// {
//     Node *nodeWhereCycleStarted = detectLoop(head);
//     if (nodeWhereCycleStarted != NULL)
//     {
//         Node *node = nodeWhereCycleStarted->next;
//         while (node -> next != nodeWhereCycleStarted)
//         {
//             node = node -> next;
//         }
//         node -> next = NULL;
//     }
// }

Node* removeLoop(Node *head)
{
    map<Node*, bool> mp;
    Node* node = head;
    mp[node] = true;
    while (node->next != NULL && mp[node->next] == false)
    {
        mp[node] = true;
        node = node->next;
    }
    node->next = NULL;
    return head;
}