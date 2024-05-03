#include <bits/stdc++.h>

using namespace std;
    
typedef struct Item* ptr;

struct Item
{
    double coef; // coefficient
    int exp; // exponent
    ptr next;
};

ptr makeNode(double x, int y) {
    ptr tmp = new Item();
    tmp->coef = x;
    tmp->exp = y;
    return tmp;
}

int Size(ptr a) {
    int cnt = 0;
    while (a != NULL) {
        ++cnt;
        a = a->next;
    }
    return cnt;
}

void insertFirst(ptr &a, double x, int y) {
    ptr tmp = makeNode(x, y);
    if (a == NULL) {
        a = tmp;
    }
    else {
        tmp->next = a;
        a = tmp;
    }
}

void insertLast(ptr &a, double x, int y) {
    ptr tmp = makeNode(x, y);
    if (a == NULL) {
        a = tmp;
    }
    else {
        ptr p = a;
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = tmp;
    }
}

void insertMid(ptr &a, double x, int y, int pos) {
    int n = Size(a);
    if (pos <= 0 || pos > n + 1) return;
    if (n == 1) {
        insertFirst(a, x, y);
        return;
    } 
    else if (n == pos) {
        insertLast(a, x, y);
        return;
    }
    ptr p = a;
    for (int i = 1; i < pos - 1; i++) {
        p = p->next;
    }
    ptr tmp = makeNode(x, y);
    tmp->next = p->next;
    p->next = tmp;
}

void deleteFirst(ptr &a) {
    if (a == NULL) return;
    a = a->next;
}

void deleteLast(ptr &a) {
    if (a == NULL) return;
    ptr prev = NULL, cur = a;
    while (cur->next != NULL) {
        prev = cur;
        cur = cur->next;
    }
    if (prev == NULL) a = NULL;
    else {
        prev->next = NULL;
    }
}

void deleteMid(ptr &a, int pos) {
    if (pos <= 0 || pos > Size(a) + 1) return;
    if (Size(a) == 1) {
        deleteFirst(a);
        return;
    } 
    else if (Size(a) == pos) {
        deleteLast(a);
        return;
    }
    ptr prev = NULL, cur = a;
    for (int i = 1; i < pos; i++) {
        prev = cur;
        cur = cur->next;
    }
    if (prev == NULL) a = a->next;
    else {
        prev->next = cur->next;
    }
}

void normalizePolynomial(ptr& first) {
    ptr tmp = first;
    ptr res = NULL;
    while (1) {
        ptr cal = tmp;
        int head_exp = cal->exp, cnt = 2;
        if (head_exp < 0) {
            first = NULL;
            return;
        }
        double sumCoef =  cal->coef;
        cal = cal->next; bool check = false;
        while (cal != NULL) {
            if (cal->exp == head_exp) {
                sumCoef += cal->coef;
                if (sumCoef == 0) {
                    deleteMid(tmp, cnt);
                }
                else {
                    deleteMid(tmp, cnt);
                    insertMid(tmp, sumCoef, head_exp, cnt);
                }
                deleteFirst(tmp);
                check = true;
                break;
            }
            cal = cal->next;
            cnt++;
        }
        if (!check) {
            if (res == NULL) insertFirst(res, tmp->coef, tmp->exp);
            else {
                if (res->exp > tmp->exp) insertFirst(res, tmp->coef, tmp->exp);
                else if (res->next != NULL) {
                    ptr tmp2 = res;
                    int count = 2; bool inserted = false;
                    while (tmp2->next != NULL) {
                        if (tmp2->exp < tmp->exp && tmp->exp < tmp2->next->exp) {
                            insertMid(tmp2, tmp->coef, tmp->exp, count);
                            inserted = true;
                            break;
                        }
                        tmp2 = tmp2->next;
                    }
                    if (!inserted) insertLast(tmp2, tmp->coef, tmp->exp);
                }
                else {
                    insertLast(res, tmp->coef, tmp->exp);
                }
            }
            deleteFirst(tmp);
        } 
        if (tmp == NULL) break;
    }
    first = res;
}

int main()
{

    return 0;
}