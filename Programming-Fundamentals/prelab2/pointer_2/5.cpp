/*
Given a dynamic two-dimensional array of size r x c. Implement the function void insertRow(int**& matrix, int r, int c, int* rowArr, int row) that can insert the rowArr array (with the size c) into the row position, row, of the matrix.

Input: The two-dimensional matrix of size r x c, the insert row rowArr and the insert position row.

Output: The two-dimensional matrix after insert.
*/
#include <bits/stdc++.h>
using namespace std;

void insertRow(int**& matrix, int r, int c, int* rowArr, int row) {
         int tmp[r][c];
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            tmp[i][j] = matrix[i][j];
        }
    }
    matrix = new int*[r + 1];
    for (int i = 0; i < r + 1; i++){
        matrix[i] = new int[c];
    }
    for (int i = 0; i < row; i++){
        for (int j = 0; j < c; j++){
            matrix[i][j] = tmp[i][j];
        }
    }
    for (int i = 0; i < c; i++){
        matrix[row][i] = rowArr[i];
    }
    if (row <= r + 1){
        for (int i = row + 1; i < r + 1; i++){
            for (int j = 0; j < c; j++){
                matrix[i][j] = tmp[i - 1][j];
            }
        }
    }
}

int main()
{
   
    return 0;
}