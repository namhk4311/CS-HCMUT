#include "main.h"
#include "Stack_Queue.h"
#include "implement.h"

int main() {
    //ex2();
    void(*func)(int);
    func = [](int a) {std::cout << a << std::endl;};
    func(1);
}