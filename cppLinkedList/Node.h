#ifndef NODE_H  
#define NODE_H
#include <cstdlib> // Provides size_t and NULL
  
  
class Node //Node is all inlined and implemented
{
  public:
    typedef int value_type;
    
	// CONSTRUCTOR
	  Node(const value_type& init_data = value_type( ), Node* init_link = NULL)
	    { data_field = init_data ; link_field = init_link; }

	// Member functions to set the data and link fields:
    	void set_data(const value_type& new_data) { data_field = new_data; }
    	void set_link(Node* new_link)             { link_field = new_link; }

	// Constant member function to retrieve the current data:
	   value_type data( ) const { return data_field; }

	// Two slightly different member functions to retreive
	// the current link:
	   const Node* link( ) const { return link_field; }
    	Node* link( )             { return link_field; }
	
  private:
	  value_type data_field;
	  Node* link_field;
};
    // FUNCTIONS for the linked list toolkit
    //Utlity Functions
    void print_list(const Node* head_ptr);
    std::size_t list_length(const Node* head_ptr);
    const Node* list_get_tail(const Node* head_ptr);
    Node* list_get_tail(Node* head_ptr);
    
    //Inserting into a list
    void list_head_insert(Node*& head_ptr, const Node::value_type& entry); 
    void list_insert(Node* previous_ptr, const Node::value_type& entry);  
    void list_tail_insert(Node*& head_ptr, const Node::value_type& toInsert);

    //Searching and locating in a list based on value and "index"
    Node* list_search(Node* head_ptr, const Node::value_type& target);
    const Node* list_search (const Node* head_ptr, const Node::value_type& target);
    //Node* list_locate(Node* head_ptr, std::size_t position);
    /*const Node* list_locate(const Node* head_ptr, std::size_t position);
    */
    //Removing from a list
    Node* list_head_remove(Node*& head_ptr);
    Node* list_remove(Node* previous_ptr);
    /*Node* list_tail_remove(Node* head_ptr);
    */
    void list_clear(Node*& head_ptr);
    void list_copy(const Node* source_ptr, Node*& head_ptr);
#endif