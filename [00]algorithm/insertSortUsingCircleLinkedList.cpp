// https://www.geeksforgeeks.org/sorted-insert-for-circular-linked-list/

// 1) Linked List is empty:  
//     a)  since new_node is the only node in CLL, make a self loop.      
//           new_node->next = new_node;  
//     b) change the head pointer to point to new node.
//           *head_ref = new_node;
// 2) New node is to be inserted just before the head node:    
//   (a) Find out the last node using a loop.
//          while(current->next != *head_ref)
//             current = current->next;
//   (b) Change the next of last node. 
//          current->next = new_node;
//   (c) Change next of new node to point to head.
//          new_node->next = *head_ref;
//   (d) change the head pointer to point to new node.
//          *head_ref = new_node;
// 3) New node is to be  inserted somewhere after the head: 
//   (a) Locate the node after which new node is to be inserted.
//          while ( current->next!= *head_ref && 
//              current->next->data < new_node->data)
//          {   current = current->next;   }
//   (b) Make next of new_node as next of the located pointer
//          new_node->next = current->next;
//   (c) Change the next of the located pointer
//          current->next = new_node;

#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
};

//this is circuler linked list... 
void sortedInsert(Node** head, Node* new_node)
{
    Node* current = *head;
    
    //case1 (make new linked list)
    if(current == NULL){
        new_node->next = new_node;
        *head = new_node;
    }
    
    //case2 (insert front head)
    else if(current->data >= new_node->data){
        while(current->next != *head)
            current= current->next;
        current->next = new_node;
        new_node->next = *head;
        *head = new_node;
    }
    //case3 (insert after node)
    else{
        while(current->next != *head && current->next->data < new_node->data)
            current = current->next;
        new_node->next = current->next;
        current->next = new_node;
    }
}

void printL(Node* start){
    Node *temp;
    
    if(start != NULL)
    {
        temp = start;
        do{
            cout << temp->data << " ";
            temp = temp->next;
        }while(temp != start);
    }
}

int main()
{
    int arr[] = {12, 56, 2, 11, 1, 90};
    int list_size, i;
    
    Node* start = NULL;
    Node* temp;
    
    for(i =0; i < 6; i++)
    {
        temp = new Node();
        temp->data = arr[i];
        sortedInsert(&start, temp);
    }
    
    printL(start);
    return 0;
}