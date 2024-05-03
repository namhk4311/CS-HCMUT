#include <iostream>
#include <assert.h>
#include "Linklist.h"
#include "stack.h"
#include "Array_based_stacks.h"
#include "LLStack.h"


void stack1() {
    AStack<int> listStack;
    listStack.push(1);
    listStack.push(3);
    listStack.push(4);
    listStack.push(5);
    int a = listStack.pop();  
    std::cout << a << std::endl;
    std::cout << listStack.topValue() << " " << listStack.length();
}

void stack2() {
    LStack<int> LLs;
    LLs.push(4);
    LLs.push(1);
    LLs.push(3);
    LLs.push(5);
    std::cout << LLs.topValue();
}

int main() {
    stack2();
}
