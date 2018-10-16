#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX = 110;

char s[MAX];
int n;

int main()
{
    scanf("%d %s", &n, s);
    int cnt8 = 0;
    for (int i = 0; i < n; i ++) {
        if (s[i] == '8') {
            ++ cnt8;
        }
    }
    printf("%d\n", min(cnt8, n / 11));
    return 0;
}
