// https://www.geeksforgeeks.org/linked-list-set-2-inserting-a-node/

#include <iostream>
using namespace std;
class Node
{
    public:
    int data;
    Node *next;
};

//push front,
void push(Node **head_ref, int new_data)
{
    Node * new_node = new Node();
    new_node->data = new_data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

void insertAfter(Node* prev_node, int new_data)
{
    if(prev_node == NULL){
        cout << "the given previous node cannnot be NULL";
        return;
    }
    
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}
//append to end list
void append(Node** head_ref, int new_data)
{
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = NULL;
    
    Node *last = *head_ref;
    if(*head_ref == NULL){
        *head_ref = new_node;
        return;
    }
    
    while(last->next !=NULL)
    {
        last = last->next;
    }
    
    last->next = new_node;
    return;
    
}

void printList(Node *node)
{
    while(node != NULL)
    {
        cout << " "<<node->data;
        node = node->next;
    }
}

int main() {
	Node* head = NULL;
	append(&head, 6);
	push(&head, 7);
	push(&head, 1);
	append(&head, 4);
	insertAfter(head->next, 8);
	
	printList(head);
	return 0;
}