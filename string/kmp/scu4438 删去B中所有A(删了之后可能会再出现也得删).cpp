#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX = 5e6 + 10;

char a[MAX], b[MAX];
int l1, l2, nt[MAX];
int pre[MAX], post[MAX];

void init()
{
    pre[0] = -1;
    post[0] = 1;
    pre[l2 + 1] = l2;
    post[l2 + 1] = -1;
    for (int i = 1; i <= l2; i ++) {
        pre[i] = i - 1;
        post[i] = i + 1;
    }
}

void erase(int x)
{
    post[pre[x]] = post[x];
    pre[post[x]] = pre[x];
}

void getNt()
{
    memset(nt, 0, sizeof nt);
    nt[0] = -1;
    int i = 0, j = -1;
    while (i < l1) {
        if (j == -1 || a[i] == a[j]) {
            nt[++ i] = ++ j;
        } else {
            j = nt[j];
        }
    }
}

int erasek(int x)
{
    int ret = x;
    ++ x;
    x = pre[x];
    for (int i = 0; i < l1; i ++) {
        int t = pre[x];
        erase(x);
        x = t;
    }
    if (x == 0) {
        return ret;
    } else {
        for (int i = 0; i < l1 - 1; i ++) {
            if (pre[x] != 0) {
                x = pre[x];
            } else {
                break;
            }
        }
    }
    return x - 1;
}

void kmp()
{
    int i = 0, j = 0;
    while (i < l2) {
        if (j == -1 || a[j] == b[i]) {
            i = post[i + 1] - 1;
            j ++;
        } else {
            j = nt[j];
        }
        if (j == l1) {
            i = erasek(i);
            j = 0;
        }
    }
}

int main()
{
    while (~scanf(" %s %s", a, b)) {
        l1 = strlen(a);
        l2 = strlen(b);
        init();
        getNt();
        kmp();
        int i = 0;
        while (true) {
            i = post[i];
            if (i == l2 + 1) {
                break;
            }
            putchar(b[i - 1]);
        }
        puts("");
    }
    return 0;
}

/*
abc
aaabcbc
b
bbb
abc
ab
*/
