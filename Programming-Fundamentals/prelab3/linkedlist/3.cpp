#include <iostream>
using namespace std;
struct node
{
  int data;
  node *next;
};
node *createLinkedList(int n)
{
    cout << "Start";
    node *tmp = nullptr;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        node *input = new node();
        input->data = x;
        input->next = nullptr;
        if (tmp == nullptr){
            tmp = input;
        }
        else {
            input->next = tmp;
            tmp = input;
        }
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