#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstring>
using namespace std;

int main()
{
	int t, n, m, k, a[110];
	scanf("%d", &t);
	while (t --) {
		scanf("%d%d%d", &n, &m, &k);
		if (k <= 0 || m <= 0) {
			printf("\n");
			continue;
		}
		if (k > n || m > n) {
			printf("\n");
			continue;
		}
		if (n == 3 && (k == 1 && m == 2 || m == 1 && k == 2)) {
			printf("\n");
			continue;
		}
		if (n == 1) {
			printf("1\n");
			continue;
		}
		if (n == 3 && k == 1 && m == 3) {
			puts("1 2 3");
			continue;
		}
		if (n == 3 && k == 3 && m == 1) {
			puts("3 2 1");
			continue;
		}
		int fflag = 0;
		for (int ii = 1; ii <= m ; ii ++)
		{
			int cnt = 0;
		
			for (int i = 1; i <= m - ii; i ++) {
				a[++ cnt] = i;
			}
			int sum = cnt;
//			printf("%d : %d \n", ii, cnt);
			if (n - sum < k) {
				continue;
			}
			
			int loc = n;
			int time = 1;
			int key ;
			while (k < n - cnt) {
				int i;
				for (i = n - time * k + 1; i <= n - (time - 1) * k; i ++) {
					a[i] = n + n - i - time * k + 1 - (time - 1) * k;
					++ cnt;
				}
				loc = n - time * k;
				-- i;
				key = 2 * n - i - time * k - (time - 1) * k;
				++ time;
			}
				
			for (int i = sum + 1; i <= loc; i ++) {
				a[i] = key --;
			}
			++ key;
			if (sum == 0) a[sum] = 0;
			if (a[sum] + 1 != key || time != ii) {
//				printf("%d %d\n", time, ii);
//				printf("%d %d\n", a[sum], key);
//				printf("%d\n", sum);
				continue;
			}
			fflag = 1;
			printf("%d", a[1]);
			for (int i = 2; i <= n ; i ++) {
				printf(" %d", a[i]);
			}
			printf("\n");
			break;
		}
		if (!fflag) {
			printf("\n");
		}
	}
	return 0;
}
