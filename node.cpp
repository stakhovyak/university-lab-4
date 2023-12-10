#include "include/node.h"

template <typename T>
Node<T>::Node() 
{ 
  data = 0; 
  next = nullptr; 
}

template <typename T>
Node<T>::Node(int data)
{
  this->data = data;
  this->next = nullptr;
}
