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

    int count(List<E> &L, E k) {
        int cnt = 0;
        for (L.moveToStart(); L.currPos() < L.length(); L.next()) {
            if (L.getValue() == K) ++cnt; 
        }
        return cnt;
    };
    void del(List<E> &L, E k){
            L.moveToStart();
            while (L.currPos() < L.length()) {
            if (L.getValue() == k) {
                L.remove();
            }
            else L.next();
        }
    }

    void DuplicationKiller(List<E> &L) {
        L.moveToStart();
        while (L.currPos() < L.length()) {
            E k = L.getValue();
            int prev_pos = L.currPos();
            bool check = false, first = false;
            while (L.currPos() < L.length()) {
                if (L.getValue() == k && first) {
                    L.remove();
                    check = true;
                }
                else L.next();
                first = true;
            }
            L.moveToPos(prev_pos);
            if (check) L.remove();
            else L.next();
        }
    }

    List<E>* merge(List<E>* in1, List<E>* in2) {
        List<E> *res = new List<E>();
        in1->moveToStart(), in2->moveToEnd();
        while (in1->currPos() < in1->length() && in2->currPos() < in2->length()) {
            if (in1->getValue() <= in2->getValue()) {
                res->insert(in1->getValue());
                in1->next();
            }
            else {
                res->insert(in2->getValue());
                in2->next();
            }
        }
        while (in1->currPos() < in1->length()) {
            res->insert(in1->getValue());
            in1->next();
        }
        while (in2->currPos() < in2->length()) {
            res->insert(in2->getValue());
            in2->next();
        }
        return res;
    };
}; 

int main()
{
   
    return 0;
}