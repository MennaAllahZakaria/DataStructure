
#include <bits/stdc++.h> 

 #define ll long long 
 #define nl "\n"

 using namespace std;




 class Node{
    public:
int data;
Node* next;
Node* prev;


 };


class List{
Node* head;
public:
 List(){

        head = NULL;
    }

     //Destructor
    ~List(){


       Node *p = head;

        while(p!=NULL)
        {

            p=head->next;
            delete head;
            head=p;
        }
    }
//////////////////////////////////////////functions\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\        

 bool isEmpty();
 void print();
  void rev_print();


 void insert_to_head(int data);
 void insert_to_tail(int data);
 void insert_to_possion(int poss,int data);
void insert_befor(int val,int data);

 void search(int target);
 int searchPoss(int target);

 int size();

 void del_from_head();
 void del_from_tail();
 void del_poss(int poss);

 int get_min();
 int get_max();

 int sum_odd();
 int sum_even();

 void copy_list(List* l2);

 void update(int poss,int data);
 void DelAfter(int value);



};
// To cheak if the list is empty or not

bool List::isEmpty(){
return head==NULL;
}

//----------------------------------------------------------------\\
// To print all elements in the list

void List::print(){

if ( isEmpty()) return void ( cout<<"No Elements in that List");
 Node* p=head;
int x=0;

 while ( p->next!=NULL) {
     cout<<p->data<<" ";
   p=p->next;
   if ( x++==20) return;

 }
   cout<<p->data<<nl;

}

//----------------------------------------------------------------\\
// To print all elements in the list in reverse order

void List::rev_print(){
if ( isEmpty()) return void ( cout<<"No Elements in that List");
Node* p=head;

while ( p->next!=NULL){

    p=p->next;
}
while ( p->prev!=NULL){
    cout <<p->data<<" ";
    p=p->prev;
}

cout<<p->data<<nl;
}

//----------------------------------------------------------------\\
// return size of list 

int List ::size(){
if ( isEmpty()) return 0;
Node* p=head;
    int l=1;
while ( p->next!=NULL) {
l++;
    p=p->next;

}
return l;
}

//----------------------------------------------------------------\\
//To insert element in the beginning of the list 

void List ::insert_to_head(int data){


Node* p=new Node;
p->data=data;
p->prev=NULL;
if ( !isEmpty()) head->prev=p;
p->next=head;
head=p;

}

//----------------------------------------------------------------\\
//To insert element in the end of the list

void List ::insert_to_tail(int data){

Node* p=new Node;
p->data=data;
p->next=NULL;
if ( isEmpty()){

    p->prev=NULL;
    head=p;
    return;
}
Node* q=head;
while ( q->next!=NULL){
    q=q->next;
}
q->next=p;
p->prev=q;

}

//----------------------------------------------------------------\\
//To insert element in possition (poss) 

void List::insert_to_possion(int poss ,int data){
    if (poss<1 || poss>size()) return void ( cout<<"Unvalid input");
    Node* p=new Node;
p->data=data;
p->next=NULL;
if ( poss==1){

    p->prev=NULL;
    head=p;
    return;
}

int l=1;
Node* q=head;
    while (q->next!=NULL){
  l++;
  if ( l==poss){

p->next=q->next;
p->prev=q;
q->next->prev=p;
q->next=p;

  return;
  }

q=q->next;


    }
}

//----------------------------------------------------------------\\
//To check if the element in the list or not 

void List ::search(int target){

if ( isEmpty()) return void ( cout<<"No Elements in that List");
Node* p=head;

while ( p->next!=NULL){
 if (p->data==target ) return void ( cout<<"FOUND"<<nl);
    p=p->next;
}
cout <<"NOT FOUND"<<nl;


}

//----------------------------------------------------------------\\
//To check if the element in the list and return it's posation 
// if element not found if list return -1

int List ::searchPoss(int target ){
if ( isEmpty()) return -1;
Node* p=head;

int l=1;
while ( p->next!=NULL){

 if (p->data==target ) return l;
    p=p->next;
      l++;
}

return -1;


}

//----------------------------------------------------------------\\
// To remove one element from the beginning of list

