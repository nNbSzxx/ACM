#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
const int MAX = 1e5 + 10;
int a[MAX];
int sorted[MAX];
int bucket[MAX / 10][MAX / 10];
int n, m;
int num, size;

int Count(int l, int r, int x)
{
    int cnt = 0;
    int bound;
    if (l % size != 0) {
        bound = (l / size + 1) * size;

        while (l <= r && l < bound) {
            if (a[l] <= x) {
                ++ cnt;
            }
            ++ l;
        }
    }

    if ((r + 1) % size != 0) {
        bound = (r / size) * size;
        while (l <= r && r >= bound) {
            if (a[r] <= x) {
                ++ cnt;
            }
            -- r;
        }
    }
    if (l <= r) {
        int beg = l / size;
        int ed = r / size;
        //printf("l r x cnt: %d %d %d %d\n", l, r, x, cnt);
        for (int i = beg; i <= ed; i ++) {
            cnt += upper_bound(bucket[i], bucket[i] + size, x) - (bucket[i]);
        }
    }

    //printf("l r x cnt: %d %d %d %d\n", l, r, x, cnt);
    return cnt;
}

int main()
{
    while (~scanf("%d%d", &n, &m)) {
        size = sqrt(n * log2(n));
        if (size == 0)
            size = 1;
        //printf("size: %d\n", size);
        num = n / size;
        for (int i = 0; i < n; i ++) {
            scanf("%d", &a[i]);
            sorted[i] = a[i];
        }
        sort(sorted, sorted + n);

        for (int i = 0, cnt = 0; i < num; i ++) {
            for (int j = 0; j < size; j ++, cnt ++) {
                bucket[i][j] = a[cnt];
            }
            sort(bucket[i], bucket[i] + size);
        }

        while (m --) {
            int left, right, k;
            scanf("%d%d%d", &left, &right, &k);
            -- left;
            -- right;
            int l = 0, r = n - 1, mid, ret = -1;
            while (l <= r) {
                mid = (l + r) >> 1;
                //printf("%d %d %d\n", l, r, mid);
                int num = Count(left, right, sorted[mid]);
                //printf("sum: %d\n", num);
                if (num <= k - 1) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
            printf("%d\n", sorted[l]);
        }

    }

    return 0;
}
