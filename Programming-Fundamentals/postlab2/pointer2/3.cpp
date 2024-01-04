#include <bits/stdc++.h>
using namespace std;

bool deleteCol(int**& matrix, int r, int c, int col) {
    // TODO
    if(col<0 || col>=c){
        return false;
    }
    if(r<=0 || c<=0){
        return false;
    }
    
    if(col==0 && c==1){
        for(int i=0;i<r;i++){
            delete[] matrix[i];
        }
        delete[] matrix;
        matrix=NULL;
        return true;
    }
    int **kq=new int*[r];
    for(int i=0;i<r;i++){
        kq[i]=new int[c-1];
        for(int j=0;j<col;j++){
            kq[i][j]=matrix[i][j];
        }
        for(int j=col+1;j<c;j++){
            kq[i][j-1]=matrix[i][j];
        }
    }
    matrix=nullptr;
    matrix=new int*[r];
    for(int i=0;i<r;i++){
        matrix[i]=new int[c-1];
        matrix[i]=kq[i];
    }
    kq=nullptr;
    return true;
}

int main()
{
   
    return 0;
}