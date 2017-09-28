
 
 
#ifdef _CIRCULARLINKEDLIST_H_
 
#include <stdexcept>
#include "circularlinkedlist.h"
 
// default constructor
template <class T>
CircularLinkedList<T>::CircularLinkedList(void)
{
  
 
size = 0;             
head = NULL;
}
 
 
// copy constructor, performs deep copy of list elements
template <class T>
CircularLinkedList<T>::CircularLinkedList(const CircularLinkedList<T>& ll)
{
CopyList(ll);
}
// helper function for deep copy
// Used by copy constructor and operator=
template <class T>
void CircularLinkedList<T>::CopyList(const CircularLinkedList<T>& ll)
{
 size = 0;
 
    head = NULL;  
 	 	  if (ll.Count()==0) {} // do nothing
 	 	  else if (ll.Count() == 1) {
 	 	 	  Node<T>* temp = new Node<T>(ll.ElementAt(0));
 	 	 	  head=temp;head->next=head; head->prev=head; size++;
 	 	  } // if the list we are copying from contains 1 item;
 	 	  else
 	 	  {
 	 	 	  Node<T>* temp = new Node<T>(ll.ElementAt(0));
 	 	 	  head = temp;
 	 	 	  head->next=head; head->prev=head; size++;
 	 	 	 for(int i=0; i< (ll.Count()-1);i++)
 	 	 	 {
 	 	 	 	  
Node<T>* temp = new Node<T>(ll.ElementAt(i+1));          //creating a new node that contains the data from copy list    

 	 	 	 	 head->prev->next =temp; temp -> prev = head->prev;head->prev= temp; temp->next=head;
 	 	 	  size++;
 	 	 	  }
 	 	 	 
 	 	  }
}
 
 
// destructor
template <class T>
CircularLinkedList<T>::~CircularLinkedList(void)
{
DeleteList();
}
// helper function for deep delete
// Used by destructor and copy/assignment
template <class T>
void CircularLinkedList<T>::DeleteList()
{
Node<T>* temp = head;
 
  
 
 if(head == NULL) {;}              // case 1 if head is null then do nothing (size is zero);
else if (size == 1){delete head;}	  	  	  // case 2 if the size is 1
else
{
 	  for(int i =0; i < size ; i++)
 	  {
 	  	  temp = head->next;
 	  	  delete head;
 	  	  head = temp;	  	  
 	  }
}
head = NULL; //set head to null after deletion;
size = 0;
}
 
 
 
// Inserts an item at the tail end of the list in constant time
template <class T>
void CircularLinkedList<T>::Insert(T item)
{
Node<T>* temp = new Node<T>(item); // create a new pointer to type Node
//case 1: if there is nothing in the list
if (head == NULL)
{
 	  head = temp;
 	  head->next = head;	  	  	  	  //if there is only one item in the list head prev,and next will point to head itself
 	  head->prev = head;
}
  
 
else if (size == 1)          //case 2: if one item in the list
{
head -> next = temp; head -> prev = temp;
temp -> next = head; temp -> prev = head;
}
else //case 3: if more than one items in the list
{
 	  temp->prev = head->prev; temp->next = head;
 	  head->prev->next = temp; head->prev = temp;
}
 
size++; //increase the siz of the list
 
}
 
 
// Returns the number of items in the list
template <class T>
int CircularLinkedList<T>::Count() const
{
return size;
}
 
 
template <class T>
bool CircularLinkedList<T>::IsEmpty() const
{
if (head==NULL)
{return true;}
else
{	  return false ;}
 
}
 
 
// Returns existence of item
template<class T>
bool CircularLinkedList<T>::Contains(T item) const
{
  
 
 if (head== NULL){return false;}            //list is empty
Node<T>* temp = head;
for (int i=0 ; i < size; i ++)
{
 	  if (temp->data == item)
 	  { return true;}
 	  temp = temp-> next;
}
return false ;
}
 
 
 
 
    // Returns item at index (0-indexed)
template<class T>
T CircularLinkedList<T>::ElementAt(int p) const
{
Node<T>* temp = head;
  
 
 if (head == NULL) throw std::exception("list is empty");    // case if list is empty
else if (p>(size-1) || p < 0) throw std::exception("invalid index"); // case: invalid index;
else if (p == 0) {return head->data;}
else if (p == (size-1)) {return head->prev->data;}
else
{
 	  for(int i=0;i<p;i++)
 	  {
 	  	  temp=temp->next;
 	  }
 	  return temp->data;
}
}
 
 
// Removes and returns an item from position p (0-indexed)
template<class T>
T CircularLinkedList<T>::RemoveAt(int p)
{
Node<T>* temp = head;
T item;
  
 
 if (head == NULL) throw std::exception("list is empty");    // case if list is empty
else if (p> (size-1) || p < 0) throw std::exception("invalid index");
else if (size == 1) { head = NULL;}
else if (p == 0)	  	  	  	  	  	  	  	  	  	  	  //if the item removed is at position 1;
{head=head->next; head->prev = temp->prev; temp->prev->next=head;}
  
 
 else if (p == (size-1))                                       //case: the item is at the end of the list;
{temp=head->prev; head->prev = temp->prev; temp->prev->next=head;}
else
{
 	  for(int i=0;i<p;i++)
 	  {
 	  	  temp = temp->next;
 	  }
 	  temp->prev->next = temp->next;
 	  temp->next->prev = temp->prev;
}
item = temp->data;
delete temp;
size--;
return item;
 
}
 
template<class T>
void CircularLinkedList<T>::InsertAt(T item, int p)
{
if (p > size|| p<0) throw std::exception("invalid index");
Node<T>* temp = new Node<T>(item); // create a new pointer to type Node
Node<T>* temp2 = head; // keep track of the index
  
 
  if (head==NULL)             //no item in the list
{
 	  head = temp;
 	  head->prev = temp;
 	  head->next = temp;
}
  
 
  else if (p == 0)         //1 item in the list
{
 	  head = temp;
 	  temp->next = temp2;
 	  temp->prev = temp2->prev;
 	  temp2->prev->next=temp;
 	  temp2->prev = temp;
}
 
  
 
  else if (p == size)    // insert item in the last position
{
 	  temp2=temp2->prev;
 	  temp->prev = temp2;
 	  temp2->next = temp;
 	  temp->next = head;
 	  head->prev=temp;
}
else
{
 	  for(int i=0;i< p ; i++)
 	  {
 	  	  temp2=temp2 ->next;
 	  }
 	  temp2->prev->next = temp;
 	  temp->prev= temp2->prev;
 	  temp->next=temp2;
 	  temp2->prev=temp;
}
 
size++;
}
 
template<class T>
CircularLinkedList<T>& CircularLinkedList<T>::operator=(const CircularLinkedList<T>& ll)
{
if (this != &ll)
{
 	  DeleteList();
 	  CopyList(ll);
}
return *this;
}
 
#endif
