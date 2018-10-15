#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;

char s[100010];

int main()
{
    int n;
    scanf("%d", &n);
    scanf(" %s", s);
    sort(s, s + n);
    puts(s);
    return 0;
}
