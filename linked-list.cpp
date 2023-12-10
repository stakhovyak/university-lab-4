#include <fstream>
#include <cstddef>
#include <iostream>
#include "include/node.h"
#include "include/node-list.h"
using std::cout, std::endl;

// Default destructor
template <typename T>
Linkedlist<T>::~Linkedlist()
{
  Node<T>* current = head;
  while (current != nullptr)
    {
      Node<T>* temp = current;
      current = current->next;
      delete temp;
    }
}

// Function to insert a new node.
template <typename T>
void Linkedlist<T>::insertNode(int data) 
{ 
  Node<T>* newNode = new Node<T>(data);
  if (head == nullptr)
    {
      head = newNode;
    }
  else
    {
      Node<T>* current = head;
      while (current->next != nullptr)
        {
          current = current->next;
        }
      current->next = newNode;
    }
}

template <typename T>
void Linkedlist<T>::insertNode(int data, int pos)
{
  Node<T> *newNode = new Node<T>(data);

  if (pos == 0)
    {
      newNode->next = head;
      head = newNode;
      return;
    }

  Node<T> *temp = head;
  for (int i = 0; i < pos--; i++)
    {
      if (temp == nullptr)
        {
          throw std::out_of_range("Index out of range!");
          return;
        }
      temp = temp->next;
    }
  newNode->next = temp->next;
  temp->next = newNode;
}

template <typename T>
void Linkedlist<T>::deleteNode(int pos)
{
  if (head == nullptr)
    {
      cout << "List is empty" << endl;
      return;
    }

  if (pos == 0)
    {
      Node<T>* temp = head;
      head = head->next;
      delete temp;
      return;
    }

  Node<T> *temp = head;
  for (int i = 0; i < pos--; i++)
    {
      if (temp == nullptr || temp->next == nullptr)
        {
          throw std::out_of_range("Index is out of range!");
          return;
        }
      temp = temp->next;
    }

  Node<T> *toDelete = temp->next;
  temp->next = temp->next->next;
  delete toDelete;
}

// Function to print the 
// nodes of the linked list.
template <typename T>
void Linkedlist<T>::printList() 
{
  if (head == nullptr)
    {
      cout << "List is empty" << endl;
      return;
    }

  Node<T> *current = head;
  while (current != nullptr)
    {
      cout << current->data << " ";
      current = current->next;
    }
  cout << endl;
}

template <typename T>
void Linkedlist<T>::reverseList() 
{ 
  Node<T>* prev = nullptr; 
  Node<T>* current = head; 
  Node<T>* next = nullptr; 
  
  while (current != nullptr)
    { 
      next = current->next; 
      current->next = prev; 
      prev = current; 
      current = next; 
    } 
  
  head = prev;
}

template <typename T>
size_t Linkedlist<T>::listLength()
{
  Node<T> *temp1 = head;
  size_t listLen = 0;

  // Find length of the list
  while (temp1 != nullptr)
    {
      temp1 = temp1->next;
      listLen++;
    }

  return listLen;
}

template <typename T>
Node<T> *Linkedlist<T>::index(int index)
{
  Node<T> *current = this->head;
  unsigned int count = 0;
  
  while (current != nullptr)
    {
      if (count == index)
        return current;
      else
        {
          count++;
          current = current->next;
        }
    }

  throw std::out_of_range("The index is out of range!");
  return nullptr;
}

template <typename T>
void Linkedlist<T>::write()
{
  std::ofstream outFile("input.txt");

  if (!outFile)
    {
      std::cerr << "Failed to open file" << endl;
      return;
    }
  
  Node<T> *current = head;

  while (current != nullptr)
    {
      outFile << current->data << " ";
      current = current->next;
    }

  outFile.close();
}

template <typename T>
bool Linkedlist<T>::isIncreasing()
{
  Node<T> *current = head;
  while (current->next != nullptr)
    {
      if (current->data <= current->next->data)
        {
          current = current->next;
        }
      else
        {
          std::cerr << "Список должен быть неубывающим!" << endl;
          return false;
        }
    }

  return true;
}
