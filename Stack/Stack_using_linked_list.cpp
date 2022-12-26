#include <bits/stdc++.h> 

 #define ll long long 
 #define nl "\n"

 using namespace std;


   class Node{
    public:
    int data;
    Node* next;
 
   };

class Stack{
Node *head;
Node *tail;
int sz;
public:

Stack(){
    head=NULL;
    tail=NULL;
    sz=0;
}
//-----------------------------Functions Declaration-------------------------\\

bool isEmpty();
void clear();
void push(int val);
void pop();
int top();
int size();
int search(int item);

};
//----------------------------Functions Definition---------------------------\\

// To check if the stack is empty or not


bool Stack::isEmpty(){
    return head==NULL;
}
//-------------------------------------------------------------------------------------\\

// To clear the stack and remove all elements on it

void Stack::clear(){ //o(n)
    if ( isEmpty()) return void ( cout<<"No elemants in the stack to clear"<<nl);
    while ( head!=NULL) head=head->next;
    sz=0;
 }
//-------------------------------------------------------------------------------------\\

// To insert one element to the stack

void Stack::push(int val){ //o(1)
     Node * temp = new Node();
     temp->data=val;
     sz++;
    if ( isEmpty()) {
        head=tail=temp;
        return;
    }

tail->next=temp;
tail=temp;


}

//-------------------------------------------------------------------------------------\\

// To remove one element from the stack

void Stack::pop(){  // o(n)
     if ( isEmpty())   
      return void (cout<< "No elemants in the stack"<<nl);
      sz--;
    
     if ( head->next==NULL) {
        head=NULL;
        tail=NULL;
        return;
     }
    Node * p=head;
      while ( p->next->next!=NULL)
                        p=p->next;
    
    tail = p;
    p->next=NULL;
    
}
//-------------------------------------------------------------------------------------\\

// To get the element which is in the top of stack
// if it's return -2147483648 that is mean no elements in the stack

int Stack::top(){ // o(1)
    return (isEmpty()?INT_MIN:tail->data);
}

//-------------------------------------------------------------------------------------\\

// To get the size of the stack

int Stack::size(){  // o(1)
    return sz;
}

//-------------------------------------------------------------------------------------\\

// search for a given element on a stack and returns its position in relation with the top. 

int Stack::search(int item){ // o(n)
    int x=size();
    Node *p=head;
    while ( p!=NULL) {
        if ( p->data==item) return x;
        p=p->next;
        x--;

    }
    return -1;
}
//-------------------------------------------------------------------------------------\\

int main(){

    return 0;
}
