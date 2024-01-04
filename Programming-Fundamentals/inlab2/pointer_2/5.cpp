#include <bits/stdc++.h>
using namespace std;

int** transposeMatrix(int** matrix, int r, int c) {
    int **tmp = new int*[c];
    for (int i = 0; i < c; i++) tmp[i] = new int [r];
    for (int i = 0; i < c; i++){
        for (int j = 0; j < r; j++){
            tmp[i][j] = matrix[j][i]; 
        }
    }
    return tmp;
}

int main()
{
   
    return 0;
}