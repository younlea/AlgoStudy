//https://www.geeksforgeeks.org/circular-linked-list-set-2-traversal/

//circular linked list circular-linked-list-set-2-traversal

#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
};

void push(Node** head, int data){
    Node* ptr = new Node();
    ptr->data = data;
    ptr->next = *head;
    
    Node* temp = *head;
    
    if(*head != NULL)
    {
        while(temp->next != *head)
            temp= temp->next;
        temp->next = ptr;
    }else
        ptr->next = ptr;
        
    *head = ptr;
}

void printL(Node* head){
    Node* temp = head;
    if(head != NULL)
    {
        do{
            cout<<temp->data<<" ";
            temp = temp->next;
        }while(temp != head);
    }
}

int main(){
    Node* head = NULL;
    
    push(&head, 12);
    push(&head, 56);
    push(&head, 2);
    push(&head, 11);
    
    printL(head);
    
    return 0;
}