void List::del_from_head(){
if ( isEmpty()) return void ( cout<<"No Elements in that List");
head->next->prev=NULL;
head=head->next;




}

//----------------------------------------------------------------\\
 
 // To remove one element from the end of list

 void List::del_from_tail(){

if ( isEmpty()) return void ( cout<<"No Elements in that List"<<nl);
if ( head->next==NULL) {
    delete(head);
    return;
}
Node* p=head;
while ( p->next->next!=NULL){
p=p->next;
}
p->next=p->next->next;

 }

//----------------------------------------------------------------\\
// To remove element in position (poss)


void List::del_poss(int poss){
if ( isEmpty())  return void ( cout<<"No Elements in that List"<<nl);
if ( poss<1 || poss>size()) return void ( cout<<"this poss is invalid"<<nl);
if ( poss==1)  return void ( del_from_head());
if ( poss==size()) return void ( del_from_tail());
int l=1;
Node* p=head->next;
while ( p!=NULL){
l++;
if ( l==poss) {

p->prev->next=p->next;
p->next->prev=p->prev;
return;

}
p=p->next;


}


}

//----------------------------------------------------------------\\
//To get the minimum element 


int List::get_min(){
int mn=INT_MAX;
Node* p=head;
if ( isEmpty()) return 0;

while ( p!=NULL){
  mn=min(mn,p->data);
  p=p->next;
}
return mn;

}

//----------------------------------------------------------------\\
//To get the maximum element 

int List::get_max(){
int mx=INT_MIN;
Node* p=head;
if ( isEmpty()) return 0;

while ( p!=NULL){
  mx=max(mx,p->data);
  p=p->next;
}
return mx;

}

//----------------------------------------------------------------\\
//To get sum of all odd elements in the list

int List::sum_odd(){
  int sum=0;
  Node* p=head;
  if ( isEmpty()) return 0;
  while ( p!=NULL){
if ( p->data&1) sum+=p->data;
p=p->next;
  }
  return sum;
}

//----------------------------------------------------------------\\
//To get sum of all even elements in the list

int List::sum_even(){
  int sum=0;
  Node* p=head;
  if ( isEmpty()) return 0;
  while ( p!=NULL){
if ( !(p->data&1)) sum+=p->data;
p=p->next;
  }
  return sum;
}

//----------------------------------------------------------------\\
// To copy the list to anther list ( l2 )

void List::copy_list(List* l2){

Node* p=head;
while ( p!=NULL){
l2->insert_to_tail(p->data);
p=p->next;

}
}

//----------------------------------------------------------------\\
//To update the data in position (poss)

 void List::update(int poss,int data){
   if ( poss <1 || poss >size()) return void ( cout<<"This posstion isn't in the list "<<nl);
   int l=1;
Node* p=head->next;
if ( poss==1) {
  head->data=data;
  return;
}

while ( p!=NULL){
  l++;
  if ( l==poss){
  p->data=data;
 return;
  }
p=p->next;

}
 }

  //----------------------------------------------------------------\\
  
//To delete the element after the element has data = val

void List ::DelAfter(int val){
    if(isEmpty())
       return void ( cout<<"The list is empty");
  else if(val==head->data)
       return void( del_from_head());

    Node* p=head;
    int x=1;
    while ( p!=NULL){

      if ( p->data==val) {
        del_poss(x+1);
        return;
      }
      x++;
      p=p->next;
    }
cout<<"This value not found "<<nl;

}

//----------------------------------------------------------------\\
//To add element before the element with data =value

void List::insert_befor(int value, int data){

    if(isEmpty())return void ( cout<<"The list is empty");
    if ( head->data==value) return void ( insert_to_head(data));
    Node* p=head->next;
    while ( p!=NULL){

      if ( p->data==value){


        Node* ele=new Node();
      ele->data=data;
      p->prev->next=ele;
      ele->next=p;
      ele->prev=p->prev;
      p->prev=ele;
      return;



      }
p=p->next;

    }
 cout<<"This value isn't in the list"<<nl;

}

//----------------------------------------------------------------\\

int main(){


List l;
int n;
 cin >>n;
 for ( int i=0;i<n;i++){

    int x;
    cin >> x;
    l.insert_to_tail(x);
 }


 l.print();
 cout<<nl;




return 0;

}
