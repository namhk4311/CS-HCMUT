#include <bits/stdc++.h>
using namespace std;

template <typename E> class List { // List ADT
private:
void operator =(const List&) {} // Protect assignment
List(const List&) {} // Protect copy constructor
public:
List() {} // Default constructor
virtual ˜List() {} // Base destructor
// Clear contents from the list, to make it empty.
virtual void clear() = 0;
// Insert an element at the current location.
// item: The element to be inserted
virtual void insert(const E& item) = 0;
// Append an element at the end of the list.
// item: The element to be appended.
virtual void append(const E& item) = 0;
// Remove and return the current element.
// Return: the element that was removed.
virtual E remove() = 0;
// Set the current position to the start of the list
virtual void moveToStart() = 0;
// Set the current position to the end of the list
virtual void moveToEnd() = 0;
// Move the current position one step left. No change
// if already at beginning.
virtual void prev() = 0;
// Move the current position one step right. No change
// if already at end.
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


template <typename E> class Link {
public:
    E element; // Value for this node
    Link *next; // Pointer to next node in list
    // Constructors
    Link(const E& elemval, Link* nextval =NULL)
    { element = elemval; next = nextval; }
    Link(Link* nextval =NULL) { next = nextval; }
};
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
        void insertBefore(const E& v, const E& k) {
            Link<E>* tmp = head;
            while (tmp->next != NULL) {
                if (tmp->next->element == k) {
                    tmp->next = new Link<E>(v, tmp->next);
                    curr = tmp;
                    return;
                }
                tmp = tmp->next;
            }
        }
        void print() const; 
};

template <typename E> 
void LList<E>:: print() const {
    Link<E> *tmp = head;
    bool first = true;
    cout << "< ";
    while (tmp != NULL) {
        if (!first) cout << tmp->element << " ";
        if (tmp == curr) cout << "| ";
        first = false;
        tmp = tmp->next;
    }
    cout << ">";
}

int main()
{
   
    return 0;
}