#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAX = 1e6 + 10;
int n, cnt = 0, prime[111111], vis[MAX];

void init()
{
	memset(vis, 0, sizeof vis);
	vis[1] = 1;
	for (int i = 2; i < MAX; i ++) {
		if (!vis[i]) {
			prime[cnt ++] = i;
			for (int j = 2 * i; j < MAX; j += i) {
				vis[j] = 1;
			}
		}
	}
}

int bfs(int x)
{
	int t = x, i = 0;
	int ret = x;
	int dep = 1, ans = INF;
	int maxprime = -1;
	
	while (vis[t] == 1 && t != 1) {	
		if (t % prime[i] == 0) {
			// int div = x / prime[i];
			//printf("%d %d\n", div, prime[i]);
			do {
				t /= prime[i];
			} while (t % prime[i] == 0);
			maxprime = max(maxprime, prime[i]);
		}
		++ i;
	}
	maxprime = max(maxprime, t);
	//printf("%d %d\n", maxprime, x);
	
	for (int j = (x / maxprime - 1) * maxprime + 1; j < x; j ++) {
		//printf("%d\n", *it);
		int m;
		m = t = j;
		i = 0;
		while (t != 1 && vis[t]) {
			if (t % prime[i] == 0) {
				int div = m / prime[i];
				do {
					t /= prime[i];
				} while (t % prime[i] == 0);
				//printf("%d %d\n", m, prime[i]);
//				if (div != 1) {
//					if (prime[i] * (div - 1) >= 3) 
//						ans = min(ans, prime[i] * (div - 1) + 1);
//				} else {
//					if (prime[i] >= 3) {
//						ans = min(ans, prime[i]);
//					}
//				}
				ans = min(ans, m - prime[i] + 1);
			}
			++ i;
		}
		if (!vis[t])
			if (t == m)
				ans = min(ans, t);
			else
				ans = min(ans, m - t + 1);
	}
	return ans;
}

int main()
{
	init();
	scanf("%d", &n);
	if (!vis[n]) {
		printf("%d\n", n);
	} else
		printf("%d\n", bfs(n)); 
	
	return 0;
}
