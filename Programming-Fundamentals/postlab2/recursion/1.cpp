#include <bits/stdc++.h>
using namespace std;
    
bool palindromeRecursion(string s)
{
    // BEGIN YOUR IMPLEMENTATION [1]
    // TODO
    int len=s.length();
    if(len==0||len== 1){
        return true;
    }
    
    if(s[0]!=s[len-1]){
        return false;
    }
    
    s.erase(0,1);
    s.erase(len-2,1);
    return palindromeRecursion(s);
    // END YOUR EMPLEMENTATION [1]
}
int main()
{
   // hiddenCheck();
    // BEGIN YOUR IMPLEMENTATION [2]
    // TODO
   string temp[2]={"false","true"};
   string mau;
   while(cin>>mau){
       if(mau[0]=='*'){
           break;
       }
       else {
           //int num1=palindrome(mau);
           int num2=palindromeRecursion(mau);
           cout<<temp[num2]<<"\n";
       }
   }
    // END YOUR EMPLEMENTATION [2]
    return 0;
}