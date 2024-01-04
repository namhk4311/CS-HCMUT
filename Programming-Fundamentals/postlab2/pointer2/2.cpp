#include <bits/stdc++.h>
using namespace std;

bool deleteRow(int**& matrix, int r, int c, int row) {
    // TODO
    if(row<0|| row>=r){
        return false;
    }
    if(r<=0||c<=0){
        return false;
    }
    if(r==1 && row==0){
        delete[] matrix[0];
        delete[] matrix;
        matrix= NULL;
        return true;
    }
    
    int **kq= new int*[r-1];
    for(int i=0;i<row;i++){
        kq[i]=new int[c];
        kq[i]=matrix[i];
    }
    for(int i=row+1;i<r;i++){
        kq[i-1]=new int[c];
        kq[i-1]=matrix[i];
    }
    matrix= nullptr;
    matrix=new int*[r-1];
    for(int i=0;i<r-1;i++){
        matrix[i]=new int[c];
        matrix[i]=kq[i];
    }
    kq=nullptr;
    return true;
}

int main()
{
   
    return 0;
}