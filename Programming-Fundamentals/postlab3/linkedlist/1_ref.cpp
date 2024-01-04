#include <iostream>
using namespace std;

struct node
{
  int data;
  node *next;
};

node *createLinkedList(int n){
    cout << "start" << endl;
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
node* evenThenOddLinkedList(node *head)
{
  //TODO
  if(head==nullptr){
      return nullptr;
  }
  
  node* numE=new node;
  numE=nullptr;
  node* numO=new node;
  numO=nullptr;
  node* tmpE=new node;
  node* tmpO=new node;
  
  while(head){
      if(head->data %2!=0){
          node* oddP=new node;
          oddP->data=head->data;
          oddP->next=nullptr;
          
          if(!numO){
              numO=oddP;
              tmpO=numO;
          }
          else
          {
            tmpO->next=oddP;
            tmpO=oddP;
          }
      }
      else{
          node* evenP=new node;
          evenP->data=head->data;
          evenP->next=nullptr;
          if(!numE){
              numE=evenP;
              tmpE=numE;
          }
          else
          {
              tmpE->next=evenP;
              tmpE=evenP;
          }
      }
      head=head->next;
  }
  if(!numE){
      return numO;
  }
  if(numO){
      tmpE->next=numO;
  }
  return numE;
}
void print(node *head)
{
  while (head != nullptr)
  {
    cout << head->data << " ";
    head = head->next;
  }
  cout<<endl;
}
int main()
{
  int n = 0;
  cin >> n;
  node *head = createLinkedList(n);
  print(head);
  head = evenThenOddLinkedList(head);
  print(head);
  return 0;
}
