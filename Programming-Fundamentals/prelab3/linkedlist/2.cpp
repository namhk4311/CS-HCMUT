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

int countNode(node* head)
{
    int cnt = 0;
    while (head != nullptr){
        ++cnt;
        head = head->next;
    }
    return cnt;
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
  print(head);
  cout<<endl;
  cout<<countNode(head);
  return 0;
}
