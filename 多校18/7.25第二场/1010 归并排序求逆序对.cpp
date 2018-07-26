#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAX = 1e5 + 10;
int n, x, y;
int num[MAX], temp[MAX];

/**
 * @brief 归并排序
 * @details 对 a[l...r] 进行排序，并求逆序对个数
 *
 * @param a 原数组
 * @param tmp 临时数组
 * @param cnt 逆序对个数
 */

void mergeSort(int a[], int tmp[], int l, int r, long long &cnt) {
	if (l < r) {
		int m = (l + r) >> 1;
		mergeSort(a, tmp, l, m, cnt);
		mergeSort(a, tmp, m + 1, r, cnt);
        int i = l;
        int j = m + 1;
        int k = l;
        while (i <= m && j <= r) {
            if (a[i] > a[j]) {
                tmp[k++] = a[j++];
                cnt += m - i + 1;
            }
            else
                tmp[k++] = a[i++];
        }
        while (i <= m) tmp[k++] = a[i++];
        while (j <= r) tmp[k++] = a[j++];
        for (int fi = l; fi <= r; ++fi)
            a[fi] = tmp[fi];
	}
}



int main()
{
    while (~scanf("%d", &n)) {
        scanf("%d%d", &x, &y);
        for (int i = 1; i <= n; i ++) {
            scanf("%d", &num[i]);
        }
        long long cnt = 0;
        mergeSort(num, temp, 1, n, cnt);
        printf("%lld\n", cnt * min(x, y));
    }
    return 0;
}
