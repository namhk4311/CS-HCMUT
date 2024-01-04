/*
Implement the function void deleteMatrix(int**& matrix, int r) that can free memory for a dynamic two-dimensional array consisting of r rows. matrix should be set to NULL after function's execution.
Input: The dynamic two-dimensional array, matrix, consists of r rows.
*/

#include <bits/stdc++.h>
using namespace std;

void deleteMatrix(int**& matrix, int r) {
    for (int i = 0; i < r; i++){
        delete [] matrix[i];
        matrix[i] = 0; // ????
    }
     delete [] matrix;   
     matrix = 0; //???
    // matrix = nullptr;
    //cout << *matrix << endl;
}

int main()
{
    int r = 3;
    int **matrix = new int*[r];
    for (int i = 0; i < r; i++)
    {
        matrix[i] = new int[2];
    }
    matrix[0][0] = 2; matrix[0][1] = 2;
    matrix[1][0] = 1; matrix[1][1] = 1;
    matrix[2][0] = 1; matrix[2][1] = 1;
    deleteMatrix(matrix,3);
    //cout << *matrix;
    if (matrix == nullptr) cout << "SUCCESSFUL";
    else cout << "FAILED";
    return 0;
}