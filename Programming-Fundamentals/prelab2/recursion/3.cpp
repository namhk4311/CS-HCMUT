/*
Given a positive number, print following a pattern without using any loop.

Input: n = 16

Output: 16, 11, 6, 1, -4, 1, 6, 11, 16 (has no space at the end)

Input: n = 10

Output: 10, 5, 0, 5, 10 (has no space at the end)

We basically first reduce 5 one by one until we reach a negative or 0. After we reach 0 or negative, we one add 5 until we reach n.

Note: Please note that you can't using key work for, while, goto (even in variable names, comment).

You can implement other recursive functions if needed.

For this exercise, we have #include <iostream> and using namespace std;
*/

#include <iostream>
using namespace std;

bool negative_check = false, initial_num = false;
int a;

void printPattern(int n)
{
    if (initial_num == false){
        a = n; initial_num = true;
    }
    
	if (n > 0 && !negative_check) {
        cout << n << ", ";
        return printPattern(n - 5);
    } 
    else if (n < 0) {
        cout << n << ", ";
        negative_check = true;
        return printPattern(n + 5);
    }
    else if (n > 0 && negative_check && n <= a){
        if (n != a) cout << n << ", ";
        else cout << n;
        return printPattern(n + 5);
    }
}

int main()
{
    printPattern(16);
    return 0;
}