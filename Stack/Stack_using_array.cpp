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
Stack(int n){

    i =-1;
   
     sz=n;
    st = new int[sz];
}

//--------------------------------Functions Declaration----------------------------------------------\\

bool isEmpty();
bool isFull();
void clear();
void push(int val);
void pop();
int top();
int size();
int search(int item);
bool isplindrom(string s);
void dec_to_bin(int dec);

};


//----------------------------------Functions Definition---------------------------------------------\\

// To cheak if the stack is empty or not


bool Stack::isEmpty(){
return i==-1;

}

//To check if the stack is full
bool Stack::isFull(){
    return i==sz-1;

}

// To clear the stack and remove all elements on it

void Stack::clear(){
  if (isEmpty()) return void ( cout<<"The Stack is already clear"<<"\n");
  while (!isEmpty() ) pop();
 
 cout<<"The Stack is clear now"<<"\n";

}

// To insert one element to the stack

void Stack::push(int val){
if ( isFull()){

int *temp=new int[sz*2];
for ( int idx=0;idx<sz;idx++)
temp[idx]=st[idx];

delete st;
st=temp;
sz*=2;
}
st[++i]=val;

}

// To remove one element from the stack
void Stack::pop(){
    if (isEmpty()) return void (cout<< "There are no elemants in the stack"<<"\n");
    st[i--]=0;

}

// To get the element which is in the top of stack

int Stack ::top(){
if (isEmpty()) {
    cout<<"There is no elemants in the stack"<<"\n";
    return -1;
}
return st[i];
}

// To get the size of the stack

int Stack::size(){
    return i+1;
}
 
// search for a given element on a stack and returns its position in relation with the top. 
int Stack:: search(int item){
 
for ( int j=i;j>=0;j--){
 if ( item ==st[j]) return i-j+1;
}
return -1;

}

//--------------------------------------------Important funcations using stack---------------------------------------------------\\

//check if the string is plindrom or not 
// MELILEM  plindrom    MELIM not plindrom


bool Stack::isplindrom(string s){

Stack x(s.size());
int j=0;
for ( ;j<s.size()/2;j++){
    x.push(s[j]);
}
if ( s.size()%2==1) j++;
for ( ;j<s.size();j++){
    if ( s[j]==x.top()) x.pop();
    else return 0;
}


return x.isEmpty();
}

void Stack::dec_to_bin(int dec){
 
 Stack x(1);
 while ( dec){
    x.push(dec%2);
    dec/=2;
 }
while ( !x.isEmpty()) {
    cout<<x.top();
    x.pop();
}
}

int main(){

Stack s;

cout<<(s.isplindrom("MklkM")?"plindrom":"not plindrom")<<"\n";
s.dec_to_bin(10);
  
    return 0;
}
