/*
Write a program where:
- struct node: represents a node in linkedlists
- functions createLinkedList:
    + Receive the size of a linked list (>0)
    + create a linked list with value from standard input (stdin) a new node is add to the  END  of the linked list
    + Return a pointer which points to the first node of the linked list.
- Function isEqual compare two linked list:
   + Receive the pointer head1 of the 1st linked list , pointer head2 of the 2nd linked list
   + Return true if and only if 2 the linked lists have indentical size, and node value. Otherwise, return false.
- Function main reads the size of the linked list, calls function createLinkedList to Initialize the linked list, then call functdion print to print all the node's values of the linked list.
Complete function isEqual 
Input: 
The value input from standard input (stdin) with value in (0; 5000)
*/

#include <iostream>
using namespace std;
struct node
{
  int data;
  node *next;
};

node *createLinkedList(int n){
    cout << "Start" << endl;
    node *tmp = nullptr;
    int x;
    for (int i = 0; i < n; i++){
        node *p = new node();
        cin >> x;
        p->data = x;
        p->next = nullptr;
        if (tmp == nullptr){
            tmp = p;
        }
        else {
            node *s = tmp;
            while(s->next != nullptr){
                s = s->next;
            }
            s->next = p;
        }
        //delete [] p;
    }
    return tmp;
}; // The implementation is provided implicitly


bool isEqual(node *head1, node *head2)
{
    node *size1 = head1; int size_1 = 0;
    node *size2 = head2; int size_2 = 0;
    while(size1 != nullptr){
        ++size_1;
        size1 = size1->next;
    }
    while(size2 != nullptr){
        ++size_2;
        size2 = size2->next;
    }
    if (size_1 != size_2) return false; 
    while(head1 != nullptr){
        if(head1->data != head2->data) return false;
        head1 = head1->next;
        head2 = head2->next;
    }
    return true;
}

// void print(node *a){
//     while(a != nullptr){
//         cout << a->data << " ";
//         a = a->next;
//     }
//     cout << endl;
//     cout <<"-----------------------------------------------------";
//     cout << endl;
// }

int main()
{
  int n = 0;
  cin>> n;
  node *head1 = createLinkedList(n);
  int m = 0;
  cin>> m;
  node *head2 = createLinkedList(m);
  //print(head1);
  //print(head2);
  cout << isEqual(head1, head2) << endl;
  return 0;
}
