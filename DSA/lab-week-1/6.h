
void printArray(int n)
{
    /*  
     * STUDENT ANSWER
     */
    if (n == 0) {
        cout << 0;
        return;
    }
    printArray(n - 1);
    cout << ", " << n;
}

// Implement function 


// void printArray(int n){}
// to print 0, 1, 2, ..., n (n is positive integer and has no space at the end).

// Please note that you can't using key work for, while, goto (even in variable names, comment).


// For this exercise, we have #include <iostream> and using namespace std;