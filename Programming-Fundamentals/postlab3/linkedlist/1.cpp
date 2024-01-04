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
        node *tmp = head; int size = 0;
        while (tmp != nullptr){
            ++size;
            tmp = tmp->next;
        }

        node *tmp_even =  head; int size_even = 0;
        while (tmp_even != nullptr){
            if (tmp_even->data % 2 == 0) ++size_even;
            tmp_even = tmp_even->next;
        }
        
        node *tmp_odd = head; int size_odd = 0;
        while (tmp_odd != nullptr){
            if (tmp_odd->data % 2 != 0) ++size_odd;
            tmp_odd = tmp_odd->next;
        }

        //cout << size_odd << "&";
        //int arr[sizehead];
        //node *anothertmp = head;
        node *checkeven = nullptr;
        node *checkodd = nullptr;
        node *eventhenodd = nullptr;
        // for (int i = 0; i < size_even; i++){
        //     if (eventhenodd == nullptr){
        //         if (checkeven->data % 2 != 0){
        //             while (checkeven->data % 2 != 0){
        //                 checkeven = checkeven->next;
        //             }
        //         }
        //         //cout << "haha";
        //         node *copy_even = new node();
        //         copy_even->data = checkeven->data;
        //         copy_even->next = nullptr;
        //         eventhenodd = copy_even;
        //         checkeven = checkeven->next;
        //     }
        //     else {
        //         node *p = eventhenodd;
        //         while (p->next != nullptr){
        //             p = p->next;
        //         }
        //         if (checkeven->data % 2 != 0){
        //             while (checkeven->data % 2 != 0){
        //                 checkeven = checkeven->next;
        //             }
        //         }
        //         node *copyeven = new node();
        //         copyeven->data = checkeven->data;
        //         copyeven->next = nullptr;
        //         p->next = copyeven; 
        //         checkeven = checkeven->next;
        //     }
        // }
        // for (int i = 0; i < size_odd; i++){
        //     node *k = eventhenodd;
        //     while (k->next != nullptr){
        //         k = k->next;
        //     }
        //     if (checkodd->data % 2 == 0){
        //         while (checkodd->data % 2 == 0){
        //             checkodd = checkodd->next;
        //         }
        //     }
        //     node *copyodd = new node();
        //     copyodd->data = checkodd->data;
        //     copyodd->next = nullptr;
        //     k->next = copyodd;
        //     checkodd = checkodd->next;
        // }
        node *tmpe = head;
        for (int i = 1; i <= size_even; i++){
            if (tmpe->data % 2 != 0){
                while(tmpe->data % 2 != 0){
                    tmpe = tmpe->next;
                }
            }
            node *copy_even = new node();
            if (checkeven == nullptr){
                copy_even->data = tmpe->data;
                copy_even->next = nullptr;
                checkeven = copy_even;
            }
            else {
                node *p = checkeven;
                while (p->next != nullptr){
                    p = p->next;
                }
                copy_even->data = tmpe->data;
                copy_even->next = nullptr;
                p->next = copy_even;
            }
            tmpe = tmpe->next;
        }
        node *tmpo = head;
        for (int i = 1; i <= size_odd; i++){
            if (tmpo->data % 2 == 0){
                while(tmpo->data % 2 == 0){
                    tmpo = tmpo->next;
                }
            }
            node *copy_odd = new node();
            if (checkodd == nullptr){
                copy_odd->data = tmpo->data;
                copy_odd->next = nullptr;
                checkodd = copy_odd;
            }
            else {
                node *k = checkodd;
                while (k->next != nullptr){
                    k = k->next;
                }
                copy_odd->data = tmpo->data;
                copy_odd->next = nullptr;
                k->next = copy_odd;
            }
            tmpo = tmpo->next;
        }
        //cout << size_odd << " " << size_even << endl;
        
        while (size_even || size_odd){
            //cout << "hello"  << endl;
            if (eventhenodd == nullptr){
                node *initial = new node();
                if (checkeven != nullptr){
                    --size_even;
                    
                    initial->data = checkeven->data;
                    initial->next = nullptr; 
                    eventhenodd = initial;
                    checkeven = checkeven->next;
                    //cout << checkeven->data << " " << endl;
                    // if (checkeven == nullptr){
                    //     cout << "true";
                    // } 
                }
                else if (checkodd != nullptr){
                    --size_odd;
                    //if (eventhenodd != nullptr) eventhenodd = eventhenodd->next;
                    initial->data = checkodd->data;
                    initial->next = nullptr; 
                    eventhenodd = initial;
                    checkodd = checkodd->next;
                }
            }
            else {
                node *anothercopy = eventhenodd;
                while (anothercopy->next != nullptr){
                    anothercopy = anothercopy->next;
                }
                node *anothercopy2; 
                //cout << size_odd << endl;
                if (checkeven != nullptr && anothercopy->data % 2 != 0 || size_odd == 0){
                    --size_even;
                    //if (size_even < 0) break;
                    anothercopy2 = new node();
                    anothercopy2->data = checkeven->data;
                    anothercopy2->next = nullptr;
                    anothercopy->next = anothercopy2;
                    
                    checkeven = checkeven->next;
                }
                else if (checkodd != nullptr){
                    --size_odd;
                    //if (size_odd < 0) break;
                    anothercopy2 = new node();
                    anothercopy2->data = checkodd->data;
                    anothercopy2->next = nullptr; 
                    //if (anothercopy != nullptr) anothercopy = anothercopy->next;
                    anothercopy->next = anothercopy2;
                    checkodd = checkodd->next;
                }
            }
            
        }
        return eventhenodd;
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