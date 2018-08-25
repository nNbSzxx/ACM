#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    while (t --) {
        int p;
        scanf("%d", &p);
        for (int i = 0; i < p; i ++) {
            printf("%d", (i + 0) % p);
            for (int j = 1; j < p; j ++) {
                printf(" %d", (i + j) % p);
            }
            puts("");
        }
        for (int i = 0; i < p; i ++) {
            printf("0");
            for (int j = 1; j < p; j ++) {
                printf(" %d", (i * j) % p);
            }
            puts("");
        }
    }
    return 0;
}
