// File:        circularlinkedlist.h
// Author:      Geoffrey Tien
// Date:        2015-05-25
// Description: Declaration of a templated CircularLinkedList class to be used for CMPT 225 assignment #2
//              FILE REQUIRES NO MODIFICATIONS

#ifndef _CIRCULARLINKEDLIST_H_
#define _CIRCULARLINKEDLIST_H_

#include <cstdlib>
#include <stdexcept>
using namespace std;

// template class for doubly-linked list node
template <class T>
class Node
{
  public:
    T data;
    Node<T>* prev;
    Node<T>* next;

    // default constructor (parameterized)
    template <class T>
    Node(T value)
    {
      data = value;
      prev = NULL;
      next = NULL;
    }
};

// CircularLinkedList class definition
template <class T>
class CircularLinkedList
{
  private:
    // LinkedList private members
    int size; // number of items stored in list
    Node<T>* head; // reference to the front, can access back of the list with head->prev (if not null)

    // helper function for deep copy
    // Used by copy constructor and operator=
    void CopyList(const CircularLinkedList<T>& ll);

    // helper function for deep delete
    // Used by destructor and copy/assignment
    void DeleteList();

  public:
    // default constructor
    CircularLinkedList();

    // copy constructor, performs deep copy of list elements
    CircularLinkedList(const CircularLinkedList<T>& ll);

    // destructor
    ~CircularLinkedList();

    // Accessors

    // Returns the number of items in the list
    int Count() const;

    // Returns whether the list contains any items
    bool IsEmpty() const;

    // Returns existence of item
    bool Contains(T item) const;

    // Returns item at index (0-indexed)
    // Throws exception for empty list or invalid index
    T ElementAt(int p) const;

    // Inserts an item at the tail end of the list in constant time
    // POST: List contains item at the tail end, size increases by 1
    // PARAM: item = item to be inserted
    void Insert(T item);

    // Inserts an item in position p (0-indexed)
    // Throws exception for invalid index
    // POST:  List contains item at position p
    // PARAM: item = item to be inserted, p = position where item will be inserted
    void InsertAt(T item, int p);

    // Removes and returns an item from position p (0-indexed)
    // Throws error if list is empty or index invalid
    // POST:  Item is removed from list and associated Node memory is deallocated
    // PARAM: p = position from where item will be removed
    T RemoveAt(int p);

    // overloaded assignment operator
    // must work in the following cases:
    // list2 = list1 -> general case
    // list2 = list2 -> should do nothing
    CircularLinkedList<T>& operator=(const CircularLinkedList<T>& ll);
};

#include "circularlinkedlist.cpp"

#endif