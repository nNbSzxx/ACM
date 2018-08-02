#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX = 10;
const int SIZE = 40;
// const int L = 5;
long long a[MAX];
long long mat[SIZE][SIZE];
long long block, col[20], row[20];
int l, q;

void init()
{
    int c = 0;
    for (int i = 0; i < SIZE; i ++) {
        for (int j = 0; j <= i; j ++) {
            mat[j][i - j] = a[c];
            c = (c + 1) % l;
        }
    }
    block = 0;
    long long sum = 0;
    for (int i = 0; i < 2 * l; i ++) {
        for (int j = 0; j < 2 * l; j ++) {
            block += mat[i][j];
            sum += mat[j][i];
        }
        row[i] = block;
        col[i] = sum;
    }
}

long long get(int x, int y)
{
    if (x < 0 || y < 0) {
        return 0;
    }
    long long ret = 0;
    int rsum = (x + 1) / (2 * l);
    int rleft = (x + 1) % (2 * l);
    int csum = (y + 1) / (2 * l);
    int cleft = (y + 1) % (2 * l);
    ret += 1LL * rsum * csum * block;
    if (rleft != 0)
        ret += 1LL * csum * row[rleft - 1];
    if (cleft != 0)
        ret += 1LL * rsum * col[cleft - 1];
    for (int i = 0; i < rleft; i ++) {
        for (int j = 0; j < cleft; j ++) {
            ret += mat[i][j];
        }
    }
    return ret;
}

int main()
{
    /* make table
    for (int i = 0; i < MAX; i ++) {
        a[i] = i;
    }
    int c = 0;
    memset(mat, -1, sizeof mat);
    for (int i = 0; i < SIZE; i ++) {
        for (int j = 0; j <= i; j ++) {
            mat[j][i - j] = a[c];
            c = (c + 1) % L;
        }
    }
    for (int i = 0; i < SIZE; i ++) {
        for (int j = 0; j < SIZE; j ++) {
            if (i == 19 && j == 19) {
                printf("* ");
            } else
                printf("%lld ", mat[i][j]);
        }
        puts("");
    }
    */

    int t;
    scanf("%d", &t);
    while (t --) {
        scanf("%d", &l);
        for (int i = 0; i < l; i ++) {
            scanf("%lld", &a[i]);
        }
        init();
        scanf("%d", &q);
        while (q --) {
            int x0, y0, x1, y1;
            scanf("%d%d%d%d", &x0, &y0, &x1, &y1);
            long long ans = 0;
            ans += get(x1, y1);
            //printf("+ %d %d %lld\n", x1, y1, get(x1, y1));
            ans -= get(x1, y0 - 1);
            //printf("- %d %d %lld\n", x1, y0 - 1, get(x1, y0 - 1));
            ans -= get(x0 - 1, y1);
            //printf("- %d %d %lld\n", x0 - 1, y1, get(x0 - 1, y1));
            ans += get(x0 - 1, y0 - 1);
            //printf("+ %d %d %lld\n", x0 - 1, y0 - 1, get(x0 - 1, y0 - 1));
            printf("%lld\n", ans);
        }
    }

    return 0;
}
