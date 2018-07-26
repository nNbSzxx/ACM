#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAX = 5e4 + 10;
const long long INF = 1000000000000L;
long long n, m;

inline long long cal(long long i, long long j)
{
	return i * i + 100000L * (i - j) + j * j + i * j;
}

long long count(long long num)
{
	long long cnt = 0;
	// 枚举列 
	for (int i = 1; i <= n; i ++) {
		int l = 1, r = n;
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (cal(mid, i) >= num) {
				r = mid - 1;
			} else {
				l = mid + 1;
			}
		}
		cnt += r;
	}
	return cnt;
}

long long bins()
{
	long long l = -INF, r = INF;
	while (l <= r) {
		long long mid = (l + r) >> 1;
//		printf("%lld\n", count(mid));
		if (count(mid) > m - 1) {
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}
	return r;
}

int main()
{
	int t;
	scanf("%d", &t);
	while (t --) {
		scanf("%lld%lld", &n, &m);
		// 矩阵中有m-1个数比当前数小，这些数字中最大值就是答案 
		long long ans = bins();
		printf("%lld\n", ans);
	}
	return 0;
}
