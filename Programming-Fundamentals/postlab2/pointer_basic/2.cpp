#include <iostream>
using namespace std;

void doi(int &x,int &y){
    int tam=y;
    y=x;
    x=tam;
}
void reverse(int *ptr, int n)
{
    for(int i=0;i<n/2;i++){
        doi(*(ptr+i),*(ptr+n-i-1));
    }
}

// void reverse(int *ptr, int n){
//     for (int i = 0; i < )
// }

int main()
{
    int a = 6, b = 8;
    doi(a,b);
    cout << a << " " << b << "\n";
    int ptr[] = {1,2,3,4,5};
    reverse(ptr,5);
    for (int i = 0; i < 5; i++){
        cout << ptr[i] << endl;
    }
    return 0;
}