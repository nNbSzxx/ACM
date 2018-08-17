#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n;
char a[10][10];

void C(int id)
{
    -- id;
    int c1 = (1 + (id & 1));
    int c2 = (2 + (id & 1));
    int r1 = 1 + ((id >> 1) & 1);
    int r2 = 2 + ((id >> 1) & 1);
    int temp = a[r1][c1];
    a[r1][c1] = a[r2][c1];
    a[r2][c1] = a[r2][c2];
    a[r2][c2] = a[r1][c2];
    a[r1][c2] = temp;
}

void R(int id)
{
    -- id;
    int c1 = (1 + (id & 1));
    int c2 = (2 + (id & 1));
    int r1 = 1 + ((id >> 1) & 1);
    int r2 = 2 + ((id >> 1) & 1);
    int temp = a[r1][c1];
    a[r1][c1] = a[r1][c2];
    a[r1][c2] = a[r2][c2];
    a[r2][c2] = a[r2][c1];
    a[r2][c1] = temp;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t --) {
        scanf("%d", &n);
        for (int i = 1; i <= 3; i ++) {
            for (int j = 1; j <= 3; j ++) {
                scanf(" %c", &a[i][j]);
            }
        }
        while (n --) {
            int id;
            char tp[2];
            scanf("%s", &tp);
            if (tp[1] == 'C') {
                C(tp[0] - '0');
            } else {
                R(tp[0] - '0');
            }
        }
        for (int i = 1; i <= 3; i ++) {
            for (int j = 1; j <= 3; j ++) {
                printf("%c", a[i][j]);
            }
            puts("");
        }
    }

    return 0;
}
