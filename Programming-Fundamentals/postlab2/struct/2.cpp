#include <bits/stdc++.h>
using namespace std;

struct SCP {
    int id;
};

void doi(SCP &z,SCP &y){
    SCP br=z;
    z=y;
    y=br;
}
SCP** sortDatabase(SCP** arr, int n) {
    // Student answer
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[j]->id >= arr[i]->id){
                doi(*arr[i],*arr[j]);
            }
        }
    }
    
    return arr;
}

int main()
{
   
    return 0;
}