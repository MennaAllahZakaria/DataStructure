 #include <bits/stdc++.h> 

 #define ll long long 
 #define nl "\n"

 using namespace std;


   class Node{
    public:
    int data;
    Node* next;
 
   };

class List {
Node * head;
public :

      List(){

        head = NULL;
    }
/////////////////////////////////////////Functions Declaration\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
    
 bool isEmpty(); 
 void print(); 

 int size(); 

 void insert_to_head(int num); 
 void insert_to_tail(int num); 
 void insert_to_possion(int poss,int data);

 void search(int target); 
 int searchPoss(int target); 

 void del_from_head(); 
 void del_from_tail(); 
 void del_posstion(int poss); 



  int get_min();
 int get_max();

 int sum_odd();
 int sum_even();

 void copy_list(List* l2);

 void update(int poss,int data);
 void DelAfter(int value);
 void addbefor(int val,int data);
};


/////////////////////////////////////////////////Functions Definition\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

// To cheak if the list is empty or not
bool List::isEmpty(){

   return head==NULL;
}

//---------------------------------------------------------\\

// To print all elements in the list
void List::print(){

if ( isEmpty()) return void ( cout<<"No Elements in that List");
Node* p=head;
int x=0;
while (p->next!=head ) {
    cout<<p->data<<" ";
   p=p->next;
   if ( x++==10) return;
}
cout<<p->data<<nl;

}

//---------------------------------------------------------\\

// return size of list 
int List::size(){
    if ( isEmpty()) return 0;
     int l=1;
    Node* p=head;
    
    while ( p->next!=head) {
   l++;
   p=p->next;

    }
    return l;
}

//---------------------------------------------------------\\

//To insert element in the beginning of the list 

void List::insert_to_head(int data){
 Node* p=new Node();
   p->data=data;
   p->next=head;
if ( isEmpty()) {
  
   head=p;
  head->next=head;
  return;
}
Node* q=head;
while ( q->next!=head){
    q=q->next;
}
q->next=p;
head=p;

}

//---------------------------------------------------------\\

//To insert element in the end of the list
void List::insert_to_tail(int data){
 Node* p=new Node();
   p->data=data;
   p->next=head;
if ( isEmpty()) {
  
   head=p;
  head->next=head;
  return;
}
Node* q=head;
while ( q->next!=head){
    q=q->next;
}
q->next=p;

}

//---------------------------------------------------------\\

//To insert element in possition (poss) 

void List ::insert_to_possion(int poss ,int data){

if (poss==1) return void ( insert_to_head(data));
if ( poss==size())  return void(insert_to_tail(data));
if ( poss <1 || poss >size()) return void ( cout<<"Can't Be Posstion "<<nl);
int n=1;

Node* p=head;
while ( p->next!=head){
n++;
 if ( n==poss){
  Node* ele=new Node();
  ele->data=data;
  ele->next=p->next;
  p->next=ele;
 return;
  }
p=p->next;
}

}

//---------------------------------------------------------\\

//To check if the element in the list or not 

void List ::search(int target){
if ( isEmpty()) return void ( cout<<"No Elements in that List"<<nl);
Node* p=head;

while (p->next!=head ){

    if ( p->data==target) return void ( cout<<"FOUND"<<nl);
    p=p->next;
}
 if ( p->data==target) return void ( cout<<"FOUND"<<nl);
cout<<"NOT FOUND"<<nl;

}

//To check if the element in the list and return it's posation 
// if element not found if list return -1
int List::searchPoss(int target){
  if ( isEmpty()) return -1;
  int l=1;
Node* p=head;
 if ( p->data==target) return l;
    p=p->next;
while (p!=head ){
l++;
    if ( p->data==target) return l;
    p=p->next;
}
return -1;

}

//---------------------------------------------------------\\

// To remove one element from the beginning of list

void List::del_from_head(){
if ( isEmpty()) return void ( cout<<"No Elements in that List"<<nl);
Node* p=head;
if ( p->next==head) {
    delete(head);
    return;
}
while( p->next!=head)  
     p=p->next;

  p->next=p->next->next;
    head=p->next;
}

//---------------------------------------------------------\\

// To remove one element from the end of list

