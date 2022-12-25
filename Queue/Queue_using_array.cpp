
#include <bits/stdc++.h> 

 #define ll long long 
 #define nl "\n"

 using namespace std;




class Queue
{
    int *arr;       
    int capacity;   
    int front;      
    int rear;       
    int current_size;      

public:
///////////////////////////Functions Declaration\\\\\\\\\\\\\\\\\\\\\\\\\\\
   // constructor
    Queue();

    // destructor    
    ~Queue();               

    void dequeue();
    void enqueue(int x);
    int peek();
    int size();
    int max_size();
    bool isEmpty();
    bool isFull();
    int search(int target);
};

/////////////////////////Functions Definition\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
 // constructor
Queue::Queue(){
      cout<<"please enter the max size of the queue"<<nl;
     cin>>capacity;
     arr=new int [capacity];
     current_size=0;
     front=0;
     rear=-1;


}
//------------------------------------------------\\
// destructor    

Queue::~Queue(){
   delete [] arr;

}

//-------------------------------------------\\
//To check if the queue id empty or not

bool Queue::isEmpty(){
    return current_size==0;
}

//--------------------------------------------\\
// To check the queue if full or not
bool Queue::isFull(){
return current_size==capacity;
}


//--------------------------------------------\\
// To delete the first element in the queue

void Queue ::dequeue(){
if (isEmpty()) return void ( cout<<"There are no element in Queue now "<<nl);

front = (front+1) %capacity;
current_size--;


}

//--------------------------------------------\\
// To add one element to the end of the queue


void Queue ::enqueue(int x){
if ( isFull()) return void ( cout<<"The Queue is full "<<nl);
rear = (rear + 1) % capacity;
    arr[rear] = x;
   current_size++;
}

//--------------------------------------------\\
// To return the size of the queue


int Queue::size(){
    return current_size;
}

//--------------------------------------------\\
// To return the maximum size of the queue


int Queue::max_size(){
    return capacity;
}

//--------------------------------------------\\
// To return the first element in the queue


int Queue::peek(){
  if (isEmpty()) {
 cout<<"There are no element in Queue now "<<nl;
 return INT_MIN;
  } 
return arr[front];
}


//--------------------------------------------\\
// search in the queue if the target in the queue return it's index if not return -1 
int Queue::search(int target){

  for ( int i=0;i<capacity;i++){
    if ( arr[i]==target) return i;
  }
return -1;
}
int main(){


Queue q;
q.enqueue(15);
q.dequeue();
 q.enqueue(6);
cout<<q.search(5);
cout<<"the max size of queue is = "<<q.max_size();
cout<<"the current size of queue is = "<<q.size();

cout<<"The first element in the queue is = "<<q.peek(); 

return 0;

}
