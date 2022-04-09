//https://www.geeksforgeeks.org/linked-list-set-3-deleting-node/

// Iterative Method:
// To delete a node from the linked list, we need to do the following steps. 
// 1) Find the previous node of the node to be deleted. 
// 2) Change the next of the previous node. 
// 3) Free memory for the node to be deleted.

#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
};

void push(Node** head_ref, int new_data){
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

void deleteNode(Node** head_ref, int key)
{
    Node* temp = *head_ref;
    Node* prev = NULL;
    
    if(temp != NULL && temp->data == key)
    {
        *head_ref = temp->next;
        delete temp;
        return;
    }else{
        while(temp != NULL && temp->data != key)
        {
            prev= temp;
            temp = temp->next;
        }
        
        if(temp == NULL)
            return;
        
        prev->next = temp->next;
        delete temp;
    }
}

void printList(Node* node){
    while(node != NULL){
        cout<< node->data<< " ";
        node = node->next;
    }
}

int main()
{
    Node* head = NULL;
    
    push(&head, 7);
    push(&head, 1);
    push(&head, 3);
    push(&head, 2);
    
    printList(head);
    
    deleteNode(&head, 1);
    
    cout<< endl;
    printList(head);
}

