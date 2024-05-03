int center;
void left(int n) {
    if (n <= 0) {
        cout << n << " ";
        center = n;
        return;
    }
    cout << n << " ";
    left(n - 5);
}

void right(int i, int n) {
    if (i == n) {
        cout << i;
        return;
    }
    cout << i << " ";
    right(i + 5, n);
}

void printPattern(int n) 
{ 
    /*  
     * STUDENT ANSWER
     */
    left(n);
    right(center + 5, n);
}