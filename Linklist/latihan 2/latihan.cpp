#include <iostream>
using namespace std;
struct node{
  char data;
  node* next;
  node* prev;

};

int main() {

node* first = new node;
first->data = 'B';
first->prev = NULL;
first->next = NULL;

cout<<first->data;
  node* jalan= new node;
  
  node* baru = new node;
  baru->data ='D';
  
  baru->next = NULL;
  baru->prev = first;
  cout<<baru->data;  


  node* baru2 = new node;
  baru2->data ='F';

  baru2->next = NULL;
  baru2->prev = baru;
  cout<<baru2->data;

  // cout<<endl;
  // jalan = first;
  // while(jalan!=NULL){
  // cout<<jalan->data;  
  // jalan = jalan->next;
  // }
  // cout<<endl;

// cout<<first->data;
//   first->data='B';
//   cout<<first->data;
    
  

node*baru3= new node;
  baru3->data = 'A';
  baru3->next= first; 
  first->prev = baru3;
  first = baru3;  
  
  jalan = first;

  cout<<first->data<<"---";

  while(jalan!=NULL){
  cout<<jalan->data;  
  jalan = jalan->next;
    
  }

  node*baru4 = new node;
  baru4->data='E';
  baru4->next=baru3;
  baru3->prev=baru4;
  baru4->prev=first;

  cout<<baru4->data;

  return 0;
}