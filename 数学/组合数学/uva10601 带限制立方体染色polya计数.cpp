#include <bits/stdc++.h>
using namespace std;
const int MAX = 15;
int color[MAX], t[MAX];
long long c[MAX][MAX];

void init()
{
	c[0][0] = 1;
	c[1][0] = 1; c[1][1] = 1;
	for (int i = 2; i <= 12; i ++) {
		c[i][0] = c[i][i] = 1;
		for (int j = 1; j < i; j ++) {
			c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
		}
	}
	return ;
}

// 循环节是 12/k , 也就是每k个颜色必须是相同的，也就是有k个循环节 
long long cal(int k)
{
	long long ret = 1;
	int n = 0;
	for (int i = 1; i <= 6; i ++) {
		if (t[i] % k == 0) {
			t[i] /= k;
			n += t[i]; 
		} else {
			return 0;
		}
	}
	for (int i = 1; i <= 6; i ++) {
		ret *= c[n][t[i]];
		n -= t[i];
	}
	return ret;
}

long long polya()
{
	long long ans = 0;
	// 恒等置换 1个 
	memcpy(t, color, sizeof color); 
	ans += cal(1);
	// 沿面的中心旋转 共3 * 3个
	memcpy(t, color, sizeof color); 
	ans += cal(4) * 2 * 3;
	memcpy(t, color, sizeof color);
	ans += cal(2) * 1 * 3;
	// 沿相对的棱的中点连线旋转 共 1 * 6个
	for (int i = 1; i <= 6; i ++) {
		for (int j = 1; j <= 6; j ++) {
			memcpy(t, color, sizeof color);
			-- t[i]; -- t[j];
			if (t[i] < 0 || t[j] < 0) {
				continue;
			}
			ans += 6 * cal(2);
		}
	}
	// 沿最远点对的连线旋转 共4 * 2个 
	memcpy(t, color, sizeof color);
	ans += cal(3) * 4 * 2; 
	return ans / 24;
}

int main()
{
	init();
	int t;
	scanf("%d", &t);
	while (t --) {
		memset(color, 0, sizeof color);
		int a;
		for (int i = 1; i <= 12; i ++) {
			scanf("%d", &a);
			color[a] ++;
		}
		printf("%lld\n", polya());
	}
	return 0;
}
