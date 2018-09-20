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

// 统计区间l到r中小于等于x的数字的个数
int Count(int l, int r, int x)
{
    int cnt = 0;
    int bound;

    // 首先处理区间l到r没有完全覆盖整个桶的部分，这部分暴力的查找
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

    // 然后处理区间内的每个桶，由于桶内是有序的，故可以二分找到小于等于x的数的个数
    if (l <= r) {
        int beg = l / size;
        int ed = r / size;
        for (int i = beg; i <= ed; i ++) {
            cnt += upper_bound(bucket[i], bucket[i] + size, x) - (bucket[i]);
        }
    }

    return cnt;
}

int main()
{
    while (~scanf("%d%d", &n, &m)) {
        size = sqrt(n * log2(n));
        if (size == 0)
            size = 1;
        num = n / size;
        for (int i = 0; i < n; i ++) {
            scanf("%d", &a[i]);
            sorted[i] = a[i];
        }
        sort(sorted, sorted + n);

        // 分桶，并在每个桶内排序
        for (int i = 0, cnt = 0; i < num; i ++) {
            for (int j = 0; j < size; j ++, cnt ++) {
                bucket[i][j] = a[cnt];
            }
            sort(bucket[i], bucket[i] + size);
        }

        // 核心思想是二分找到区间中 恰有k个数字小于等于sorted[mid] 中最小的那个，这样sorted[mid]就是答案
        while (m --) {
            int left, right, k;
            scanf("%d%d%d", &left, &right, &k);
            -- left;
            -- right;
            int l = 0, r = n - 1, mid, ret = -1;
            while (l <= r) {
                mid = (l + r) >> 1;
                int num = Count(left, right, sorted[mid]);
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
