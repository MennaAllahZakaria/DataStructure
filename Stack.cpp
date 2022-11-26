#include <bits/stdc++.h> 

 

 using namespace std;

  


class Stack{


int *st;
int i=-1;
public:
 int sz;
Stack(){

    i =-1;
    cout<<"please enter the max size of the stack"<<"\n";
    cin >> sz;
    st = new int[sz];
}


//////////////////////////////////////////Functions Declaration\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

bool isEmpty();
bool isFull();
void clear();
void push(int val);
void pop();
int top();
int size();




};


/////////////////////////////////////////Functions Definition\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

// To cheak if the stack is empty or not


bool Stack::isEmpty(){
return i==-1;

}

//--------------------------------------------------------\\

//To check if the stack is full
bool Stack::isFull(){
    return i==sz-1;

}

//--------------------------------------------------------\\

// To clear the stack and remove all elements on it

void Stack::clear(){
  if (isEmpty()) return void ( cout<<"The Stack is already clear"<<"\n");
  while (!isEmpty() ) pop();
 
 cout<<"The Stack is clear now"<<"\n";

}

//--------------------------------------------------------\\

// To insert one element to the stack

void Stack::push(int val){
if ( isFull()){

int temp[sz*2];
for ( int idx=0;idx<sz;idx++)
temp[idx]=st[idx];

delete st;
st=temp;
sz*=2;
}
st[++i]=val;

}

//--------------------------------------------------------\\

// To remove one element from the sack
void Stack::pop(){
    if (isEmpty()) return void (cout<< "There are no elemants in the stack"<<"\n");
    st[i--]=0;

}

//--------------------------------------------------------\\

// To get the element which is in the top of stack

int Stack ::top(){
if (isEmpty()) {
    cout<<"There is no elemants in the stack"<<"\n";
    return -1;
}
return st[i];
}

//--------------------------------------------------------\\

// To get the size of the stack

int Stack::size(){
    return i+1;
}

//--------------------------------------------------------\\


int main(){

menna_allah();
Stack s;

s.push(5);
s.push(9);
s.push(11);
s.push(4);
s.push(6);
s.push(14);

s.pop();
cout<<s.top()<<"\n";

s.clear();


    return 0;
}
