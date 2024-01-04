#include <bits/stdc++.h>
using namespace std;

struct SCP {
    int objClass;
};

int compareObjectClass(const SCP &objA, const SCP &objB) {
    // Student answer
    if(objA.objClass< objB.objClass){
        return -1;
    }
    else if(objA.objClass== objB.objClass){
        return 0;
    }
    else {
        return 1;
    }
}

int main()
{
   
    return 0;
}