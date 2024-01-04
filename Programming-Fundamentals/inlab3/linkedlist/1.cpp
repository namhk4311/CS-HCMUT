/*
Write a program where:
- struct node: represents a node in linkedlists
- functions createLinkedList:
    + Receive the size of a linked list (>0)
    + create a linked list with value from standard input (stdin) a new node is add to the  END  of the linked list
    + Return a pointer which points to the first node of the linked list.
- Function main reads the size of the linked list, calls function createLinkedList to Initialize the linked list, then call function print to print the linked list.
Complete function createLinkedList
Input:
size n of the linked list(0 < n < 5000)
following n numbers are values of each node in the linked list each number is an integers in (-5000; 5000)
Input:
Satisfy the requirements
*/
#include <iostream>
using namespace std;
struct node
{
  int data;
  node *next;
};
node *createLinkedList(int n)
{
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
}
void print(node *head)
{
  while (head != nullptr)
  {
    cout << head->data << endl;
    head = head->next;
  }
}
int main()
{
  int n = 0;
  cin >> n;
  if (n > 0)
  {
    node *head = createLinkedList(n);
    print(head);
  }
  else
  {
    cout << "Invalid n" << endl;
  }
  return 0;
}
