/*
Given a string, implement function

int strLen(char* str){}
to calculate length of the string using recursion.

Please note that you can't using key work for, while, goto (even in variable names, comment).
*/

#include <iostream>
using namespace std;

int i = 0;

int strLen(char* str)     
{ 
    if (str[i] != '\0') {i++; return 1 + strLen(str);}
    return 0;
}

int recLen(char* str)   
{
    // if we reach at the end of the string
    if (*str == '\0')
        return 0;
    else
        return 1 + recLen(str + 1);
}

int main()
{
    char str[] = "Truong DH Bach Khoa";
    cout << recLen(str);
    return 0;
}