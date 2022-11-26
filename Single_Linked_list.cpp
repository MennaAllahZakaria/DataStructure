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

//Constructor
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

/////////////////////////////////////////////Functions Declaration\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
 bool isEmpty();
 void print();

 void insert_to_head(int data);
 void insert_to_tail(int data);
 void insert_to_possion(int poss,int data);

 void search(int target);
 int searchPoss(int target);

 int size();

 void del_from_head();
 void del_from_tail();
 void delAt(int poss);

 int get_min();
 int get_max();

 int sum_odd();
 int sum_even();

 void copy_list(List* l2);

 void update(int poss,int data);
 void DelAfter(int value);
 void addbefor(int val,int data);
 void reverse_list();
};


//////////////////////////////////////////Functions Definition\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

// To cheak if the list is empty or not
bool List::isEmpty(){

   return head==NULL;
}

//----------------------------------------------------------------------------\\

// To print all elements in the list
 void List:: print() {
  Node* p= head;
  if(isEmpty()) return void ( cout<<"No eleemants in the List"<<nl);
int x=0;
 while ( p != NULL  ){
    cout<< p->data<<" ";
    p=p->next;
  x++;
  if ( x==100) return;
  }
  
 cout<<nl;
 }
 
 //----------------------------------------------------------------------------\\
 
//To insert element in the beginning of the list 
void List::insert_to_head(int data){

Node* p = new Node();

p->data=data;
p->next=head;
head=p;

}

//----------------------------------------------------------------------------\\

//To insert element in the end of the list
void List::insert_to_tail(int data){

Node* p=head;
if ( isEmpty()) return void ( insert_to_head(data));
Node* ele = new Node();
ele->data=data;
while ( p!=NULL && p->next!=NULL){

  p=p->next;
}

p->next=ele;

}

//----------------------------------------------------------------------------\\

//To insert element in possition (poss) 
void List::insert_to_possion(int poss,int data){

if ( poss==1)  return void(insert_to_head(data));
if ( poss==size())  return void(insert_to_tail(data));
if ( poss <1 || poss >size()) return void ( cout<<"Can't Be Posstion "<<nl);
int l=0;
Node* p=head;
while ( p!=NULL){
  l++;
  if ( l==poss){
  Node* ele=new Node();
  ele->data=data;
  ele->next=p->next;
  p->next=ele;
 return;
  }
p=p->next;

}

 
}

//----------------------------------------------------------------------------\\

//To check if the element in the list or not 
void List::search ( int target){

if ( head==NULL) return void (cout<<"LIST IS NULL"<<nl);

Node* p=head;
  while ( p!=NULL && p-> next!=NULL) {
if ( p->data==target) return void (cout<<"FOUND"<<nl);

p=p->next;
  }
cout<<"NOT FOUND";



}

//----------------------------------------------------------------------------\\

//To check if the element in the list and return it's posation 
// if element not found if list return -1
int List::searchPoss(int target){


if ( head==NULL) return -1;
Node* p=head;
int n=0;


  while ( p!=NULL && p-> next!=NULL) {
    n++;
if ( p->data==target) return n;

p=p->next;
  

}
return -1;
}

//----------------------------------------------------------------------------\\

// return size of list 
int List::size(){

  int l=0;
  Node* p=head;
  while ( p!=NULL) {
    p=p->next;
    l++;
  }
  return l;
}

// To remove one element from the beginning of list
void List::del_from_head(){
  if ( head==NULL) return;
  head=head->next;
}

//----------------------------------------------------------------------------\\

// To remove one element from the end of list

void List::del_from_tail(){
    if ( head==NULL) return;

    if ( head->next==NULL) {
      head=head->next;
      return;
    }
    Node* p=head;
    while ( p->next->next!=NULL){
      p=p->next;
    }

    p->next=p->next->next;


}

//----------------------------------------------------------------------------\\

// To remove element in position (poss)

void List::delAt(int poss){

  if ( head==NULL) return;
  if ( poss ==1) return void ( del_from_head());
  if ( poss <1 || poss >size()) return void ( cout<<"This posstion isn't in the list "<<nl);
  
  Node* p=head;
  int x=0;
  while (p!=NULL)
  {
  x++;
  if ( x==poss && p->next!=NULL) {
    p->next=p->next->next;
    
    return;
  }
  else p=p->next;

  }


    
}

//----------------------------------------------------------------------------\\

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

//----------------------------------------------------------------------------\\

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

//----------------------------------------------------------------------------\\

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

//----------------------------------------------------------------------------\\

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

// To copy the list to anther list ( l2 )
void List::copy_list(List* l2){

Node* p=head;
while ( p!=NULL){
l2->insert_to_tail(p->data);
p=p->next;

}


}

//----------------------------------------------------------------------------\\

//To update the data in position (poss)

 void List::update(int poss,int data){
   if ( poss <1 || poss >size()) return void ( cout<<"This posstion isn't in the list "<<nl);
   int l=0;
Node* p=head;
if ( poss==1) {
  head->data=data;
  return;
}
p=p->next;
while ( p!=NULL){
  l++;
  if ( l==poss){
  p->data=data;
 return;
  }
p=p->next;

}
 }
  
  //----------------------------------------------------------------------------\\
  
//To add element before the element with data =value

void List::addbefor(int value, int data){
    
    Node* q=new Node;
    q->data=data;
    
    
    if(isEmpty())return void ( cout<<"The list is empty");
    
    else if(value==head->data){
        return void ( insert_to_head(data));
       
    }
    else{
        
        Node* curr=head->next,*prev=head;
        
        while(curr!=NULL){
            
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
}

//----------------------------------------------------------------------------\\

//To delete the element after the element has data = val

void List ::DelAfter(int val){
    if(isEmpty())
       return void ( cout<<"The list is empty");
  else if(val==head->data)
       return void( del_from_head());
       
    Node* p=head;
    int x=0;
    while ( p!=NULL){

      if ( p->data==val) {
        delAt(x+1);
        return;
      }
      x++;
      p=p->next;
    }
cout<<"This value not found "<<nl;


}
//----------------------------------------------------------------------------\\
// To reverse the list
void List::reverse_list(){
   if (head==nullptr || head->next==nullptr) 
            return;
       Node* last=head;
     Node* temp=head->next;
     last->next=NULL;

        while ( temp){
        
        head=temp;
        temp=temp->next;
        head->next=last;

        last=head;
        }

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
cout<<"the max element = "<<l.get_max()<<nl;
cout<<"the min element = "<<l.get_min()<<nl;

l.search(5);
    return 0;
}


