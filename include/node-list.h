#include "node.h"
#include <cstddef>
// Linked list class to 
// implement a linked list.
template <typename T>
class Linkedlist
{ 
  Node<T>* head; 
  
public: 
  // Default constructor 
  Linkedlist() : head { nullptr } {};

  // Default destructor
  virtual ~Linkedlist();

  // Function to insert a 
  // node at the end of the 
  // linked list. 
  void insertNode(int);

  // Funtion to insert the element
  // at index
  void insertNode(int data, int pos);
  
  // Function to print the 
  // linked list. 
  void printList(); 

  // Function to reverse the list
  // reversing the pointers
  void reverseList();

  // Function to delete element
  // at given position
  void deleteNode(int pos);

  // Funtion to find the length of the list
  size_t listLength();

  // The indexing function
  Node<T> *index(int index);
  const Node<T> *index(int index) const;
  
  // Function to write to a file
  void write();

  bool isIncreasing();
};
