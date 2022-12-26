#include <bits/stdc++.h> 

 #define ll long long 
 #define nl "\n"

 using namespace std;


   class Node{
    public:
    int data;
    Node* next;
 
   };

   class Queue {
 private:
     Node *head;
     Node *tail;
     int sz;
 public:

 // constructor
Queue(){
    head=tail=NULL;
    sz=0;
}
//-----------------------------Functions Declaration-------------------------\\

    bool isEmpty();
    void enqueue(int val);
    void dequeue();
    int peek();
    int size();
    int search(int target);
   };
//----------------------------Functions Definition-----------------------------\\

// To check if the queue is empty or not

  bool Queue::isEmpty(){ // o(1)
    return head==NULL;
  }

//----------------------------------------------------------------------------------\\
// To insert one element to the queue

void Queue::enqueue(int val){ // o(1)
      Node * temp = new Node();
     temp->data=val;
     sz++;
    if (isEmpty()){
        head=tail=temp;
        return;
    }
    tail->next=temp;
    tail=temp;
}

//-------------------------------------------------------------------------------------\\

// To remove one element from the queue

void Queue::dequeue(){ //o(1)
     if ( isEmpty())   
      return void (cout<< "No elemants in the Queue"<<nl);
      sz--;

      if ( head->next==NULL) {
        head=tail=NULL;
        return;
      }

      head=head->next;
}
//-------------------------------------------------------------------------------------\\

// To return the first element in the queue
// if it's return -2147483648 that is mean no elements in the queue

int Queue ::peek(){ // o(1)
    if (isEmpty()) {
      cout<<"There are no element in Queue now "<<nl;
       return INT_MIN;
  } 
        return  head->data;
}
//----------------------------------------------------------------------------------\\

// To return the size of the queue

int Queue::size(){ // o(1)
    return sz;

}

//----------------------------------------------------------------------------------\\

// search in the queue if the target in the queue return it's index if not return -1

int Queue::search(int item){ // o(n)
    int x=1;
    Node *p=head;
    while ( p!=NULL) {
        if ( p->data==item) return x;
        p=p->next;
        x++;

    }
    return -1;
}

int main(){

    return 0;
}
