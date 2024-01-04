#include <bits/stdc++.h>
using namespace std;

char* concatStr(char* str1, char* str2) {
    char *tmp = new char[strlen(str1) + strlen(str2)];
    int cnt = 0;
    for (int i = 0; i < strlen(str1); i++) tmp[cnt++] = str1[i];
    for (int i = 0; i < strlen(str2); i++) tmp[cnt++] = str2[i];
    tmp[cnt] = '\0';
    return tmp; 
}

int main()
{
    char s1[] = "Hello, ";
    char s2[] = "how are you?";
    char* s = concatStr(s1, s2);
    cout << s;
    delete[] s;
    return 0;
}