//https://www.geeksforgeeks.org/delete-a-linked-list-node-at-a-given-position/

//Delete a Linked List node at a given position

#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
};

void push(Node** head_ref, int data){
    Node* new_node = new Node();
    new_node->data = data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

void deleteNode(Node** head, int position)
{
    if(*head == NULL)
        return;
    
    Node* temp = *head;
    if(position == 0){
        *head = temp->next;
        delete temp;
        return;
    }
    
    for(int i =0; temp != NULL && i <position -1; i++)
        temp = temp->next;
    
    if(temp == NULL || temp->next == NULL)
        return;
    
    Node* next = temp->next->next;
    delete temp->next;
    
    temp->next = next;
}

void print(Node* node){
    while(node != NULL)
    {
        cout << node->data << " " ;
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
    push(&head, 8);
    
    print(head);
    cout << endl;
    deleteNode(&head, 3);
    print(head);
    return 0;
}
