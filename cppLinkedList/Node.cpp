#include <iostream>
#include "Node.h"
using namespace std;

//PUT ALL YOUR IMPLEMENTATIONS HERE
void print_list(const Node* head_ptr)
{
 const Node* current= head_ptr;
 cout << "head-->";
 while(current !=NULL)
 {
   cout<<current->data()<<"-->";
   current=current->link();
 }
 cout<<"null";
}

void list_head_insert(Node*& head_ptr, const Node::value_type& entry)
{
     head_ptr = new Node(entry, head_ptr);
}

std::size_t list_length(const Node* head_ptr)
{
  int count = 0; 
  const Node* current = head_ptr;
  while(current !=NULL)
 {
   count++;
   current = current->link();
 }
 return count;
}

Node* list_get_tail(Node* head_ptr)
{
  Node* tail;
  //tail-> set_link(NULL); 
  if( head_ptr == NULL){ // check to see if the head null meaning the list is empty
    return NULL; // tail is gonna be null
  }
  else // if the head isnt null 
  {
    while(head_ptr->link() != NULL){ // find when the next link is null
      head_ptr = head_ptr->link(); // keep incrementing
      tail = head_ptr;
    }
   // return head_ptr;
      //head_ptr = tail;
  }
  return tail;
}



const Node* list_get_tail(const Node* head_ptr)
{
// const Node* tail;
 // tail->set_link(head_ptr); 
  const Node* tail = head_ptr;
  if(head_ptr == NULL){
    return NULL; 
  }
  else
  {
    //const Node* tail = head_ptr;
    while(head_ptr->link() != NULL){
      head_ptr = head_ptr->link(); 
      tail = head_ptr; 
    }
    //return tail; 
  }
  return tail;
}


void list_tail_insert(Node*& head_ptr, const Node::value_type& toInsert)
{
  //Node* tail = new Node(toInsert, head_ptr);
  //tail->set_data(toInsert);
  if (head_ptr == NULL) {
        head_ptr = new Node(toInsert, head_ptr);
        list_head_insert(head_ptr,toInsert);
         while(head_ptr == NULL){
          list_insert(head_ptr,toInsert);
           head_ptr = head_ptr->link();
        }
  }
    else {
        while (head_ptr->link() != NULL) {
            head_ptr = head_ptr->link();
        }
        list_insert(head_ptr,toInsert);
        //head_ptr = head_ptr->link();
        //while(head_ptr == NULL){
         // list_insert(NULL,toInsert);
          // head_ptr = head_ptr->link();
        //}
        //head_ptr->set_data(toInsert);
        //list_head_insert(head_ptr,toInsert); //= new Node();
        
    }
    //list_head_insert(head_ptr,toInsert);

    //return head_ptr;
  /*if(head_ptr==NULL){
    head_ptr = tail;
  }*/
  
 /* while(head_ptr->link() != NULL){
    head_ptr = head_ptr->link();
  }
   Node* tmp = new Node();
   tmp->set_data(toInsert);
   tmp->set_link(NULL);
   if(head_ptr->link()==NULL){
    head_ptr->set_link(tail);
  }
   //head_ptr->set_link(tail);*/
}

void list_insert(Node* previous_ptr, const Node::value_type& entry)
{
  
Node *insert_ptr;

   insert_ptr = new Node(entry, previous_ptr->link( ));

previous_ptr->set_link(insert_ptr); 
  
}

Node* list_search(Node* head_ptr, const Node::value_type& target)
{
  Node *cursor;
  for (cursor = head_ptr; cursor != NULL; cursor = cursor->link( ))
  if (target == cursor->data( )){
  return cursor;}
  
  return NULL; 
  
}

const Node* list_search (const Node* head_ptr, const Node::value_type& target)
{
  const Node *cursor;
  for (cursor = head_ptr; cursor != NULL; cursor = cursor->link( ))
  if (target == cursor->data( ))
  return cursor;
  return NULL; 
  
}

 void list_copy(const Node* source_ptr, Node*& head_ptr)
{
  head_ptr = NULL;
  Node* tail_ptr = NULL;
  if (source_ptr == NULL) return;
  
  list_head_insert(head_ptr, source_ptr->data());
  tail_ptr = head_ptr;
  
  for (source_ptr = source_ptr->link(); source_ptr != NULL ; source_ptr=source_ptr->link())
  {
    list_insert(tail_ptr, source_ptr->data());
    tail_ptr = tail_ptr->link();
  }
}

Node* list_head_remove(Node*& head_ptr)
{
// this is the second non void functon
  Node *kill;
  kill = head_ptr;
  head_ptr = head_ptr->link(); // move up the head
  delete kill;
  return head_ptr;
}

void list_clear(Node* & head_ptr)
{
  Node *kill; // set up a pointer to take in the value that we want to remove
  //kill = head_ptr; // get the target ready for removal 
  while (head_ptr != NULL) { 
    //list_head_remove(head_ptr);
    kill = head_ptr; 
    head_ptr=head_ptr->link(); // move the head up
    delete kill; //get rid of the old head
  }
} 

Node* list_remove(Node* previous_ptr)
{
// this is a functin that reaches end of non void function 
  Node *remove_ptr; 
  // previous_ptr->> remove_ptr;
  remove_ptr->set_link(previous_ptr->link()); // set the remove 
  //to the previous ptr so it is the next pointer. 
   if (remove_ptr->link()!=NULL) 
   {
      previous_ptr->set_link(remove_ptr->link()); 
   } 
  else 
  {
    previous_ptr->set_link(NULL); // if previous_ptr-> remove_ptr 
  }
  //remove_ptr->set_link(NULL);
  delete remove_ptr;
  return previous_ptr;
}

