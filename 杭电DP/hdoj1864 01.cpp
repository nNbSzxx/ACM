#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAX = 35;

int main()
{
	int n;
	double q;
	int v[MAX];
	int dp[3000100];
	while (scanf("%lf%d",&q,&n), n) {
		int cnt = 1;
		int flag = 1;
		int amount = (q + 0.005) * 100;
		memset(dp, 0, sizeof(dp));
		for (int i = 1; i <= n; i ++) {
			int m;
			double a = 0, b = 0, c = 0;
			scanf("%d",&m);
			char s;
			double temp;
			for (int j = 1; j <= m; j ++) {
				scanf(" %c:%lf",&s, &temp);
				int price = (temp + 0.005) * 100;
				if (s == 'A') {
					a += price;
				} else
				if (s == 'B') {
					b += price;
				} else
				if (s == 'C') {
					c += price;	
				} else {
					flag = 0;
				}
				if (a > 60000 || b > 60000 || c > 60000 || a+b+c > 100000) {
					flag = 0;
				}
			}
			if (flag) {
				v[cnt ++] = a+b+c;
			} else {
				flag = 1;
			}
		}
		for (int i = 1; i < cnt; i ++) {
			for (int j = amount; j >= v[i]; j --) {
				if (dp[j] < dp[j - v[i]] + v[i]) {
					dp[j] = dp[j - v[i]] + v[i];
				}
			}	
		}
		printf("%.2f\n",1.0 * dp[amount] / 100);
	}
}
