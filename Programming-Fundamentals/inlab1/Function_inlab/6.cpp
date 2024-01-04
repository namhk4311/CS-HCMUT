#include <bits/stdc++.h>
using namespace std;

int numberOfDiffCharac(string str){
    //int count = 1; 
    string tmp = "";
    int length_str = str.length();
    int length_tmp = 0;
    for (int i = 0; i < length_str; i++){
        if (i == 0) {
            tmp += str[i];
            length_tmp = tmp.length();
        }
        else {
            bool flag = true;
            for (int j = 0; j < length_tmp; j++){
                if (str[i] == tmp[j]) {
                    flag = false;
                    break;
                } 
            }
            if (flag) tmp += str[i];
            length_tmp = tmp.length();
        }
    }
    return length_tmp;
}

int main()
{
    //char str[] = "abbbbc";
    char str[] ="ababbba";
    printf("%d", numberOfDiffCharac(str));
}