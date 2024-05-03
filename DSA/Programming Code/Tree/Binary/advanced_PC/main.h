#ifndef _MAIN_H
#define _MAIN_H

#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int defaultSize = 50;


void Assert(bool val, string s) {
    if (!val) { // Assertion failed -- close the program 
        cout << "Assertion Failed: " << s << endl;
        exit(-1); }
}

#endif