void List::del_from_tail(){
if ( isEmpty()) return void ( cout<<"No Elements in that List"<<nl);
Node* p=head;
if ( p->next==head) {
    delete(head);
    return;
}

while ( p->next->next!=head){
p=p->next;
}

p->next=p->next->next;


}

//---------------------------------------------------------\\

// To remove element in position (poss)

void List::del_posstion(int poss){
if ( isEmpty()) return void ( cout<<"No Elements in that List"<<nl);
Node* p=head;
if ( poss==1) {
    delete(head);
    return;
}
int l=1;
while (p->next!=head){
l++;
if( l==poss){
    p->next=p->next->next;
    return;
}
p=p->next;
}

 cout<<"Unvalid posstion"<<nl;

}

//---------------------------------------------------------\\

//To get the minimum element 

int List::get_min(){
int mn=INT_MAX;
Node* p=head;

if ( isEmpty()) {
cout<<"No Elements in that List"<<nl;
return 0;
} 

while ( p!=head) {
    mn=min(mn,p->data);
    p=p->next;
}
return mn;

}

//---------------------------------------------------------\\

//To get the maximum element 

int List::get_max(){
int mx=INT_MIN;
Node* p=head;

if ( isEmpty()) {
cout<<"No Elements in that List"<<nl;
return 0;
} 

while ( p!=head) {
    mx=max(mx,p->data);
    p=p->next;
}
return mx;

}

//---------------------------------------------------------\\

//To get sum of all odd elements in the list

int List::sum_odd(){
  int sum=0;
  Node* p=head;
  if ( isEmpty()) return 0;
  while ( p!=head){
if ( p->data&1) sum+=p->data;
p=p->next;
  }
  return sum;
}

//---------------------------------------------------------\\

//To get sum of all even elements in the list

int List::sum_even(){
  int sum=0;
  Node* p=head;
  if ( isEmpty()) return 0;
  while ( p!=head){
if ( !(p->data&1)) sum+=p->data;
p=p->next;
  }
  return sum;
}

//---------------------------------------------------------\\

// To copy the list to anther list ( l2 )

void List::copy_list(List* l2){
if ( isEmpty()) return void ( cout<<"no element in list to copy");
Node* p=head;
while ( p!=NULL){
l2->insert_to_tail(p->data);
p=p->next;

}
l2->insert_to_tail(p->data);
p=p->next;
}

//---------------------------------------------------------\\

//To update the data in position (poss)

 void List::update(int poss,int data){
   if ( poss <1 || poss >size()) return void ( cout<<"This posstion isn't in the list "<<nl);
   int l=1;
Node* p=head;
if ( poss==1) {
  head->data=data;
  return;
}
p=p->next;
while ( p!=head){
  l++;
  if ( l==poss){
  p->data=data;
 return;
  }
p=p->next;

}
 }
  
//---------------------------------------------------------\\

//To add element before the element with data =value

void List::addbefor(int value, int data){
    
    Node* q=new Node;
    q->data=data;
    
    
    if(isEmpty())return void ( cout<<"The list is empty");
    
    else if(value==head->data){
        return void ( insert_to_head(data));
       
    }
    
        
        Node* curr=head->next,*prev=head;
        
        while(curr!=head){
            
            if(curr->data==value){
                prev->next=q;
                q->next=curr;
                return;
            }
            
            prev=curr;
            curr=curr->next;
        }
        
        
        cout<<"This value not found "<<nl;
    
}

//---------------------------------------------------------\\

//To delete the element after the element has data = val

void List ::DelAfter(int val){
    if(isEmpty())
       return void ( cout<<"The list is empty");
if ( head->next==head && head->data==val) 
       return void ( delete(head));
    if(val==head->data)
       return void( head->next=head->next->next);
       
    Node* p=head;
    p=p->next;
    int x=1;
    while ( p!=head){

      if ( p->data==val) {
        del_posstion(x+2);
        return;
      }
      x++;
      p=p->next;
    }
cout<<"This value not found "<<nl;


}

int main()
{

 List l;

 int n;
 cin >>n;
 for ( int i=0;i<n;i++){


    int x;
    cin >> x;
    l.insert_to_tail(x);
 }
cout<<"size of list is "<<l.size()<<nl;

l.print();
cout<<nl;

    return 0;
}


