/*
Write a recursive function

bool checkDuplicate(int* ar,int size)
{

  //Implement content in function  here


}

to check if all elements in an array are unique (meaning there are no identical value element). I.e {1,2,3,4,5} is unique, and {1,2,3,2,5} is not unique because it has two element with value 2.

Input:
Function checkDuplicate will receive an integer array with value between (-109; 109) and the size in [1; 104] and array size.

Output:
Return true if there is no identical element, else return false
*/

#include <bits/stdc++.h>
using namespace std;

bool checkDuplicate(int* ar,int size)
{
    if (size == 1) return true;
    int tmp;
    tmp = ar[size - 1];
    for (int i = 0; i < size - 1; i++){
        if (tmp == ar[i]) return false;
    }
    return checkDuplicate(ar, size - 1);
}

int main()
{
    int size; cin >> size;
    int ar[size];
    for (int &x : ar) cin >> x;
    (checkDuplicate(ar, size))? cout << "Not duplicate" : cout << "Duplicate";
    return 0;
}