#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX = 2e7 + 10;

int cnt, vis[MAX], prime[MAX];
long long g[MAX];
int n;

void init()
{
	memset(vis, 0, sizeof vis);
	cnt = 0;
	g[1] = 1;
	for (int i = 2; i < MAX; i ++) {
		if (!vis[i]) {
			prime[cnt ++] = i;
			g[i] = 2;
		}
		for (int j = 0; j < cnt; j ++) {
			if (1LL * i * prime[j] >= MAX) break;
			vis[i * prime[j]] = 1;
			if (i % prime[j] == 0) {
				if (i / prime[j] % prime[j] == 0) {
                    g[i * prime[j]] = 0;
				} else {
                    g[i * prime[j]] = g[i / prime[j]];

				}
				break;
			} else {
				g[i * prime[j]] = 1LL * g[i] * g[prime[j]];
			}
		}
	}
	g[0] = 0;
	/*
	for (int i = 1; i <= 24; i ++) {
        printf("%d ", g[i]);
	}
	*/
	for (int i = 1; i < MAX; i ++) {
        g[i] += g[i - 1];
	}
}

int main()
{
    init();
    int t;
    scanf("%d", &t);
    while (t --) {
        scanf("%d", &n);
        printf("%lld\n", g[n]);
    }
    return 0;
}
