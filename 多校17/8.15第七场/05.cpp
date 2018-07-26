#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;


int main()
{
    int t;
    scanf("%d", &t);
    while (t --) {
        int a;
        scanf("%d", &a);
        printf("%d\n", (a + 1) / 2 + 1);
    }
    return 0;
}
