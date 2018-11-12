#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAX = 2e5 + 10;

int main()
{
    int n;
    char s[MAX];
    scanf("%d %s", &n, s);
    int ok = -1;
    for (int i = 0; i < n - 1; i ++) {
        if (s[i] > s[i + 1]) {
            ok = i;
            break;
        }
    }
    if (ok == -1) {
        ok = n - 1;
    }
    for (int i = 0; i < n; i ++) {
        if (i != ok) {
            printf("%c", s[i]);
        }
    }
    puts("");

    return 0;
}
