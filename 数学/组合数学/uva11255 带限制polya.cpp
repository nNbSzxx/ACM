#include <bits/stdc++.h>
using namespace std;
int tc, a, b, d, n, color[5], t[5];
long long c[45][45];

void init()
{
	for (int i = 0; i <= 40; i ++) {
		c[i][0] = c[i][i] = 1;
		for (int j = 1; j < i; j ++) {
			c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
		}
	}
	return ;
}

int gcd(int a, int b)
{
	int r;
	while (b) {
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}

long long cal(int k)
{
	int m = 0;
	long long ret = 1;
	for (int i = 1; i <= 3; i ++) {
		if (t[i] % k == 0) {
			t[i] /= k;
			m += t[i];
		} else {
			return 0;
		}
	}
	for (int i = 1; i <= 3; i ++) {
		ret *= c[m][t[i]];
		m -= t[i];
	}
	return ret; 
}

long long polya()
{
	long long ans = 0;
	for (int i = 1; i <= n; i ++) {
		memcpy(t, color, sizeof color);
		ans += cal(n / gcd(n, i));
	}
	if (n & 1) {
		for (int i = 1; i <= 3; i ++) {
			memcpy(t, color, sizeof color);
			-- t[i];
			if (t[i] >= 0)
				ans += cal(2) * n;
		}
	} else {
		for (int i = 1; i <= 3; i ++) {
			for (int j = 1; j <= 3; j ++) {
				memcpy(t, color, sizeof color);
				t[i] --; t[j] --;
				if (t[i] >= 0 && t[j] >= 0) {
					ans += cal(2) * (n / 2);
				}
			}
		}
		memcpy(t, color, sizeof color); 
		ans += cal(2) * (n / 2);
	}
	ans /= 2 * n;
	return ans;
}

int main()
{
	init();
	scanf("%d", &tc);
	while (tc --) {
		scanf("%d%d%d", &a, &b, &d);
		n = a + b + d;
		color[1] = a; color[2] = b; color[3] = d;
		printf("%lld\n", polya());
	}
	return 0;
}
