#include <bits/stdc++.h>
using namespace std;

bool isSymmetry(int *head, int *tail)
{
    if(tail==head){
        return true;
    }
    if(head==tail+1){
        return true;
    }
    bool kq= (*tail==*head);
    *head++;
    *tail--;
    return isSymmetry(head,tail) && kq;
}

int main()
{
    
    return 0;
}