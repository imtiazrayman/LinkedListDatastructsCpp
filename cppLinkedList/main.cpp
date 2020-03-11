#include <iostream>
#include "Node.h"
using namespace std;
int main() {
  cout<<"here are the tests, we assume all the print_list function works, otherwise no test will pass\n";
  cout<<"press 1 for head_insert test"<<endl;
  cout<<"press 2 for list_length test"<<endl;
  cout<<"press 3 for list_get_tail, both const and non const test"<<endl;
  cout<<"press 4 for list_tail_insert"<<endl;
  cout<<"press 5 for list_insert"<<endl;
  cout<<"press 6 for list_search"<<endl;
  cout<<"press 7 for list locate"<<endl;
  cout<<"press 8 for list_head_remove"<<endl;
  cout<<"press 9 for list_remove"<<endl;
  cout<<"press 10 for list_clear"<<endl;
  cout<<"press 11 for list copy"<<endl;

  int choice;
  cin>>choice;

  if(choice==1)
  {
    cout<<"creates a Node* to null and then inserts 5,4,3,2,1 at head, in that order\n";
    Node* head=NULL;
    for(int i=5; i>0; i--)
    {
      list_head_insert(head,i);
    }
     print_list(head);
  }
 
  if(choice==2)
  {
    cout<<"creates a Node* to null and then inserts 5,4,3,2,1 at head, in that order, each time checking length\n";
    Node* head=NULL;
    if(list_length(head)==0)
    {
      cout<<"0 length correct"<<endl;
    }
    for(int i=5; i>0; i--)
    {
      list_head_insert(head,i);
      cout<<"current length: "<<list_length(head)<<endl;
    }
    
    cout<<"Final length: "<<list_length(head)<<endl;
  } 

  if(choice==3)
  {
    cout<<"creates a Node* to null and then inserts 5,4,3,2,1 at head, in that order, each grabbing the tail and checking if it's correct\n";
    Node* head=NULL;
    Node* headConst=NULL;
    cout<<"empty list, list_get_tail should be null "<<list_get_tail(head)<<endl;
    cout<<"empty list, list_get_tail should be null (const) "<<list_get_tail(headConst)<<endl;
    for(int i=5; i>0; i--)
    {
      list_head_insert(head,i);
    }
    cout<<"at the end of all the inserts, tail should be value 5"<<endl;
    cout<<"non-const list_get_tail: "<<list_get_tail(head)->data()<<endl;
    const Node* tailConst= list_get_tail(head);
    cout<<"const list_get_tail: "<<tailConst->data();
  } 

 if(choice==4)
  {
    cout<<"creates a Node* to null and then tail inserts 5,4,3,2,1 at head, in that order\n";
    Node* head=NULL;
    for(int i=5; i>0; i--)
    {
      list_tail_insert(head,i);
    }
     print_list(head);
  }

  if(choice==5)
  {
    Node* head=NULL;
    cout<<"\n creates a Node* to null and then inserts 5,4,3,2,1 using list_head_insert, then grabs the 3rd one and inserts 599 after it\n";

    Node* toInsertAfter;

    for(int i=5; i>0; i--)
    {
      list_head_insert(head,i);
    }
    cout<<"list before insert"<<endl;
    print_list(head);
    cout<<endl;
    toInsertAfter=head->link()->link();
    cout<<"list after insert"<<endl;
    list_insert(toInsertAfter,599);
     
    print_list(head);
  }

   if(choice==6)
  {
    cout<<"creates a Node* to null and then inserts 5,4,3,2,1 at head, in that order\n";
    Node* head=NULL;
    for(int i=5; i>0; i--)
    {
      list_head_insert(head,i);
    }
     cout<<"Now searchers for 0,1,2,3,4,5  in that order and prints out their values"<<endl;
     for(int i=0; i<6; i++)
     {
       cout<<"looking for "<<i<<" data should be this value if it exists: ";
       Node* found= list_search(head, i);
       if(found)
       {
         cout<<found->data()<<endl;
       }
       else
       {
         cout<<"NULL"<<endl;
       }
     }
      cout<<"CONST TEST: Now searchers for 0,1,2,3,4,5  in that order and prints out their values"<<endl;
     for(int i=0; i<6; i++)
     {
       cout<<"looking for "<<i<<" data should be this value if it exists: ";
       const Node* foundC= list_search(head, i);
       if(foundC)
       {
         cout<<foundC->data()<<endl;
       }
       else
       {
         cout<<"NULL"<<endl;
       }
     }
  }
/*
  if(choice==7)
  {
    cout<<"creates a Node* to null and then inserts 5,4,3,2,1 at head, in that order\n";
    Node* head=NULL;
    for(int i=5; i>0; i--)
    {
      list_head_insert(head,i);
    }
     cout<<"now finds the items at locations from 0 to 5 including 5 (which should be null)"<<endl;
     for(int i=0; i<6; i++)
     {
       Node* atPosition= list_locate(head,i);
       if(atPosition)
       {
         cout<<"at position "<<i<<" value is "<<atPosition->data()<<endl;
       }
       else
       {
         cout<<"at position "<<i<<" value is NULL"<<endl;
       }
     }
  }
 
  if(choice==8)
  {
    cout<<"creates a Node* to null and then inserts 5,4,3,2,1 at head, in that order\n";
    Node* head=NULL;
    for(int i=5; i>0; i--)
    {
      list_head_insert(head,i);
    }
     cout<<"now removes the head 6 times and prints out the values of the node removed"<<endl;
     for(int i=0; i<6; i++)
     {
       Node* removed=list_head_remove(head);
       if(removed)
       {
         cout<<"removed node value is "<<removed->data()<<endl;
       }
       else
       {
         cout<<"removed node value is NULL"<<endl;
       }
       
     }
  }
 if(choice==9)
  {
    Node* head=NULL;
    cout<<"calls remove on empty list"<<endl;
    list_remove(head);
    head=new Node(5);
    cout<<"calls remove on one item list passing in head, should be unchanged"<<endl;
    list_remove(head);
    head=NULL; //MEMORY LEAK ;)
    cout<<"\nNow resets head, creates a Node* to null and then inserts 5,4,3,2,1 at head, in that order\n";
    for(int i=5; i>0; i--)
    {
      list_head_insert(head,i);
    }
    cout<<"our list pre remove"<<endl;
    print_list(head);
     cout<<"\nnow removes the node after the 3 and prints out the values of the node removed (4)"<<endl;
     list_remove(list_search(head,3));
     cout<<"our list\n";
     print_list(head);   
     
  }

  if(choice==10)
  {
    cout<<"creates a Node* to null and then inserts 5,4,3,2,1 at head, in that order\n";
    Node* head=NULL;
    for(int i=5; i>0; i--)
    {
      list_head_insert(head,i);
    }
    cout<<"Now clears the list, memory leaks checked by hand"<<endl;
    list_clear(head);
    if(head==NULL)
    {
      cout<<"test passed!"<<endl;
    }
    else
    {
      cout<<"Test failed!"<<endl;
    }
  }

  if(choice==11)
  {
    cout<<"creates a Node* to null and then inserts 5,4,3,2,1 at head, in that order\n";
    Node* head=NULL;
    for(int i=5; i>0; i--)
    {
      list_head_insert(head,i);
    }
     Node* head2=NULL;
     list_copy(head, head2);
     cout<<"copied list should have same values"<<endl;
     print_list(head2);
     cout<<"now changing original lists first item, copied list should stay the same"<<endl;
     head->set_data(53);
     print_list(head2);
  }*/

}