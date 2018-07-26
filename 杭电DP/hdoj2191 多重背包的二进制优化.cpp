//while(true) RP++;
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm> 
using namespace std;
const int MAX = 512;

int main()
{
	int t;
	scanf("%d", &t);
	int n,m;
	int p[MAX], w[MAX], num[MAX], dp[MAX];
	while (t --) {
		scanf("%d%d",&m,&n);
		int cnt = 0;
		for (int i = 1; i <= n; i ++) {
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			int j = 1;
			while (c >= j) {
				c -= j;
				p[++ cnt] = j * a;
				w[cnt] = j * b;
				 j <<= 1;
			}
			if (c) {
				p[ ++ cnt] = c * a;
				w[cnt] = c * b;
			}
		}
		
		memset(dp,0,sizeof(dp));
		for (int i = 1; i <= cnt; i ++) {
			for (int j = m; j >= p[i]; j --) {
				dp[j] = max(dp[j], dp[j - p[i]] + w[i]);
			}
		}
		printf("%d\n", dp[m]);
	}
	return 0;
}

