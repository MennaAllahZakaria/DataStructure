#include <bits/stdc++.h> 
#define nl "\n"
 using namespace std;


 class Node{
    public:
int data;
Node* left;
Node* right;
Node(int val=0){
  this->data=val;
  left=NULL;
  right=NULL;

}

 };

//*********************************************************************\\

// root left right
 void pre_order(Node* root ){

if ( root ==NULL) return ;
cout<<root->data<<" ";
pre_order(root->left);
pre_order(root->right);


 }

//*********************************************************************\\

 //left root right
 void in_order(Node* root ){

if ( root ==NULL) return ;

in_order(root->left);
cout<<root->data<<" ";
in_order(root->right);


 }

 //*********************************************************************\\

 // left right root
 void post_order(Node* root ){

if ( root ==NULL) return ;

post_order(root->left);
post_order(root->right);
cout<<root->data<<" ";

 }

 //*********************************************************************\\

// level order 
void level_order(Node* root){

if ( root ==NULL) return ;

queue<Node*>q;
q.push(root);
while ( !q.empty()){
  Node* curr=q.front();
  cout<<curr->data<<" ";
  if ( curr->left!=NULL) q.push(curr->left);
  if ( curr->right!=NULL) q.push(curr->right);

q.pop();

}
}
//*********************************************************************\\

// return the hight of tree
int hight ( Node* root){
  
if ( root==NULL) return 0;
return max(hight(root->left),hight(root->right))+1;

}

//*********************************************************************\\

// count numbers of this node in tree 
int count_node ( Node* root){
  
if ( root==NULL) return 0;
return count_node(root->left)+count_node(root->right)+1;

}

//*********************************************************************\\


// count how many leaves in the tree
int count_leaves ( Node* root){
  
if ( root==NULL) return 0;
if ( root->left==NULL && root->right==NULL) return 1;
return count_leaves(root->left)+count_leaves(root->right);

}

//*********************************************************************\\


// return the node of the max element

Node* max_element(Node* root){
Node* p=root;
while ( p!=NULL and p->right!=NULL) p=p->right;
return p;

}

//*********************************************************************\\


// return the node of the min element

Node* min_element(Node* root){
Node* p=root;
while ( p!=NULL and p->left!=NULL) p=p->left;
return p;
}

//*********************************************************************\\


// search the number in the tree

bool search(Node* root,int target){

if ( root==NULL) return false;
if ( root->data==target) return true;
if ( target>root->data) return search(root->right,target);
else return search(root->left,target);

}

//*********************************************************************\\


// insert node in the tree

 Node* insert(Node* root, int val){
        if(!root) return new Node(val);
        if(val > root -> data)
            root -> right = insert(root -> right, val);
        else
            root -> left = insert(root -> left, val);
        return root;
    }

//*********************************************************************\\

// delete node from the tree

Node* delete_node (Node* root, int val){
  if ( root==NULL) return root;

if ( val > root->data){
 root ->right= delete_node( root->right,val);

}

else if ( val < root->data){
 root ->left= delete_node( root->left,val);
 
}

else{
  if ( root->left==NULL && root->right==NULL) return NULL;

  if ( root->left==NULL) {
   Node* temp = root -> right;
   delete root;
   return temp;
  }

  
  if ( root->right==NULL) {
   Node* temp = root ->left;
   delete root;
   return temp;
  }

 Node* temp = min_element(root -> right);
 root -> data = temp -> data;
 root -> right = delete_node(root -> right, temp -> data);

}
return root;
}



 int main(){

    return 0;
 }
