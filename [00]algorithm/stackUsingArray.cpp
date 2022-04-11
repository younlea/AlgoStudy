//https://www.geeksforgeeks.org/stack-data-structure-introduction-program/

//stack using array

#include <bits/stdc++.h>

using namespace std;
#define MAX 1000

class Stack{
    int top;
    
    public:
    int a[MAX];
    
    Stack(){top = -1;}
    bool push(int x)
    {
        if(top >= (MAX -1)){
            cout <<"stack overflow";
            return false;
        }else{
            a[++top] = x;
            cout<<x<<"push into stack\n"; 
        }
    }
    
    int pop()
    {
        if(top < 0){
            cout<<"stack underflow";
            return 0;
        }else{
            int x = a[top--];
            return x;
        }
    }
    
    int peek(){
        if(top < 0){
            cout <<"stack is empty";
            return 0;
        }else{
            int x = a[top];
            return x;
        }
    }
    
    bool isEmpty(){
        return (top < 0);
    }
};

int main(){
    class Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout << s.pop() << "popped form stack\n";
    
    cout<<"Elements present in stack : ";
    while(!s.isEmpty()){
        cout<< s.peek() <<" ";
        s.pop();
    }
    
    return 0;
}