#include <iostream>
using namespace std;
struct node
{
  int data;
  node *next;
};
node *createLinkedList(int n); // The implementation is provided implicitly
void mergeList(node* head1, node* head2)
{
  // TODO
  if(head2 && head1)
  {
      node* tmp1=new node;
      tmp1=head1;
      while(tmp1->next){
          tmp1=tmp1->next;
      }
      tmp1->next=head2;
  }
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
  node *head = createLinkedList(n);
  int m;
  cin>>m;
  node *head1 = createLinkedList(m);
  mergeList(head, head1);
  print(head);
  return 0;
}
