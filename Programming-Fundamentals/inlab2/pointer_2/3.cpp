#include <bits/stdc++.h>
using namespace std;

int* flatten(int** matrix, int r, int c) {
    int *tmp = new int[r*c];
    int cnt = 0;
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            if (cnt != r*c) tmp[cnt++] = matrix[i][j];
        }
    }
    return tmp;
}

int main()
{
     
    return 0;
}   