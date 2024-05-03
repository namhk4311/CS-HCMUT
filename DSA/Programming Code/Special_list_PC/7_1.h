#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;
#define SEPARATOR "#<ab@17943918#@>#"

int defaultSize = 50;

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


// Singly linked list node
template <typename E> class Link {
public:
E element; // Value for this node
Link *next; // Pointer to next node in list
// Constructors
Link(const E& elemval, Link* nextval =NULL)
{ element = elemval; next = nextval; }
Link(Link* nextval =NULL) { next = nextval; }
};


// Linked list implementation
template <typename E> class LList: public List<E> {
    private:
        Link<E>* head; // Pointer to list header
        Link<E>* tail; // Pointer to last element
        Link<E>* curr; // Access to current element
        int cnt; // Size of list
        void init() { // Intialization helper method
            curr = tail = head = new Link<E>;
            cnt = 0;
        }
        void removeall() { // Return link nodes to free store
            while(head != NULL) {
                curr = head;
                head = head->next;
                delete curr;
            }        
        }
    public:
        LList(int size=defaultSize) { init(); } // Constructor
        ~LList() { removeall(); } // Destructor
        void print() const; // Print list contents
        void clear() { removeall(); init(); } // Clear list
        // Insert "it" at current position
        void insert(const E& it) {
        curr->next = new Link<E>(it, curr->next);
        if (tail == curr) tail = curr->next; // New tail
        cnt++;
        }
        void append(const E& it) { // Append "it" to list
        tail = tail->next = new Link<E>(it, NULL);
        cnt++;
        }
        // Remove and return current element
        E remove() {
        Assert(curr->next != NULL, "No element");
        E it = curr->next->element; // Remember value
        Link<E>* ltemp = curr->next; // Remember link node
        if (tail == curr->next) tail = curr; // Reset tail
        curr->next = curr->next->next; // Remove from list
        delete ltemp; // Reclaim space
        cnt--; // Decrement the count
        return it;
        }
        void moveToStart() // Place curr at list start
        { curr = head; }
        void moveToEnd() // Place curr at list end
        { curr = tail; }
        // Move curr one step left; no change if already at front
        void prev() {
        if (curr == head) return; // No previous element
        Link<E>* temp = head;
        // March down list until we find the previous element
        while (temp->next!=curr) temp=temp->next;
        curr = temp;
        }
        // Move curr one step right; no change if already at end
        void next()
        { if (curr != tail) curr = curr->next; }
        int length() const { return cnt; } // Return length
        // Return the position of the current element
        int currPos() const {
        Link<E>* temp = head;
        int i;
        for (i=0; curr != temp; i++)
        temp = temp->next;
        return i;
        }
        // Move down list to "pos" position
        void moveToPos(int pos) {
        Assert ((pos>=0)&&(pos<=cnt), "Position out of range");
        curr = head;
        for(int i=0; i<pos; i++) curr = curr->next;
        }
        const E& getValue() const { // Return current element
        Assert(curr->next != NULL, "No value");
        return curr->next->element;
        }
};


// Abstract queue class
template <typename E> class Queue {
    private:
    void operator =(const Queue&) {} // Protect assignment
    Queue(const Queue&) {} // Protect copy constructor
    public:
    Queue() {} // Default
    virtual ~Queue() {} // Base destructor
    // Reinitialize the queue. The user is responsible for
    // reclaiming the storage used by the queue elements.
    virtual void clear() = 0;
    // Place an element at the rear of the queue.
    // it: The element being enqueued.
    virtual void enqueue(const E&) = 0;
    // Remove and return element at the front of the queue.
    // Return: The element at the front of the queue.
    virtual E dequeue() = 0;
    // Return: A copy of the front element.
    virtual const E& frontValue() const = 0;
    // Return: The number of elements in the queue.
    virtual int length() const = 0;
};

// Array-based queue implementation
template <typename E> class AQueue: public Queue<E> {
    private:
        int maxSize; // Maximum size of queue
        int front; // Index of front element
        int rear; // Index of rear element
        E *listArray; // Array holding queue elements
    public:
        AQueue(int size =defaultSize) { // Constructor
        // Make list array one position larger for empty slot
        maxSize = size+1;
        rear = 0; front = 1;
        listArray = new E[maxSize];
        }
        ~AQueue() { delete [] listArray; } // Destructor
        void clear() { rear = 0; front = 1; } // Reinitialize
        void enqueue(const E& it) { // Put "it" in queue
        Assert(((rear+2) % maxSize) != front, "Queue is full");
        rear = (rear+1) % maxSize; // Circular increment
        listArray[rear] = it;
        }
        E dequeue() { // Take element out
        Assert(length() != 0, "Queue is empty");
        E it = listArray[front];
        front = (front+1) % maxSize; // Circular increment
        return it;
        }
        const E& frontValue() const { // Get front value
        Assert(length() != 0, "Queue is empty");
        return listArray[front];
        }
        virtual int length() const // Return length
        { return ((rear+maxSize) - front + 1) % maxSize; }
};

// Linked queue implementation
template <typename E> class LQueue: public Queue<E> {
    private:
        Link<E>* front; // Pointer to front queue node
        Link<E>* rear; // Pointer to rear queue node
        int size; // Number of elements in queue
    public:
        LQueue(int sz =defaultSize) // Constructor
        { front = rear = new Link<E>(); size = 0; }
        ~LQueue() { clear(); delete front; } // Destructor
        void clear() { // Clear queue
        while(front->next != NULL) { // Delete each link node
        rear = front;
        delete rear;
        }
        rear = front;
        size = 0;
        }
        void enqueue(const E& it) { // Put element on rear
        rear->next = new Link<E>(it, NULL);
        rear = rear->next;
        size++;
        }
        E dequeue() { // Remove element from front
        Assert(size != 0, "Queue is empty");
        E it = front->next->element; // Store dequeued value
        Link<E>* ltemp = front->next; // Hold dequeued link
        front->next = ltemp->next; // Advance front
        if (rear == ltemp) rear = front; // Dequeue last element
        delete ltemp; // Delete link
        size --;
        return it; // Return element value
        }
        const E& frontValue() const { // Get front element
        Assert(size != 0, "Queue is empty");
        return front->next->element;
        }
        virtual int length() const { return size; }
};
