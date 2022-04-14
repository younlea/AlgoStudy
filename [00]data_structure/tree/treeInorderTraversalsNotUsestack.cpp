// https://www.geeksforgeeks.org/inorder-tree-traversal-without-recursion-and-without-stack/

// 1. Initialize current as root 
// 2. While current is not NULL
//   If the current does not have left child
//       a) Print current’s data
//       b) Go to the right, i.e., current = current->right
//   Else
//       a) Find rightmost node in current left subtree OR
//               node whose right child == current.
//          If we found right child == current
//              a) Update the right child as NULL of that node whose right child is current
//              b) Print current’s data
//              c) Go to the right, i.e. current = current->right
//          Else
//              a) Make current as the right child of that rightmost 
//                 node we found; and 
//              b) Go to this left child, i.e., current = current->left

//Using Morris Traversa

#include <iostream>
using namespace std;

struct tNode{
    int data;
    struct tNode* left;
    struct tNode* right;
};

void MorrisTraversal(struct tNode* root)
{
    struct tNode* current, *pre;
    
    if(root == NULL)
        return;
        
    current = root;
    while(current != NULL){
        if(current->left == NULL){
            cout <<"1 " << current->data << " " <<endl;
            current = current->right;
        }else{
            pre = current->left;
            while(pre->right != NULL && pre->right!=current)
                pre= pre->right;
            
            if(pre->right == NULL){
                pre->right = current;
                current = current->left;
            }else{
                pre->right = NULL;
                cout <<"2 " << current->data <<" " <<endl;
                current=current->right;
            }
        }
    }
}

struct tNode* newtNode(int data){
    struct tNode* node = new tNode;
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    
    return node;
}

int main(){
    struct tNode* root = newtNode(1);
    root->left = newtNode(2);
    root->right = newtNode(3);
    root->left->left = newtNode(4);
    root->left->right = newtNode(5);
  
    MorrisTraversal(root);
  
    return 0;
}