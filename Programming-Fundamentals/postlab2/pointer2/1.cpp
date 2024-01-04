#include <bits/stdc++.h>
using namespace std;

int** insertCol(int**& matrix, int r, int c, int* colArr, int col) {
    // TODO
    int **kq=new int*[r];
    for(int i=0;i<r;i++){
        kq[i]=new int[c+1];
        for(int j=0;j<col;j++){
            kq[i][j]=matrix[i][j];
        }
        
        kq[i][col]=colArr[i];
        
        for(int j=col+1;j<c+1;j++){
            kq[i][j]=matrix[i][j-1];
        }
    }
    delete[] matrix;
    matrix=new int*[r];
    for(int i=0;i<r;i++){
        matrix[i]=new int [c+1];
        matrix[i]= kq[i];
    }
    delete[] kq;
    
    return matrix;
}

int main()
{
   
    return 0;
}