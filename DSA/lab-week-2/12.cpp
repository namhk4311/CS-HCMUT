

long long nthNiceNumber(int n) {
    queue<long long> q;
    q.push(2);
    q.push(5);

    long long niceNumber = 0;

    while (n > 0) {
        niceNumber = q.front();
        q.pop();

        q.push(niceNumber * 10 + 2);
        q.push(niceNumber * 10 + 5);

        n--;
    }

    return niceNumber;
}