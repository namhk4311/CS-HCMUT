#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;
#define SEPARATOR "#<ab@17943918#@>#"

void Assert(bool val, string s) {
    if (!val) { // Assertion failed -- close the program 
        cout << "Assertion Failed: " << s << endl;
        exit(-1); }
}
template <typename E> class List { // List ADT
private:
  void operator =(const List&) {} // Protect assignment
  List(const List&) {}           // Protect copy constructor
public:
  List() {} // Default constructor 
  virtual ~List() {} // Base destructor
// Clear contents from the list, to make it empty. 
  virtual void clear() = 0;
// Insert an element at the current location. // item: The element to be inserted
  virtual void insert(const E& item) = 0;
// Append an element at the end of the list. // item: The element to be appended.
  virtual void append(const E& item) = 0;
// Remove and return the current element. // Return: the element that was removed. 
  virtual E remove() = 0;
// Set the current position to the start of the list  
  virtual void moveToStart() = 0;
// Set the current position to the end of the list virtual 
  virtual void moveToEnd() = 0;
// Move the current position one step left. No change // if already at beginning.
  virtual void prev() = 0;
// Move the current position one step right. No change // if already at end.
  virtual void next() = 0;
// Return: The number of elements in the list. 
  virtual int length() const = 0;
// Return: The position of the current element. 
  virtual int currPos() const = 0;
// Set current position.
// pos: The position to make current. 
   virtual void moveToPos(int pos) = 0;
// Return: The current element.
  virtual const E& getValue() const = 0; 
};
// Doubly linked list link node with freelist support
template <typename E> class Link {
private:
  static Link<E>* freelist; // Reference to freelist head
public:
  E element;
  Link* next;
  Link* prev;
  Link(const E& it, Link* prevp, Link* nextp) {
    element = it; prev = prevp; next = nextp;
    }
  Link(Link* prevp =NULL, Link* nextp =NULL) {
    prev = prevp;
    next = nextp; }
 /* void* operator new(size t) { // Overloaded new operator if (freelist == NULL) return ::new Link; // Create space Link<E>* temp = freelist; // Can take from freelist freelist = freelist->next;
    return temp;                 // Return the link
  }
  // Overloaded delete operator
  void operator delete(void* ptr) {
   ((Link<E>*)ptr)->next = freelist; // Put on freelist } freelist = (Link<E>*)ptr;*/
};

// Linked list implementation
template <typename E> class DLList: public List<E> {
private:
  Link<E>* head;
  Link<E>* tail;
  Link<E>* curr;
  int cnt;
  void init() {
     curr = head = new Link<E>();
     tail = new  Link<E>(head);
     head -> next = tail;
     cnt = 0; }

   void removeall() { 
     while(head!=nullptr) {
        curr = head -> next;
        head = head->next; 
        delete curr;
     } 
   }
public:
  DLList() { init(); }
  ~DLList() { removeall(); }
  void clear() {removeall(); init();}

  // Insert "it" at current position
  void insert(const E& it) {
    curr->next = curr->next->prev = new Link<E>(it, curr, curr->next);
    cnt++; 
  }
  void append(const E& it) { // Append "it" to list 
    tail->prev = tail->prev->next =new Link<E>(it, tail->prev, tail);
    cnt++;
 }
  // Remove and return current element
  E remove() {
    Assert(curr->next != tail, "No element");
    E it = curr->next->element; 
    Link<E>* ltemp = curr->next; 
    curr->next->next->prev = curr; 
    curr->next = curr->next->next; 
    delete ltemp;
    cnt--;
    return it;
 }
 void moveToStart() 
    { curr = head;}
 void moveToEnd() // Place curr at list end 
    { curr = tail -> prev; }
  // Move curr one step left; no change if already at front
  void prev() {
   if (curr == head) return; 
    curr = curr->prev; 
  }
  // Move curr one step right; no change if already at end
  void next() { 
      if (curr->next != tail) curr = curr->next; }
  int length() const { return cnt; } // Return length
  // Return the position of the current element
  int currPos() const {
    Link<E>* temp = head;
    int i;
    for (i=0; i<cnt && curr != temp; i++)
       temp = temp->next; 
    return i;
   }
// Move down list to "pos" position
    void moveToPos(int pos) {
    Assert ((pos>=0)&&(pos<=cnt), "Position out of range");
    curr = head;
    for(int i=0; i<pos; i++) curr = curr->next;
  }

  const E& getValue() const { // Return current element Assert(curr->next != NULL, "No value");
     return curr->next->element; }

    E removePre() {
        Assert(curr != head, "No element");
        Link<E> *tmp = curr;
        E val = tmp->element;
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
        curr = curr->prev;
        delete tmp;
        cnt--;
        return val;
    }

};