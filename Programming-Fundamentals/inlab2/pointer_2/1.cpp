#include <bits/stdc++.h>
using namespace std;

int** readArray()
{
    int** a = new int*[10];
   for (int i = 0; i < 10; i++) a[i] = new int[10];
   
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            cin >> a[i][j];
            if (a[i][j] == 0){
                int k = j + 1;
                while (k < 10){
                    a[i][k++] = 0;
                }
                break;
            }
        }
    }
   
   return a;
}

int main()
{
    readArray(); //?????
    return 0;
}