#include "sl.h"

int main() {
DLList<int> *lst = new DLList<int>();
int x[5] = {3,4,2,1,5};
int s  = sizeof(x)/sizeof(int);
for (int i =  0;  i < s;  i++) lst->insert(x[i]);
   {
    ;
    lst->moveToPos(2);
cout<<lst->removePre()<<endl;;
   }
    cout << SEPARATOR << endl;   {
    ;
    cout<<lst->removePre()<<endl;;
   }
    cout << SEPARATOR << endl;   {
    ;
    cout<<lst->removePre()<<endl;;
   }
        return 0;
}