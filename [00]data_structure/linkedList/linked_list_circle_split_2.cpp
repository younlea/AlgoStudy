//https://www.geeksforgeeks.org/split-a-circular-linked-list-into-two-halves/

#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
};

void splitList(Node* head, Node** head1_ref, Node** head2_ref){
    if(head == NULL) return;
    
    Node* slow_ptr = head;
    Node* fast_ptr = head;
    //find mid point;
    while(fast_ptr->next != head && 
        fast_ptr->next->next != head){
            fast_ptr = fast_ptr->next->next;
            slow_ptr = slow_ptr->next;
        }
    /* If there are even elements in list
       then move fast_ptr */    
    if(fast_ptr->next->next == head)
        fast_ptr = fast_ptr->next;
    
    //set the head pointer of first half
    *head1_ref = head;
    
    //set the head pointer of second half
    if(head->next != head)
        *head2_ref = slow_ptr->next;
    //make second half cirtcular    
    fast_ptr->next = slow_ptr->next;
    
    //make first half circular  //요게 맨 뒤로 와야함. 
    slow_ptr->next = head;
}

//circular linked list
void push(Node** head, int data){
    Node* ptr = new Node();
    ptr->data = data;
    ptr->next = *head;
    
    Node* temp = *head;
    
    if(*head != NULL){
        while(temp->next != *head)
            temp= temp->next;
        temp->next = ptr;
    }else
        ptr->next = ptr;
        
    *head = ptr;
}

void printL(Node *head){
    Node *temp = head;
    if(head != NULL)
    {
        do{
            cout<< temp->data <<" ";
            temp = temp->next;
        }while(temp != head);
    }
    
    cout<<endl;
}

int main(){
    int list_size, i;
    
    Node *head = NULL;
    Node *head1 = NULL;
    Node *head2 = NULL;
    
    push(&head, 12);
    push(&head, 56);
    push(&head, 2);
    push(&head, 11);
    
    printL(head);
    
    splitList(head, &head1, &head2);
    printL(head1);
    printL(head2);
}