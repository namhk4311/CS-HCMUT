/*
A function that finds the greatest common divisor of two positive integers can be written through simple recursion and looping. You write the function gcdRecursion to perform the greatest common divisor by recursion and the function gcdIteration to find the greatest common divisor by loop.

Input:

Two integers p, q respectively (1 ≤ p,q < 109).

Output:

The gcdRecursion and gcdIteration functions return the greatest common divisor of p, q, respectively.

*/
#include<iostream>
#include<string>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
using namespace std;

int gcdRecursion(int p, int q)
{
    if (p < q) return gcdRecursion(q, p);
    else if (q == 0) return p;
    return gcdRecursion(q, p % q);
}

int gcdIteration(int p, int q)
{
    int r;
    while (q != 0){
        r = p % q;
        p = q;
        q = r;
    }
    return p;
}

int main()
{
    int p, q; cin >> p >> q;
    cout << gcdRecursion(p, q) << " " << gcdIteration(p, q);
    return 0;
}