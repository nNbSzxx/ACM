#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
	int num[10];
	int val = 0;
	int tc = 1;
	int dp[420002];
	int p[200];
	int n;
	while (~scanf("%d",&num[1])) {
		val = num[1];
		int flag = 1;
		if (num[1]) flag = 0;
		n = 0;
		int j = 1;
		while (num[1] >= j) {
			num[1] -= j;
			p[++ n] = j * 1;
			j <<= 1;
		}
		if (num[1]) {
			p[++ n] = num[1] * 1;
		}
		memset(dp,0,sizeof(dp));
		for (int i = 2; i <= 6; i ++) {
			scanf("%d",&num[i]);
			if (num[i]) flag = 0;
			val += num[i] * i;
			int j = 1;
			while (num[i] >= j) {
				num[i] -= j;
				p[++ n] = j * i;
				j <<= 1;
			}
			if (num[i]) {
				p[++ n] = num[i] * i;
			}
		}
		if (flag) break;
		if (val & 1) {
			printf("Collection #%d:\nCan't be divided.\n\n",tc ++);
			continue;
		}
		val >>= 1;
		for (int i = 1; i <= n; i ++) {
			for (int j = val; j >= p[i]; j --) {
				dp[j] = max(dp[j], dp[j - p[i]] + p[i]);
			}
		}
		//printf("%d %d\n",val,dp[val]);
		if (dp[val] == val) {
			printf("Collection #%d:\nCan be divided.\n\n",tc ++);
		} else {
			printf("Collection #%d:\nCan't be divided.\n\n",tc ++);
		}
	}
	return 0;
}
